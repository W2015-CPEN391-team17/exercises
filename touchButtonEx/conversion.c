/*
 * conversion.c
 *
 *  Created on: 2016-02-06
 *      Author: Kyle
 */

#include "touchscreen.h" //for definition of Point
#include "conversion.h"
#include "graphics.h" //for XRES/YRES
//#include <limits.h> //Couldn't get this include to work, idk why. Have used the min/max def'n's from it in conversion.h

/*Mutates points. Assumes player has ran across the field during some point in the game, in both x and y direction.
 *Assumes field is in line with lat/long.
 *
 *Should really just have defined points of where the field is. Maybe use Google Maps/Earth?
 *Basically, this function is just for testing atm, need a new one once we know where our field is, but concept will be similar.
 *
 */
void convertGPSPointsToPoints( Point points[] ){
	int minx = points[0].x;
	int miny = points[0].y;
	int maxx = points[0].x;
	int maxy = points[0].y;

	int i = 1;

	//Tim could probably figure out the max/min while pulling points, would be faster
	while(points[i].x != INT_MIN){
		if(points[i].x < minx){
			minx = points[i].x;
		}else if(points[i].x > maxx){
			maxx = points[i].x;
		}

		if(points[i].y < miny){
			miny = points[i].y;
		}else if(points[i].y > maxy){
			maxy = points[i].y;
		}
		i++;
	}

	int xRange = maxx - minx;
	int yRange = maxy - miny;

	double mX = XRES / (double) xRange;
	double mY = YRES / (double) yRange;

	i = 1;

	while(points[i].x != INT_MIN){
		points[i].x = mX * (points[i].x - minx);
		points[i].y = mY * (points[i].y - miny);

		i++;
	}
}
