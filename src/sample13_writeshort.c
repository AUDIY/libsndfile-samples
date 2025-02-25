/* sample13_writeshort.c */

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

    int       seconds ; // Playing time [s]
    int       freq    ; // Play frequency [Hz]
    sf_count_t frames;
    long  int items   ; // frames * channels
    short     *ptr    ; // Short type data array 
    short     *headptr; // Head pointer of *ptr

    /* Output filename here */
    char *filename = "./Output.wav";

    /* Initialize sfinfos */
    memset(&sfinfoW, 0, sizeof(sfinfoW));
    memset(&sfinfoR, 0, sizeof(sfinfoR));

    seconds = 5; // seconds
    freq = 1000; // Hz

    sfinfoW.samplerate = 44100;                            // Sampling frequency (necessary)
    sfinfoW.channels   = 2;                                // Channels (necessary)
    sfinfoW.format     = SF_FORMAT_WAV | SF_FORMAT_PCM_16; // 16bit WAV (necessary)
    
    frames = sfinfoW.samplerate * seconds + 1;
    items  = frames * sfinfoW.channels;

    /* Initialize the *ptr array */
    ptr = (short *)calloc(items, sizeof(short));
    headptr = ptr;

    /* Generate the data array */
    for (long int i = 0; i < frames; i++) {
        if (sfinfoW.channels == 1) {
            // Mono: Sine wave
            *ptr = (short)(SHRT_MAX * sin(2 * M_PI * ((double)i/sfinfoW.samplerate) * freq));
            ptr++;
        } else if (sfinfoW.channels == 2) {
            // Left channel: Sine wave
            *ptr = (short)(SHRT_MAX * sin(2 * M_PI * ((double)i/sfinfoW.samplerate) * freq));
            ptr++;

            // Right channel: Cosine wave
            *ptr = (short)(SHRT_MAX * cos(2 * M_PI * ((double)i/sfinfoW.samplerate) * freq));
            ptr++;
        }
    }

    /* Put the ptr pointer to the head */
    ptr = headptr;

    /* Open the written audio file */
    sndfileW = sf_open(filename, SFM_WRITE, &sfinfoW);
    sf_write_short(sndfileW, ptr, items); // Write the data array to the sndfileW
    sf_close(sndfileW); // Save & close the sndfileW
    free(ptr); // Free *ptr array

    /* Open the read audio file */
    sndfileR = sf_open(filename, SFM_READ, &sfinfoR);

    /* Show the SF_INFO value */
    printf("Audio File Specifications\n");
    printf("Frames     : %ld\n", sfinfoR.frames);    // Frames (Used to be called samples.)
    printf("Sample rate: %d\n", sfinfoR.samplerate); // Sample rate
    printf("Channels   : %d\n", sfinfoR.channels);   // The number of channels.
    printf("Format     : 0x%x\n", sfinfoR.format);   // Audio file format by hexadecimal.
    printf("Sections   : %d\n", sfinfoR.sections);   // Sections
    printf("Seekable   : %d\n", sfinfoR.seekable);   // Seekable
    
    /* Initialize the *ptr array */
    ptr = (short *)calloc(items, sizeof(short));
    headptr = ptr;

    /* Read the audio data by short type */
    sf_read_short(sndfileR, ptr, items);

    /* Print the data */
    for (long int i = 0; i < sfinfoR.frames; i++) {
        if (sfinfoR.channels == 1) {
            /* Monoaural Data */
            printf("Mono[%ld]: \t%6d\n", i, *ptr);
            ptr++;
        } else if (sfinfoR.channels == 2) {
            /* Stereo Data */
            printf("Left[%ld]: \t%6d ", i, *ptr);
            ptr++;
            printf("\tRight[%ld]: \t%6d\n", i, *ptr);
            ptr++;
        }
    }
    
    ptr = headptr;      // Put the ptr pointer to the head
    free(ptr);          // Free *ptr array
    sf_close(sndfileR); // Close the audio file to read

    return 0;
}