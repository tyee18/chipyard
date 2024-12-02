#!/usr/bin/env bash

make clean
make

timestamp=$(date +%Y_%m_%d_%H%M%S)

if [ "$MIBENCH_FAST" = true ] ; then
    ${MIBENCH_RUN} ./qsort_small input_small.dat > $RTLCONFIG_NAME'_'$timestamp'_qsort_output_small.txt'

else
    ${MIBENCH_RUN} ./qsort_large input_large.dat > $RTLCONFIG_NAME'_'$timestamp'_qsort_output_large.txt'
fi
