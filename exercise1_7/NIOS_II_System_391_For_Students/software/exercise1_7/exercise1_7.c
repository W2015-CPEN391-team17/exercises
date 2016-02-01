/*
 * Exercise 1.7
 */


#include <stdio.h>
#include "graphics.h"

int main()
{
  printf("Exercise 1.7 start\n");

  int i = 0;
  while(1) {
	  for(i = 0; i < YRES; i++) {
	    WriteHLine(0, i, XRES, 6);
	  }

	  Line(0, 0, XRES-250, YRES-250, 2);
	  Line(0, 0, XRES-200, YRES-200, 2);
	  Line(0, 0, XRES-150, YRES-150, 2);
	  Line(0, 0, XRES-100, YRES-100, 2);
	  Line(0, 0, XRES-50, YRES-50, 2);
	  Line(0, 0, XRES, YRES, 2);

	  for(i = 0; i < XRES; i++) {
	    VLine(i, 0, YRES, 7);
	    printf("hi\n");
	  }
  }

  printf("Exercise 1.7 end\n");


  return 0;
}
