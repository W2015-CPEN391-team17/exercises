
#include "sys/alt_alarm.h"

#define ARRAY_SIZE 100

int main()
{

 // alt_printf("Hello World!");

  int a[ARRAY_SIZE][ARRAY_SIZE];
  int b[ARRAY_SIZE][ARRAY_SIZE];
  int c[ARRAY_SIZE][ARRAY_SIZE];
  int start_time;
  int end_time;
  int sum;
  int i, j, k;
  int ticks_per_sec = alt_ticks_per_second();

  for(i=0; i<ARRAY_SIZE; i++) {
	  for(j=0; j<ARRAY_SIZE; j++) {
		  a[i][j] = i*ARRAY_SIZE + j;
		  b[i][j] = i*ARRAY_SIZE + j;
	  }
  }

  start_time = alt_nticks();

  for(i=0; i<ARRAY_SIZE; i++) {
  	  for(j=0; j<ARRAY_SIZE; j++) {
  		  sum = 0;
  		  for(k=0; k<ARRAY_SIZE; k++) {
  			  sum = sum + a[i][k]*b[k][j];
  		  }
  		  c[i][j] = sum;
  	  }
  }

  end_time = alt_nticks();

  printf("time taken: %d clock ticks\n", end_time-start_time);
  printf("            %f seconds\n", (float)(end_time-start_time)/
		  	  	  	  	  	  	  	 (float)alt_ticks_per_second());
  return 0;
}
