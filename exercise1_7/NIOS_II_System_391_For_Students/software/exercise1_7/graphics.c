/*
 * graphics.c
 * Functions for the Graphics Controller
 */

#include <stdio.h>
#include "graphics.h"

/*******************************************************************************************
 * Return TRUE if (x,y) is between (0,0) and (XRES-1,YRES-1)
 * and print an error message and return FALSE otherwise
 ******************************************************************************************/
int check_if_point_is_on_screen(int x, int y) {
	if (x < 0) {
		printf("ERROR: Point not on screen: x value less than 0\n");
		return FALSE;
	} else if (x > XRES-1) {
		printf("ERROR: Point not on screen: x value greater than XRES-1\n");
		return FALSE;
	} else if (y < 0) {
		printf("ERROR: Point not on screen: y value less than 0\n");
		return FALSE;
	} else if (y > YRES-1) {
		printf("ERROR: Point not on screen: y value greater than YRES-1\n");
		return FALSE;
	} else {
		return TRUE;
	}
}

/**********************************************************************************
* Write the entire screen in the given colour
************************************************************************************/
void clear_screen(int colour) {
	int i;
	for(i = 0; i <= YRES-1; i++) {
		WriteHLine(0, i, XRES-1, colour);
	}
}

/*******************************************************************************************
* Writes a single pixel to the x,y coords specified using the specified colour
* Note colour is a byte and represents a palette number (0-255) not a 24 bit RGB value
********************************************************************************************/
void WriteAPixel(int x, int y, int Colour)
{
	if (ASSERT_POINTS_ARE_VALID && !check_if_point_is_on_screen(x, y)) {
		printf("WriteAPixel failed for (%d,%d)\n", x, y);
		return;
	}

	WAIT_FOR_GRAPHICS;				// is graphics ready for new command

	GraphicsX1Reg = x;				// write coords to x1, y1
	GraphicsY1Reg = y;
	GraphicsColourReg = Colour;		// set pixel colour
	GraphicsCommandReg = PutAPixel;	// give graphics "write pixel" command
}

/*********************************************************************************************
* Read a single pixel from the x,y coords specified and returns its colour
* Note returned colour is a byte and represents a palette number (0-255) not a 24 bit RGB value
*********************************************************************************************/

int ReadAPixel(int x, int y)
{
	if (ASSERT_POINTS_ARE_VALID && !check_if_point_is_on_screen(x, y)) {
		printf("ReadAPixel failed for (%d,%d)\n", x, y);
		return -1;
	}

	WAIT_FOR_GRAPHICS;					// is graphics ready for new command

	GraphicsX1Reg = x;					// write coords to x1, y1
	GraphicsY1Reg = y;
	GraphicsCommandReg = GetAPixel;		// give graphics a "get pixel" command

	WAIT_FOR_GRAPHICS;					// is graphics done reading pixel
	return (int)(GraphicsColourReg) ;	// return the palette number (colour)
}

/*******************************************************************************************
* Write a horizontal line (hardware-accelerated) starting at the x,y coords specified
* of the given length to the right
* Will print an error and return without writing anything if the start/end points are off
* of the screen or if length is negative
********************************************************************************************/
void WriteHLine(int x1, int y1, int length, int Colour)
{
	int x2 = x1 + length;

	if (ASSERT_POINTS_ARE_VALID && length < 0) {
		printf("ERROR: WriteHLine failed because length < 0 (length is %d)\n", length);
		return;
	}

	if (ASSERT_POINTS_ARE_VALID && !check_if_point_is_on_screen(x1, y1)) {
		printf("ERROR: WriteHLine failed for starting point (%d,%d)\n", x1, y1);
		return;
	}

	if (ASSERT_POINTS_ARE_VALID && !check_if_point_is_on_screen(x2, y1)) {
		printf("ERROR: WriteHLine failed for ending point (%d,%d)\n", x2, y1);
		return;
	}

	WAIT_FOR_GRAPHICS;

	GraphicsX1Reg = x1;
	GraphicsY1Reg = y1;
	GraphicsX2Reg = x2;
	GraphicsColourReg = Colour;
	GraphicsCommandReg = DrawHLine;
}

