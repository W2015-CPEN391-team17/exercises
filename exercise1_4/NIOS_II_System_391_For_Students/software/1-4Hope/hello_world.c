/*
 * touchScreen.c
 *
 *  Created on: 2016-02-03
 *      Author: Kyle
 */

#include <stdio.h>

#define TOUCH_CONTROL (*(volatile unsigned char *) (0x84000230))
#define TOUCH_STATUS (*(volatile unsigned char *) (0x84000230))
#define TOUCH_TX (*(volatile unsigned char *) (0x84000232))
#define TOUCH_RX (*(volatile unsigned char *) (0x84000232))
#define TOUCH_BAUD (*(volatile unsigned char *) (0x84000234))

#define TOUCH_STATUS_RX_MASK 0x01
#define TOUCH_STATUS_TX_MASK 0x02

typedef struct{ int x, y; } Point;

void Init_Touch ( void )
{
// Program 6850 and baud rate generator to communicate with touchscreen
// send touchscreen controller an "enable touch" command
	TOUCH_CONTROL = 0x03;
	TOUCH_BAUD = 0x07;
	TOUCH_CONTROL = 0x15;


	int i;
	for( i = 0; i < 3; i++){
		while(1){
			if(TOUCH_STATUS & TOUCH_STATUS_TX_MASK){
				switch(i){
				case 0:
					TOUCH_TX = 0x55;
					break;
				case 1:
					TOUCH_TX = 0x01;
					break;
				case 2:
					TOUCH_TX = 0x12;
					break;
				}
				break;
			}
		}
	}

}
/*****************************************************************************
**   test if screen touched
*****************************************************************************/
int ScreenTouched( void)
{
// return TRUE if any data received from 6850 connected to touchscreen
// or FALSE otherwise
	if(TOUCH_STATUS_RX_MASK & TOUCH_STATUS){
		if(TOUCH_RX == 0x81){
			return 1;
		}
	}

	return 0;
}
/*****************************************************************************
**   wait for screen to be touched
*****************************************************************************/
void WaitForTouch(){
	while(!ScreenTouched())
		;
}
/* a data type to hold a point/coord */

/*****************************************************************************
* This function
waits for
a touch screen press
event
and returns X,Y coord
*****************************************************************************/
Point GetPress(void)
{
Point p1;
// wait for a pen down command then return the X,Y coord of the point
// calibrated correctly so that it maps to a pixel on screen
WaitForTouch();

while(!(TOUCH_STATUS_RX_MASK & TOUCH_STATUS))
	;

p1.x = TOUCH_RX;

while(!(TOUCH_STATUS_RX_MASK & TOUCH_STATUS))
	;
p1.x += TOUCH_RX << 7;

while(!(TOUCH_STATUS_RX_MASK & TOUCH_STATUS))
	;
p1.y = TOUCH_RX;

while(!(TOUCH_STATUS_RX_MASK & TOUCH_STATUS))
	;
p1.y += TOUCH_RX << 7;

p1.x = (int) ((p1.x) / 4090.0 * 800.0);

p1.y = (int) ((p1.y - 30) / 4070.0 * 480.0);
return p1;
}
/*****************************************************************************
* This function
waits for
a touch screen release
event
and returns X,Y coord
*****************************************************************************/
Point GetRelease(void){
	Point p1;
// wait for a pen up command then return the X,Y coord of the point
// calibrated correctly so that it maps to a pixel on screen
	while(1){
		if(TOUCH_STATUS_RX_MASK & TOUCH_STATUS){
			if(TOUCH_RX == 0x80){
				break;
			}
		}
	}

while(!(TOUCH_STATUS_RX_MASK & TOUCH_STATUS))
	;

	p1.x = TOUCH_RX;

	while(!(TOUCH_STATUS_RX_MASK & TOUCH_STATUS))
		;
	p1.x += TOUCH_RX << 7;

	while(!(TOUCH_STATUS_RX_MASK & TOUCH_STATUS))
		;
	p1.y = TOUCH_RX;

	while(!(TOUCH_STATUS_RX_MASK & TOUCH_STATUS))
		;
	p1.y += TOUCH_RX << 7;

	p1.x = (int) ((p1.x) / 4090.0 * 800.0);

	p1.y = (int) ((p1.y - 30) / 4070.0 * 480.0);
	return p1;
}



int main()
{
	int miny = 4096;
	int minx = 4096;
	int maxy = 0;
	int maxx = 0;
	Init_Touch();

	printf("Initialized\n");

while(1){
	Point p = GetPress();

	if(p.x < minx){
		minx = p.x;
	}else{
		if(p.x > maxx){
			maxx = p.x;
		}
	}

	if(p.y < miny){
			miny = p.y;
		}else{
			if(p.y > maxy){
				maxy = p.y;
			}
		}

	printf("X: %i\tY: %i\tminx: %i\tmaxx: %i\tminy: %i\tmaxy: %i\n", p.x, p.y, minx, maxx, miny, maxy);
}
  return 0;
}
