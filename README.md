# libsndfile-samples
[![libsndfile-samples compile test](https://github.com/AUDIY/libsndfile-samples/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/AUDIY/libsndfile-samples/actions/workflows/c-cpp.yml)  
Samples for reading &amp; writing audio data which use [libsndfile](https://github.com/libsndfile/libsndfile).

## Sample lists
|No.|File name|Description|Scope function|
|:-:|:--------|:----------|:-------------|
| 1 |sample01_readinfo.c|Print sfinfo members from sound file.|SNDFILE* sf_open(const char *path, int mode, SF_INFO *sfinfo);|
| 2 |sample02_formatcheck.c|Check sf_format_check() function.|int sf_format_check(const SF_INFO *info);|
| 3 |sample03_seek.c|Print the amplitude of seeked data.|sf_count_t sf_seek(SNDFILE *sndfile, sf_count_t frames, int whence);|
| 4 |sample04_errorcheck.c|Check whether sndfile struct is valid on NOT.|int sf_error(SNDFILE *sndfile);|
