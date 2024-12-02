/* NIST Secure Hash Algorithm */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sha.h"
#include "../../timers/timers.h"

int main(int argc, char **argv)
{
    FILE *fin;
    SHA_INFO sha_info;

    if (argc < 2) {
	fin = stdin;
	sha_stream(&sha_info, fin);
	sha_print(&sha_info);
    } else {
	while (--argc) {
	    fin = fopen(*(++argv), "rb");
	    if (fin == NULL) {
		printf("error opening %s for reading\n", *argv);
	    } else {
	  	// Initialize counters for analysis
	  	Timer t;
	  	t = update_start_timers(t);
		sha_stream(&sha_info, fin);
		sha_print(&sha_info);
	
	  	// Read counters after execution, and print timing data
	  	t = update_stop_timers(t);
	  	print_timing_data(t);
		fclose(fin);
	    }
	}
    }
    return(0);
}
