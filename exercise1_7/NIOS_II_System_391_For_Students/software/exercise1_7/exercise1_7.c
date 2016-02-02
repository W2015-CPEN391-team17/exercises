/*
 * Exercise 1.7
 */


#include <stdio.h>
#include "graphics.h"

void strobe() {
	int i = 0;
	while(1) {
		for(i = 0; i < YRES; i++) {
			WriteHLine(0, i, XRES, 2);
		}
		for(i = 0; i < XRES; i++) {
			 WriteVLine(i, 0, YRES, 5);
		}
	}
}

int main()
{
  printf("Exercise 1.7 start\n");

  int i = 0;
  for(i = 0; i < YRES; i++) {
	  WriteHLine(0, i, XRES/2, 1);
  }
  for(i = XRES/2; i < XRES; i++) {
	  WriteVLine(i, 0, YRES, 2);
  }


  //TODO test drawing h/v line with only one pixel (should not appear)
  //TODO test drawing h/v line with two pixels (should appear)
  //TODO handling h/v lines in wrong direction?

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

  VLine(200,200,100,5);
  VLine(201,200,100,5);
  VLine(202,200,100,5);
  VLine(203,200,100,5);
  VLine(204,200,100,5);
  WriteVLine(205,200,100,6);
  WriteVLine(206,200,100,6);
  WriteVLine(207,200,100,6);
  WriteVLine(208,200,100,6);
  WriteVLine(209,200,100,6);

  HLine(500,100,100,3);
  HLine(500,101,100,3);
  HLine(500,102,100,3);
  HLine(500,103,100,3);
  HLine(500,104,100,3);
  WriteHLine(500,105,100,4);
  WriteHLine(500,106,100,4);
  WriteHLine(500,107,100,4);
  WriteHLine(500,108,100,4);
  WriteHLine(500,109,100,4);

  VLine(500,200,100,5);
  VLine(501,200,100,5);
  VLine(502,200,100,5);
  VLine(503,200,100,5);
  VLine(504,200,100,5);
  WriteVLine(505,200,100,6);
  WriteVLine(506,200,100,6);
  WriteVLine(507,200,100,6);
  WriteVLine(508,200,100,6);
  WriteVLine(509,200,100,6);

  printf("Exercise 1.7 end\n");


  return 0;
}
