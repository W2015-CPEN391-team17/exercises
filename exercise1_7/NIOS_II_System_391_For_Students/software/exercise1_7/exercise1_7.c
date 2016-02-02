/*
 * Exercise 1.7
 */


#include <stdio.h>
#include "graphics.h"

int main()
{
  printf("Exercise 1.7 start\n");

/*
  int i = 0;
  while(1) {
	  for(i = 0; i < YRES; i++) {
		  WriteHLine(0, i, XRES, 2);
	  }
	  for(i = 0; i < XRES; i++) {
		  WriteVLine(i, 0, YRES, 5);
	  }
  }
*/

  int i = 0;
  for(i = 0; i < YRES; i++) {
	  WriteHLine(0, i, XRES, 2);
  }

  HLine(100,100,100,3);
  HLine(100,101,100,3);
  HLine(100,102,100,3);
  HLine(100,103,100,3);
  HLine(100,104,100,3);
  WriteHLine(100,105,100,4);
  WriteHLine(100,106,100,4);
  WriteHLine(100,107,100,4);
  WriteHLine(100,108,100,4);
  WriteHLine(100,109,100,4);

  VLine(200,200,100,3);
  VLine(201,200,100,3);
  VLine(202,200,100,3);
  VLine(203,200,100,3);
  VLine(204,200,100,3);
  WriteVLine(205,200,100,4);
  WriteVLine(206,200,100,4);
  WriteVLine(207,200,100,4);
  WriteVLine(208,200,100,4);
  WriteVLine(209,200,100,4);

  printf("Exercise 1.7 end\n");


  return 0;
}
