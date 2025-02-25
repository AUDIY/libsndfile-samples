/* sample10_readffloat.c */

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
#include <sndfile.h>

int main(void) {

    SF_INFO  sfinfo ;
    SNDFILE *sndfile;

    long  int items = 0;
    float     *ptr     ;
    float     *headptr ;

    /* Input filename here */
    char *filename = "./TestSound_44100_16.wav";

    /* Open audio file & get SF_INFO value */
    sndfile = sf_open(filename, SFM_READ, &sfinfo);

    /* Calcurate items */
    items = sfinfo.frames * sfinfo.channels;

    /* Allocate & initialize the *ptr array */
    ptr = (float *)calloc(items, sizeof(float));
    headptr = ptr; // Store the head pointer

    /* Read the audio data by float type */
    sf_readf_float(sndfile, ptr, sfinfo.frames);

    /* Print the data */
    for (long int i = 0; i < sfinfo.frames; i++) {
        if (sfinfo.channels == 1) {
            /* Monoaural Data */
            printf("Mono[%ld]: \t%f\n", i, *ptr);
            ptr++;
        } else if (sfinfo.channels == 2) {
            /* Stereo Data */
            printf("Left[%ld]: \t%f ", i, *ptr);
            ptr++;
            printf("\tRight[%ld]: \t%f\n", i, *ptr);
            ptr++;
        }
    }
    

    /* Put the ptr pointer to the head */
    ptr = headptr;

    /* Free *ptr array */
    free(ptr);

    /* Close the audio file */
    sf_close(sndfile);

    return 0;
}