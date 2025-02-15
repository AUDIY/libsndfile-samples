/* sample04_errorcheck.c */

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

    SF_INFO sfinfo;
    SNDFILE *sndfile;

    /* Input filename here */
    char *filename = "./TestSound_44100_16.wav";

    /* Fill 0 the SF_INFO struct */
    memset(&sfinfo, 0, sizeof(sfinfo));

    /* Open audio file & get SF_INFO value */
    sndfile = sf_open(filename, SFM_READ, &sfinfo);

    /* Print error */
    printf("|===== sndfile error check. =====|\n");
    printf("1. sf_error()       : %d\n", sf_error(sndfile)); // Error number

    printf("2. sf_error_number(): ");
    puts(sf_error_number(sf_error(sndfile))); // Error type from error number
    
    printf("3. sf_strerror()    : ");
    puts(sf_strerror(sndfile)); // Error type from sndfile

    /* Close the audio file */
    sf_close(sndfile);

    return 0;
}