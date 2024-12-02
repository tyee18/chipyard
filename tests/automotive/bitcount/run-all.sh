#!/usr/bin/env bash

make clean
make

timestamp=$(date +%Y_%m_%d_%H%M%S)

if [ "$MIBENCH_FAST" = true ] ; then
    ${MIBENCH_RUN} bitcnts 75000 > $RTLCONFIG_NAME'_'$timestamp'_bitcnts_output_small.txt'

else
    ${MIBENCH_RUN} bitcnts 1125000 > $RTLCONFIG_NAME'_'$timestamp'_bitcnts_output_large.txt'
fi
