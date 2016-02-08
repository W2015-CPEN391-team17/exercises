/*
 * Exercise 1.7
 */

#include <stdio.h>
#include "graphics.h"

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

	points[5].x = 613;
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
	WriteHLine(0, 349, XRES-1, WHITE);
	int i;
	for(i = 350; i <= YRES-1; i++) {
		WriteHLine(0, i, XRES/4, BLACK);
	}
	for(i = 350; i <= YRES-1; i++) {
		WriteHLine(XRES/4, i, XRES/4, RED);
	}
	for(i = 350; i <= YRES-1; i++) {
		WriteHLine(2*XRES/4, i, XRES/4, BLUE);
	}
	for(i = 350; i <= YRES-1; i++) {
		WriteHLine(3*XRES/4, i, XRES/4-1, LIME);
	}
}

void draw_top_part(int colour) {
	int i;
	for(i = 0; i <= 348; i++) {
		WriteHLine(0, i, XRES-1, colour);
	}
	connect_points(WHITE);
}

int main() {
  printf("Exercise 1.7\n");
  clear_screen(BLACK);
  Rectangle(0, 0, 100, 100, WHITE);
  Rectangle(200, 0, XRES-2, 300, WHITE);
  Button(600, 200, 670, 225, LIME, BLUE, RED, "HELLO");
  Circle(700, 350, 20, MAGENTA);

  int colour = 1;
  int i = 0;
  int j = 200;
  int k = 0;

  for(i=0;i < 1000; i++) {
	  i = (i + k + 1) % 500;
	  j = (i + j + 1) % 500;
	  WriteLine(501, 1, i%XRES, j%YRES, colour);
	  k = (k + j + i) % 50;
	  colour = (colour + i + j + k) % 8;
	  //DrawFilledRectangle(0, 200, 100, 300, colour); //TODO ask about this
	  colour = (colour + 1 + i/2) % 8;
  }


  write_test_screen();

  return 0;
}