/*******************************************************************************************
* Write a vertical line (hardware-accelerated) starting at the x,y coords specified
* of the given length downwards.
* Will print an error and return without writing anything if the start/end points are off
* of the screen or if length is negative
********************************************************************************************/
void WriteVLine(int x1, int y1, int length, int Colour)
{
	int y2 = y1 + length;

	if (ASSERT_POINTS_ARE_VALID && length < 0) {
		printf("ERROR: WriteVLine failed because length < 0 (length is %d)\n", length);
		return;
	}

	if (ASSERT_POINTS_ARE_VALID && !check_if_point_is_on_screen(x1, y1)) {
		printf("ERROR: WriteVLine failed for starting point (%d,%d)\n", x1, y1);
		return;
	}

	if (ASSERT_POINTS_ARE_VALID && !check_if_point_is_on_screen(x1, y2)) {
		printf("ERROR: WriteVLine failed for ending point (%d,%d)\n", x1, y2);
		return;
	}

	WAIT_FOR_GRAPHICS;

	GraphicsX1Reg = x1;
	GraphicsY1Reg = y1;
	GraphicsY2Reg = y2;
	GraphicsColourReg = Colour;
	GraphicsCommandReg = DrawVLine;
}

/*******************************************************************************************
* Write a Bresenham line (hardware-accelerated) from x1,y1 to x2,y2
* Will print an error and return without writing anything if the start/end points are off
* of the screen
********************************************************************************************/
void WriteLine(int x1, int y1, int x2, int y2, int Colour)
{
	if (ASSERT_POINTS_ARE_VALID && !check_if_point_is_on_screen(x1, y1)) {
		printf("WriteLine failed for starting point (%d,%d)\n", x1, y1);
		return;
	}

	if (ASSERT_POINTS_ARE_VALID && !check_if_point_is_on_screen(x2, y2)) {
		printf("WriteLine failed for ending point (%d,%d)\n", x2, y2);
		return;
	}

	WAIT_FOR_GRAPHICS;

	GraphicsX1Reg = x1;
	GraphicsY1Reg = y1;
	GraphicsX2Reg = x2;
	GraphicsY2Reg = y2;
	GraphicsColourReg = Colour;
	GraphicsCommandReg = DrawLine;
}

/**********************************************************************************
* subroutine to program a hardware (graphics chip) palette number with an RGB value
* e.g. ProgramPalette(RED, 0x00FF0000) ;
************************************************************************************/

void ProgramPalette(int PaletteNumber, int RGB)
{
    WAIT_FOR_GRAPHICS;

    GraphicsColourReg = PaletteNumber;
    GraphicsX1Reg = RGB >> 16   ;        // program red value in ls.8 bit of X1 reg
    GraphicsY1Reg = RGB ;                // program green and blue into ls 16 bit of Y1 reg
    GraphicsCommandReg = ProgramPaletteColour; // issue command
}


/*********************************************************************************************
* Draw a horizontal line (1 pixel at a time) starting at the x,y coords specified
* Use for testing only
*********************************************************************************************/

void HLine(int x1, int y1, int length, int Colour)
{
	int i;
	for(i = x1; i < x1+length; i++ )
		WriteAPixel(i, y1, Colour);
}

/*********************************************************************************************
* Draw a vertical line (1 pixel at a time) starting at the x,y coords specified
* Use for testing only
*********************************************************************************************/

void VLine(int x1, int y1, int length, int Colour)
{
	int i;
	for(i = y1; i < y1+length; i++ )
		WriteAPixel(x1, i, Colour);
}

/*******************************************************************************
* Implementation of Bresenhams line drawing algorithm (1 pixel at a time)
* Use for testing only
*******************************************************************************/

int abs(int a)
{
    if(a < 0)
        return -a ;
    else
        return a ;
}

int sign(int a)
{
    if(a < 0)
        return -1 ;
    else if (a == 0)
        return 0 ;
    else
        return 1 ;
}

