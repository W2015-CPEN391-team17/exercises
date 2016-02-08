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
  printf("Demo start\n");
  clear_screen(MAGENTA);
  //line_test_screen();
  printf("**********after black screen**********\n");
  draw_bottom_part();
  printf("**********after bottom part**********\n");
  draw_top_part(BLACK);
  printf("**********after top part**********\n");

  return 0;
}
