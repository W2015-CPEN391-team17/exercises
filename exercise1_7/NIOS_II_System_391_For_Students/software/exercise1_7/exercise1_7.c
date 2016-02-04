/*
 * Exercise 1.7
 */

#include <stdio.h>
#include "graphics.h"

void speed_comparison() {
	int i = 0;
	int colour = 0;
	while(1) {
		colour = (colour + 1) % 8;
		for(i = 0; i < XRES; i++) {
			VLine(i, 0, YRES, 2);
		}
		colour = (colour + 1) % 8;
		for(i = 0; i < YRES/3; i++) {
			WriteHLine(0, i, XRES, colour);
		}
		colour = (colour + 1) % 8;
		for(i = YRES/3; i < 2*YRES/3; i++) {
			WriteHLine(0, i, XRES, colour);
		}
		colour = (colour + 1) % 8;
		for(i = 2*YRES/3; i < YRES; i++) {
			WriteHLine(0, i, XRES, colour);
		}
	}

	colour = (colour + 1) % 8;
	for(i = 0; i < YRES; i++) {
		Line(0, i, XRES, YRES, colour);
	}

	colour = (colour + 1) % 8;
	for(i = 0; i < YRES; i++) {
		WriteLine(0, i, XRES, YRES, colour);
	}
}

int main() {

  printf("Exercise 1.7 start\n");
  int i;
  //first fill the entire screen with black
  for(i = 1; i <= YRES; i++) {
	  WriteHLine(1, i, XRES, BLACK);
  }
  // fill the left half of the screen in white
  // and the right half of the screen in red
  for(i = 1; i <= YRES; i++) {
	  WriteHLine(1, i, XRES/2, WHITE);
  }
  for(i = 1; i <= YRES; i++) {
	  WriteHLine(XRES/2, i, XRES/2, RED);
  }

  //compare one-pixel-at-a-time with hardware-accelerated lines
  //each pair of lines should have the same length

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

  // compare bresenham lines
  // should see a black line on top
  // and a purple line a few pixels below it
  // otherwise the hardware-accelerated line doesn't perfectly match
  Line(240,340,440,440,0);
  Line(239,339,439,439,0);
  WriteLine(240,340,440,440,0);
  WriteLine(239,339,439,439,0);
  Line(250,350,450,450,0);
  Line(249,349,449,449,0);
  WriteLine(250,350,450,450,7);
  WriteLine(249,349,449,449,7);

  printf("Exercise 1.7 end\n");

  return 0;
}
