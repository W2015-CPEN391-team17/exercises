/*
 * Exercise 1.7
 */

#include <stdio.h>
#include "graphics.h"

void black_screen() {
	// write black lines over the entire screen area
	//first fill the entire screen with black
	int i;
	for(i = 1; i <= YRES; i++) {
		WriteHLine(1, i, XRES, BLACK);
	}
}

void white_red_screen() {
	// fill the left half of the screen in white
	// and the right half of the screen in red
	int i;
	for(i = 1; i <= YRES; i++) {
		WriteHLine(1, i, XRES/2, WHITE);
	}
	for(i = 1; i <= YRES; i++) {
		WriteHLine(XRES/2, i, XRES/2, RED);
	}
}

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

void line_comparison() {
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

	  WriteLine(240,340,440,440,7);
	  WriteLine(239,339,439,439,7);
	  Line(240,340,440,440,0);
	  Line(239,339,439,439,0);

	  Line(250,350,450,450,0);
	  Line(249,349,449,449,0);
	  WriteLine(250,350,450,450,7);
	  WriteLine(249,349,449,449,7);
}

struct point {
	int x;
	int y;
};

void connect_points(int colour) {
	int number_of_points = 6;
	struct point points[number_of_points];

	points[0].x = 0;
	points[0].y = 0;

	points[1].x = 100;
	points[1].y = 100;

	points[2].x = 60;
	points[2].y = 120;

	points[3].x = 200;
	points[3].y = 100;

	points[4].x = 0;
	points[4].y = 300;

	points[5].x = XRES;
	points[5].y = 0;

	int i;
	struct point point_a;
	struct point point_b;
	for(i = 1; i < number_of_points; i++) {
		point_a = points[i-1];
		point_b = points[i];
		WriteLine(point_a.x, point_a.y, point_b.x, point_b.y, colour);
	}
}

void draw_bottom_part() {
	WriteLine(1, 349, XRES, 349, WHITE);
	int i;
	for(i = 350; i <= YRES; i++) {
		WriteHLine(1, i, XRES/4, BLACK);
	}
	for(i = 350; i <= YRES; i++) {
		WriteHLine(XRES/4, i, 2*XRES/4, RED);
	}
	for(i = 350; i <= YRES; i++) {
		WriteHLine(2*XRES/4, i, 3*XRES/4, BLUE);
	}
	for(i = 350; i <= YRES; i++) {
		WriteHLine(3*XRES/4, i, XRES/4, LIME);
	}
}

void draw_top_part(int colour) {
	int i;
	for(i = 1; i <= 348; i++) {
		WriteHLine(1, i, XRES, colour);
	}
	connect_points(WHITE);
}

int main() {
  printf("Demo start\n");

  black_screen();

  draw_bottom_part();
  draw_top_part(BLACK);

  // TODO the touchscreen part

  return 0;
}
