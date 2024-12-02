#!/usr/bin/env bash

make clean
make

timestamp=$(date +%Y_%m_%d_%H%M%S)

if [ "$MIBENCH_FAST" = true ] ; then
    ${MIBENCH_RUN} crc ../adpcm/data/small.pcm > $RTLCONFIG_NAME'_'$timestamp'_crc32_output_small.adpcm'
    #${MIBENCH_RUN} ../bin/rawdaudio < ../data/small.adpcm > ../output_small.pcm

else
    ${MIBENCH_RUN} crc ../adpcm/data/large.pcm > $RTLCONFIG_NAME'_'$timestamp'_crc32_output_large.adpcm'
    #${MIBENCH_RUN} ../bin/rawdaudio < ../data/large.adpcm > ../output_large.pcm

fi
