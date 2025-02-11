/* sample21_setstring.c */

/*
** Copyright (C) 2025 AUDIY.
**
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in
**       the documentation and/or other materials provided with the
**       distribution.
**     * Neither the author nor the names of any contributors may be used
**       to endorse or promote products derived from this software without
**       specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
** PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
** CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
** OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
** OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
** ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <sndfile.h>

int main(void) {

    /* SF_INFO & SNDFILE for written audiofile */
    SF_INFO  sfinfoW ;
    SNDFILE *sndfileW;

    /* SF_INFO & SNDFILE for read audiofile */
    SF_INFO  sfinfoR ;
    SNDFILE *sndfileR;

    int      seconds ; // Playing time [s]
    int      freq    ; // Play frequency [Hz]
    sf_count_t frames;
    long int items   ; // frames * channels
    double   *ptr    ; // Double type data array 
    double   *headptr; // Head pointer of *ptr

    /* Output filename here */
    char *filename = "./Output.flac";

    /* Initialize sfinfos */
    memset(&sfinfoW, 0, sizeof(sfinfoW));
    memset(&sfinfoR, 0, sizeof(sfinfoR));

    seconds = 5; // seconds
    freq = 1000; // Hz

    sfinfoW.samplerate = 96000;                            // Sampling frequency (necessary)
    sfinfoW.channels   = 2;                                // Channels (necessary)
    sfinfoW.format     = SF_FORMAT_FLAC | SF_FORMAT_PCM_24; // Format (necessary)
    
    frames = sfinfoW.samplerate * seconds + 1;
    items  = frames * sfinfoW.channels;

    /* Initialize the *ptr array */
    ptr = (double *)calloc(items, sizeof(double));
    headptr = ptr;

    /* Generate the data array */
    for (long int i = 0; i < frames; i++) {
        if (sfinfoW.channels == 1) {
            // Mono: Sine wave
            *ptr = (sin(2 * M_PI * ((double)i/sfinfoW.samplerate) * freq));
            ptr++;
        } else if (sfinfoW.channels == 2) {
            // Left channel: Sine wave
            *ptr = (sin(2 * M_PI * ((double)i/sfinfoW.samplerate) * freq));
            ptr++;

            // Right channel: Cosine wave
            *ptr = (cos(2 * M_PI * ((double)i/sfinfoW.samplerate) * freq));
            ptr++;
        }
    }

    /* Put the ptr pointer to the head */
    ptr = headptr;

    /* Open the written audio file */
    sndfileW = sf_open(filename, SFM_WRITE, &sfinfoW);

    /* Scope function in this sample: sf_set_string() */
    /*
        Note:
            Strings passed to and retrieved from these two functions are assumed to be utf-8.
            However, while formats like Ogg/Vorbis and FLAC fully support utf-8, others like WAV 
            and AIFF officially only support ASCII.
            Writing utf-8 strings to WAV and AIF files with libsndfile will work when read back with 
            libsndfile, but may not work with other programs.
            
            The suggested method of dealing with tags retrieved using sf_get_string() is to assume 
            they are utf-8. 
            Similarly if you have a string in some exotic format like utf-16, it should be encoded 
            to utf-8 before being written using libsndfile.
    */
    sf_set_string(sndfileW, SF_STR_TITLE, "Your output title.");
    sf_set_string(sndfileW, SF_STR_COPYRIGHT, "Copyright (C) 2025 AUDIY");
    sf_set_string(sndfileW, SF_STR_SOFTWARE, "libsndfile-samples");
    sf_set_string(sndfileW, SF_STR_ARTIST, "AUDIY");
    sf_set_string(sndfileW, SF_STR_COMMENT, "Licensed under LGPL-2.1");
    sf_set_string(sndfileW, SF_STR_DATE, "2025-01-01");
    sf_set_string(sndfileW, SF_STR_ALBUM, "Your album name.");
    sf_set_string(sndfileW, SF_STR_LICENSE, "LGPL-2.1");
    sf_set_string(sndfileW, SF_STR_TRACKNUMBER, "XX");
    sf_set_string(sndfileW, SF_STR_GENRE, "TESTTRACK");

    sf_writef_double(sndfileW, ptr, frames); // Write the data array to the sndfileW
    sf_close(sndfileW); // Save & close the sndfileW
    free(ptr); // Free *ptr array

    /* Open the read audio file */
    sndfileR = sf_open(filename, SFM_READ, &sfinfoR);

    /* Show the SF_INFO value (If you need to display) */
    /*
    printf("===== Audio File Specifications =====\n");
    printf("Frames     : %ld\n", sfinfoR.frames);    // Frames (Used to be called samples.)
    printf("Sample rate: %d\n", sfinfoR.samplerate); // Sample rate
    printf("Channels   : %d\n", sfinfoR.channels);   // The number of channels.
    printf("Format     : 0x%x\n", sfinfoR.format);   // Audio file format by hexadecimal.
    printf("Sections   : %d\n", sfinfoR.sections);   // Sections
    printf("Seekable   : %d\n", sfinfoR.seekable);   // Seekable
    printf("\n");
    */

    /* Audio File Metadata (If you need to display) */
    /*
    printf("========== Audio File Metadata ==========\n");
    printf("TITLE      : %s\n", sf_get_string(sndfileR, SF_STR_TITLE));
    printf("COPYRIGHT  : %s\n", sf_get_string(sndfileR, SF_STR_COPYRIGHT));
    printf("SOFTWARE   : %s\n", sf_get_string(sndfileR, SF_STR_SOFTWARE));
    printf("ARTIST     : %s\n", sf_get_string(sndfileR, SF_STR_ARTIST));
    printf("COMMENT    : %s\n", sf_get_string(sndfileR, SF_STR_COMMENT));
    printf("DATE       : %s\n", sf_get_string(sndfileR, SF_STR_DATE));
    printf("ALBUM      : %s\n", sf_get_string(sndfileR, SF_STR_ALBUM));
    printf("LICENSE    : %s\n", sf_get_string(sndfileR, SF_STR_LICENSE));
    printf("TRACKNUMBER: %s\n", sf_get_string(sndfileR, SF_STR_TRACKNUMBER));
    printf("GENRE      : %s\n", sf_get_string(sndfileR, SF_STR_GENRE));
    */

    sf_close(sndfileR); // Close the audio file to read

    return 0;
}