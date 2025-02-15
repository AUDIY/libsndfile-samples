/* sample25_setchunk.c */

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
#include <stdlib.h>
#include <string.h>
#include <sndfile.h>
#include <math.h>

int main(void) {

    SF_INFO   sfinfoR;
    SNDFILE  *sndfileR;
    short    *ptrR;
    short    *headR;
    long int  items;

    SF_INFO  sfinfoW;
    SNDFILE *sndfileW;

    int err;
    SF_CHUNK_INFO chunkinfo;
    const char *testdata = "The quick brown fox jumped over the lazy dogs.";

    /* Input filename here */
    char *filenameR = "./TestSound_44100_16.wav"; 
    char *filenameW = "./Output.wav";
    
    /* Fill 0 the SF_INFO struct */
    memset(&sfinfoR, 0, sizeof(sfinfoR));
    memset(&sfinfoW, 0, sizeof(sfinfoW));

    /* Open audio file & read data */
    sndfileR = sf_open(filenameR, SFM_READ, &sfinfoR);
    items    = sfinfoR.frames * sfinfoR.channels;
    ptrR     = (short *)calloc(items, sizeof(short));
    headR    = ptrR;
    sf_read_short(sndfileR, ptrR, items);

    /* Copy audio properties */
    sfinfoW.samplerate = sfinfoR.samplerate;
    sfinfoW.channels   = sfinfoR.channels;
    sfinfoW.format     = sfinfoR.format;

    /* Open audio file */
    sndfileW = sf_open(filenameW, SFM_WRITE, &sfinfoW);

    /* Generate original "Test" chunk */
    memset(&chunkinfo, 0, sizeof(chunkinfo));
    snprintf(chunkinfo.id, sizeof (chunkinfo.id), "Test") ;
	chunkinfo.id_size = 4 ;
	chunkinfo.data    = strdup(testdata) ;
	chunkinfo.datalen = strlen(chunkinfo.data) ;

    /* Add "Test" chunk & write audio data. */
    err = sf_set_chunk (sndfileW, &chunkinfo) ;
    printf("Error status: %s\n", sf_error_number(err));
    ptrR = headR;
    sf_write_short(sndfileW, ptrR, items);

    /* Close the audio file */
    /* 
        Every call to sf_open() should be matched with a call to sf_close() to free up
        memory allocated during the call to sf_open().
    */
    sf_close(sndfileR);
    sf_close(sndfileW);

    ptrR = headR;
    free(ptrR);

    return 0;
}
