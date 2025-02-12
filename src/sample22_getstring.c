/* sample22_getstring.c */

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

    /* SF_INFO & SNDFILE for read audiofile */
    SF_INFO  sfinfoR ;
    SNDFILE *sndfileR;

    /* Output filename here */
    char *filename = "./Getstring.flac";

    /* Initialize sfinfos */
    memset(&sfinfoR, 0, sizeof(sfinfoR));

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

    /* Scope function in this sample: sf_get_string() */
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

    sf_close(sndfileR); // Close the audio file to read

    return 0;
}