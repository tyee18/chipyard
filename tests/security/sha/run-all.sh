#!/usr/bin/env bash

make clean
make

timestamp=$(date +%Y_%m_%d_%H%M%S)

if [ "$MIBENCH_FAST" = true ] ; then
    ${MIBENCH_RUN} sha input_small.asc > $RTLCONFIG_NAME'_'$timestamp'_sha_output_small.txt'
else
    ${MIBENCH_RUN} sha input_large.asc > $RTLCONFIG_NAME'_'$timestamp'_sha_output_large.txt'
fi
