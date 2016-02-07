/*
 * Exercise 1.7
 */

#include <stdio.h>
#include "graphics.h"

void black_screen() {
	// write black lines over the entire screen area
	int i;
	for(i = 0; i <= YRES-1; i++) {
		WriteHLine(0, i, XRES-1, BLACK);
		//HLine(0, i, XRES-1, BLACK);
	}
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

	points[5].x = 313;
	points[5].y = 0;

	int i;
	struct point point_a;
	struct point point_b;
	for(i = 1; i < 2; i++) {
		point_a = points[i-1];
		point_b = points[i];
		WriteLine(point_a.x, point_a.y, point_b.x, point_b.y, colour);
	}
}

void draw_bottom_part() {
	WriteLine(1, 349, XRES-1, 349, WHITE);
	int i;
	for(i = 350; i <= YRES-1; i++) {
		WriteHLine(0, i, XRES/4, BLACK);
		//HLine(0, i, XRES/4, BLACK);
	}
	for(i = 350; i <= YRES-1; i++) {
		WriteHLine(XRES/4, i, XRES/4, RED);
		//HLine(XRES/4, i, XRES/4, RED);
	}
	for(i = 350; i <= YRES-1; i++) {
		WriteHLine(2*XRES/4, i, XRES/4, BLUE);
		//HLine(2*XRES/4, i, XRES/4, BLUE);
	}
	for(i = 350; i <= YRES-1; i++) {
		WriteHLine(3*XRES/4, i, 33, LIME);
		//HLine(3*XRES/4, i, (XRES/4)-1, LIME);
	}
}

void draw_top_part(int colour) {
	int i;
	for(i = 0; i <= 348; i++) {
		WriteHLine(0, i, XRES-1, colour);
		//HLine(0, i, XRES-1, colour);
	}
	connect_points(WHITE);
}

int main() {
  printf("Demo start\n");

  black_screen();
  printf("**********after black screen**********\n");
  draw_bottom_part();
  printf("**********after bottom part**********\n");
  draw_top_part(BLACK);
  printf("**********after top part**********\n");

  return 0;
}

//TODO rerun this
void line_comparison() {
	  //compare one-pixel-at-a-time with hardware-accelerated lines
	  //each pair of lines should have the same length

	  HLine(101,100,100,3);
	  HLine(101,101,100,3);
	  HLine(101,102,100,3);
	  HLine(101,103,100,3);
	  HLine(101,104,100,3);
	  WriteHLine(101,105,100,4);
	  WriteHLine(101,106,100,4);
	  WriteHLine(101,107,100,4);
	  WriteHLine(101,108,100,4);
	  WriteHLine(101,109,100,4);

	  VLine(200,201,100,5);
	  VLine(201,201,100,5);
	  VLine(202,201,100,5);
	  VLine(203,201,100,5);
	  VLine(204,201,100,5);
	  WriteVLine(205,201,100,6);
	  WriteVLine(206,201,100,6);
	  WriteVLine(207,201,100,6);
	  WriteVLine(208,201,100,6);
	  WriteVLine(209,201,100,6);

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