void Line(int x1, int y1, int x2, int y2, int Colour)
{
    int x = x1;
    int y = y1;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int s1 = sign(x2 - x1);
    int s2 = sign(y2 - y1);
    int i, temp, interchange = 0, error ;

// if x1=x2 and y1=y2 then it is a line of zero length

    if(dx == 0 && dy == 0)
        return ;

 // must be a complex line so use bresenhams algorithm
    else    {

// swap delta x and delta y depending upon slop of line

        if(dy > dx) {
            temp = dx ;
            dx = dy ;
            dy = temp ;
            interchange = 1 ;
        }

// initialise the error term to compensate for non-zero intercept

        error = (dy << 1) - dx ;    // (2 * dy) - dx

// main loop
        for(i = 1; i <= dx; i++)    {
            WriteAPixel(x, y, Colour);

            while(error >= 0)   {
                if(interchange == 1)
                    x += s1 ;
                else
                    y += s2 ;

                error -= (dx << 1) ;    // times 2
            }

            if(interchange == 1)
                y += s2 ;
            else
                x += s1 ;

            error += (dy << 1) ;    // times 2
        }
    }
}

/*******************************************************************************
* Compare software and hardware lines to check for off-by-one-errors
* Use for testing only
*******************************************************************************/
void line_test_screen() {
	// write RED lines (software) over the entire screen area
	int i;
	for(i = 0; i <= YRES-1; i++) {
		HLine(0, i, XRES-1, RED);
		printf("i is %d\n", i);
	}

	//each pair of lines (for horizontal/vertical) should have the same length

	//for horizontal lines,
	//test lines should start at both even and odd indexes
	//and have even and odd lengths
	//because they may be drawn incorrectly when drawing two pixels per cycle

	// even start pixel, even length
	HLine(100,100,100,LIME);
	HLine(100,101,100,LIME);
	HLine(100,102,100,LIME);
	HLine(100,103,100,LIME);
	HLine(100,104,100,LIME);
	WriteHLine(100,105,100,BLUE);
	WriteHLine(100,106,100,BLUE);
	WriteHLine(100,107,100,BLUE);
	WriteHLine(100,108,100,BLUE);
	WriteHLine(100,109,100,BLUE);

	// odd start pixel, even length
	HLine(101,120,100,LIME);
	HLine(101,121,100,LIME);
	HLine(101,122,100,LIME);
	HLine(101,123,100,LIME);
	HLine(101,124,100,LIME);
	WriteHLine(101,125,100,BLUE);
	WriteHLine(101,126,100,BLUE);
	WriteHLine(101,127,100,BLUE);
	WriteHLine(101,128,100,BLUE);
	WriteHLine(101,129,100,BLUE);

	// even start pixel, odd length
	HLine(100,140,101,LIME);
	HLine(100,141,101,LIME);
	HLine(100,142,101,LIME);
	HLine(100,143,101,LIME);
	HLine(100,144,101,LIME);
	WriteHLine(100,145,101,BLUE);
	WriteHLine(100,146,101,BLUE);
	WriteHLine(100,147,101,BLUE);
	WriteHLine(100,148,101,BLUE);
	WriteHLine(100,149,101,BLUE);

	// odd start pixel, odd length
	HLine(101,160,101,LIME);
	HLine(101,161,101,LIME);
	HLine(101,162,101,LIME);
	HLine(101,163,101,LIME);
	HLine(101,164,101,LIME);
	WriteHLine(101,165,101,BLUE);
	WriteHLine(101,166,101,BLUE);
	WriteHLine(101,167,101,BLUE);
	WriteHLine(101,168,101,BLUE);
	WriteHLine(101,169,101,BLUE);

	// test vertical lines
	VLine(200,200,100,LIME);
	VLine(201,200,100,LIME);
	VLine(202,200,100,LIME);
	VLine(203,200,100,LIME);
	VLine(204,200,100,LIME);
	WriteVLine(205,200,100,BLUE);
	WriteVLine(206,200,100,BLUE);
	WriteVLine(207,200,100,BLUE);
	WriteVLine(208,200,100,BLUE);
	WriteVLine(209,200,100,BLUE);

	// compare bresenham lines
	// should see a black line on top
	// and a purple line a few pixels below it
	// otherwise the hardware-accelerated line doesn't perfectly match

	WriteLine(240,340,440,440,MAGENTA);
	WriteLine(239,339,439,439,MAGENTA);
	Line(240,340,440,440,BLACK);
	Line(239,339,439,439,BLACK);

	Line(250,350,450,450,BLACK);
	Line(249,349,449,449,BLACK);
	WriteLine(250,350,450,450,MAGENTA);
	WriteLine(249,349,449,449,MAGENTA);
}
