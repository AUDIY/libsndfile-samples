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
