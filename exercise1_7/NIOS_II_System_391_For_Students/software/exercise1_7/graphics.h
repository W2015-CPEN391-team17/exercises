/*
 * graphics.h
 *
 *  Created on: Jan 26, 2016
 *      Author: nick
 */

#ifndef EXERCISE1_7_H_
#define EXERCISE1_7_H_

#define TRUE 1
#define FALSE 0

#define XRES 800
#define YRES 480

// graphics registers all address begin with '8' so as to by pass data cache on NIOS

#define GraphicsCommandReg   		(*(volatile unsigned short int *)(0x84000000))
#define GraphicsStatusReg   		(*(volatile unsigned short int *)(0x84000000))
#define GraphicsX1Reg   			(*(volatile unsigned short int *)(0x84000002))
#define GraphicsY1Reg   			(*(volatile unsigned short int *)(0x84000004))
#define GraphicsX2Reg   			(*(volatile unsigned short int *)(0x84000006))
#define GraphicsY2Reg   			(*(volatile unsigned short int *)(0x84000008))
#define GraphicsColourReg   		(*(volatile unsigned short int *)(0x8400000E))
#define GraphicsBackGroundColourReg   	(*(volatile unsigned short int *)(0x84000010))

/************************************************************************************************
** This macro pauses until the graphics chip status register indicates that it is idle
***********************************************************************************************/

#define WAIT_FOR_GRAPHICS		while((GraphicsStatusReg & 0x0001) != 0x0001);

//Here are some software routines to drive some simple graphics functions

// #defined constants representing values we write to the graphics 'command' register to get
// it to draw something. You will add more values as you add hardware to the graphics chip
// Note DrawHLine, DrawVLine and DrawLine at the moment do nothing - you will modify these

#define DrawHLine				1
#define DrawVLine				2
#define DrawLine				3
#define	PutAPixel				0xA
#define	GetAPixel				0xB
#define	ProgramPaletteColour    0x10

// defined constants representing colours pre-programmed into colour palette
// there are 256 colours but only 8 are shown below, we write these to the colour registers
//
// the header files "colours.h" contains constants for all 256 colours
// while the course file ColourPaletteData.c contains the 24 bit RGB data
// that is pre-programmed into the palette

#define	BLACK			0
#define	WHITE			1
#define	RED				2
#define	LIME			3
#define	BLUE			4
#define	YELLOW			5
#define	CYAN			6
#define	MAGENTA			7

void WriteAPixel(int x, int y, int Colour);
void WriteHLine(int x1, int y1, int length, int Colour);
void WriteVLine(int x1, int y1, int length, int Colour);
void WriteLine(int x1, int y1, int x2, int y2, int Colour);
int ReadAPixel(int x, int y);
void ProgramPalette(int PaletteNumber, int RGB);

// draw lines one pixel at a time, use only for testing
void HLine(int x1, int y1, int length, int Colour);
void VLine(int x1, int y1, int length, int Colour);
int abs(int a);
int sign(int a);
void Line(int x1, int y1, int x2, int y2, int Colour);

/* Shape drawing functions */
/*
 * Draw a non-filled rectangle at a top-left point at (x1, y1) to a
 * bottom-right point at (x2, y2).
 * Preconditions: x1 <= x2 and y1 <= y2
 */
void DrawRectangle(int x1, int y1, int x2, int y2, int color);
/*
 * Draw a filled rectangle at a top-left point (x1, y1) to a
 * bottom-right point at (x2, y2).
 * Preconditions: x1 <= x2 and y1 <= y2
 */
void DrawFilledRectangle(int x1, int y1, int x2, int y2, int color);

void DrawCircle(int x0, int y0, int radius, int color);

/*
 * Draw text string on a single line.
 * Preconditions: text != NULL
 * Note: Writing a space character with erase set to true will set all pixels
 * in the character to the background colour
 */
void DrawText(int x, int y, int font_color, int background_color, char *text, int erase);

/*
 * Draw at a top-left point at (x1, y1) to a bottom-right point at (x2, y2).
 * It is up to the user to ensure that the button dimensions are larger than
 * the text dimensions.
 * Preconditions: x1 <= x2, y1 <= y2 and text != NULL
 */
void DrawButton(int x1, int y1, int x2, int y2, int outline_color, int font_color,
				int fill_color, char *text);
#endif /* EXERCISE1_7_H_ */
