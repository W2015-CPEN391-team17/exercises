/*
 * conversion.h
 *
 *  Created on: 2016-02-06
 *      Author: Kyle
 */

#ifndef CONVERSION_H_
#define CONVERSION_H_

#define INT_MIN (-2147483647 - 1)
#define INT_MAX 2147483647

typedef struct { double x, y; } GPSPoint;

void convertGPSPointsToPoints( Point points[] );
void convertGPSReal( GPSPoint topLeft, GPSPoint topRight, GPSPoint points[], GPSPoint bottomRight, int nPoints);


#endif /* CONVERSION_H_ */
