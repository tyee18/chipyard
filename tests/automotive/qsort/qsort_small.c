#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../timers/timers.h"

#define UNLIMIT
#define MAXARRAY 60000 /* this number, if too large, will cause a seg. fault!! */

struct myStringStruct {
  char qstring[128];
};

int compare(const void *elem1, const void *elem2)
{
  int result;
  
  result = strcmp((*((struct myStringStruct *)elem1)).qstring, (*((struct myStringStruct *)elem2)).qstring);

  return (result < 0) ? 1 : ((result == 0) ? 0 : -1);
}


int
main(int argc, char *argv[]) {
  struct myStringStruct array[MAXARRAY];
  FILE *fp;
  int i,count=0;
  
  if (argc<2) {
    fprintf(stderr,"Usage: qsort_small <file>\n");
    exit(-1);
  }
  else {
    fp = fopen(argv[1],"r");
    
    while((fscanf(fp, "%s", &array[count].qstring) == 1) && (count < MAXARRAY)) {
	 count++;
    }
  }
  printf("\nSorting %d elements.\n\n",count);

	// Initialize counters for analysis
	Timer t;
	t = update_start_timers(t);

  qsort(array,count,sizeof(struct myStringStruct),compare);
  
	// Read counters after execution, and print timing data
	t = update_stop_timers(t);
	print_timing_data(t);

  for(i=0;i<count;i++)
    printf("%s\n", array[i].qstring);
  return 0;
}
