/* sample01_readinfo.c */

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

    /* Show the SF_INFO value */
    printf("Audio File Specifications\n");
    printf("Frames     : %ld\n", sfinfo.frames);    // Frames (Used to be called samples.)
    printf("Sample rate: %d\n", sfinfo.samplerate); // Sample rate
    printf("Channels   : %d\n", sfinfo.channels);   // The number of channels.
    printf("Format     : 0x%x\n", sfinfo.format);   // Audio file format by hexadecimal.
    printf("Sections   : %d\n", sfinfo.sections);   // Sections
    printf("Seekable   : %d\n", sfinfo.seekable);   // Seekable

    /* Close the audio file */
    /* 
        Every call to sf_open() should be matched with a call to sf_close() to free up
        memory allocated during the call to sf_open().
    */
    sf_close(sndfile);

    return 0;
}
