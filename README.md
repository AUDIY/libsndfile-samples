# libsndfile-samples
[![libsndfile-samples compile test](https://github.com/AUDIY/libsndfile-samples/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/AUDIY/libsndfile-samples/actions/workflows/c-cpp.yml)  
Samples for reading &amp; writing audio data which use [libsndfile](https://github.com/libsndfile/libsndfile).

## Overview
This is the samples which use [libsndfile](https://github.com/libsndfile/libsndfile).  
These samples are used basic functions in the [libsndfile programming interface](http://libsndfile.github.io/libsndfile/api.html).  
I wish it makes the programmer understood how to use libsndfile.  
Issues, Pull requests, Stars and Forks are welcome!  

## Sample lists
libsndfile programming interface is described in [this link](http://libsndfile.github.io/libsndfile/api.html).
|No.|File name|Description|Scope function|
|:--:|:--------|:----------|:-------------|
|  1 |sample01_readinfo.c|Print sfinfo members from sound file.|SNDFILE* sf_open(const char *path, int mode, SF_INFO *sfinfo);|
|  2 |sample02_formatcheck.c|Check sf_format_check() function.|int sf_format_check(const SF_INFO *info);|
|  3 |sample03_seek.c|Print the amplitude of seeked data.|sf_count_t sf_seek(SNDFILE *sndfile, sf_count_t frames, int whence);|
|  4 |sample04_errorcheck.c|Check whether sndfile struct is valid or NOT.|int sf_error(SNDFILE *sndfile);|
|  5 |sample05_readshort.c|Read the audio data as short data type.|sf_count_t sf_read_short(SNDFILE *sndfile, short *ptr, sf_count_t items);|
|  6 |sample06_readfshort.c|Read the audio data as short data type.|sf_count_t sf_readf_short(SNDFILE *sndfile, short *ptr, sf_count_t frames);|
|  7 |sample07_readint.c|Read the audio data as int data type.|sf_count_t sf_read_int(SNDFILE *sndfile, int *ptr, sf_count_t items);|
|  8 |sample08_readfint.c|Read the audio data as int data type.|sf_count_t sf_readf_int(SNDFILE *sndfile, int *ptr, sf_count_t frames);|
|  9 |sample09_readfloat.c|Read the audio data as float data type.|sf_count_t sf_read_float(SNDFILE *sndfile, float *ptr, sf_count_t items);|
| 10 |sample10_readffloat.c|Read the audio data as float data type.|sf_count_t sf_readf_float(SNDFILE *sndfile, float *ptr, sf_count_t frames);|
| 11 |sample11_readdouble.c|Read the audio data as double data type.|sf_count_t sf_read_double(SNDFILE *sndfile, double *ptr, sf_count_t items);|
| 12 |sample12_readfdouble.c|Read the audio data as double data type.|sf_count_t sf_readf_double(SNDFILE *sndfile, double *ptr, sf_count_t frames);|
| 13 |sample13_writeshort.c|Write audio data from short data type.|sf_count_t sf_write_short(SNDFILE *sndfile, short *ptr, sf_count_t items);|
| 14 |sample14_writefshort.c|Write audio data from short data type.|sf_count_t sf_writef_short(SNDFILE *sndfile, short *ptr, sf_count_t frames);|
| 15 |sample15_writeint.c|Write audio data from int data type.|sf_count_t sf_write_int(SNDFILE *sndfile, int *ptr, sf_count_t items);|
| 16 |sample16_writefint.c|Write audio data from int data type.|sf_count_t sf_writef_int(SNDFILE *sndfile, int *ptr, sf_count_t frames);|
| 17 |sample17_writefloat.c|Write audio data from float data type.|sf_count_t sf_write_float(SNDFILE *sndfile, float *ptr, sf_count_t items);|
| 18 |sample18_writeffloat.c|Write audio data from float data type.|sf_count_t sf_writef_float(SNDFILE *sndfile, float *ptr, sf_count_t frames);|
| 19 |sample19_writedouble.c|Write audio data from double data type.|sf_count_t sf_write_double(SNDFILE *sndfile, double *ptr, sf_count_t items);|
| 20 |sample20_writefdouble.c|Write audio data from double data type.|sf_count_t sf_writef_double(SNDFILE *sndfile, double *ptr, sf_count_t frames);|
| 21 |sample21_setstring.c|Add basic string metadata to the written audio file.|int sf_set_string(SNDFILE *sndfile, int str_type, const char *str);|
| 22 |sample22_getstring.c|Get basic string metadata to the written audio file.|const char* sf_get_string(SNDFILE *sndfile, int str_type);|
| 23 |sample23_versionstring.c|Get libsndfile version string.|const char *sf_version_string(void);|
| 24 |sample24_byterate.c|Return the current byterate at this point in the file.|int sf_current_byterate(SNDFILE *sndfile);|
| 25 |sample25_setchunk.c|Set the specified chunk info.|int sf_set_chunk(SNDFILE *sndfile, const SF_CHUNK_INFO *chunk_info);|
| 26 |sample26_getchunkiterator.c|Get an iterator for all chunks matching chunk_info.|SF_CHUNK_ITERATOR *sf_get_chunk_iterator(SNDFILE *sndfile, const SF_CHUNK_INFO *chunk_info);|
| 27 |sample27_getchunksize.c|Get the size of the specified chunk.|int sf_get_chunk_size(const SF_CHUNK_ITERATOR *it, SF_CHUNK_INFO *chunk_info);|
| 28 |sample28_getchunkdata.c|Get the specified chunk data.|int sf_get_chunk_data(const SF_CHUNK_ITERATOR *it, SF_CHUNK_INFO *chunk_info);|
| 29 |sample29_nextchunkiterator.c|Iterate through chunks by incrementing the iterator.|SF_CHUNK_ITERATOR *sf_next_chunk_iterator (SF_CHUNK_ITERATOR *iterator);|
