/* sample03_seek.c */

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
#include <sndfile.h>

int main(void) {
    
    SF_INFO sfinfo1;
    SNDFILE *sndfile1;

    SF_INFO sfinfo2;
    SNDFILE *sndfile2;

    short data1[2] = {0, 0};
    short data2[2] = {0, 0};

    /* Input filename here */
    char *filename1 = "./TestSound_44100_16.wav";
    char *filename2 = "./TestSound_44100_16_2.wav";

    /* Fill 0 the SF_INFO struct */
    memset(&sfinfo1, 0, sizeof(sfinfo1));
    memset(&sfinfo2, 0, sizeof(sfinfo2));

    /* Open audio file & get SF_INFO value */
    sndfile1 = sf_open(filename1, SFM_READ, &sfinfo1);
    sndfile2 = sf_open(filename2, SFM_READ, &sfinfo2);

    for (int i = 0; i < 5; i++) {
        /* Read current data */
        sf_read_short(sndfile1, data1, 2);
        sf_read_short(sndfile2, data2, 2);

        /* Print data */
        printf("sndfile1 = %d, sndfile2 = %d\n", data1[0], data2[0]);

        /* Seek the current pointer of sndfile2 */
        sf_seek(sndfile2, 1, SEEK_CUR); // Seek from current pointer
        //sf_seek(sndfile2, 2*(i+1), SEEK_SET); // Seek from Head pointer
    }

    /* Close the audio file */
    sf_close(sndfile1);
    sf_close(sndfile2);

    return 0;
}