#include <stdio.h>
#include "touchScreen.h"
#include "graphics.h"

int main()
{
  int i;
  for(i = 0; i < 200; i++){
	  WriteHLine(100, i, 200, RED);
  }

  int count = 0;
  while(1){
	  Point p = GetPress();
	  if(p.x <= 300 && p.x >= 100 && p.y <= 200){
		  printf("%d Touched\tX: %d\tY: %d\n", count++, p.x, p.y);
	  }
  }
  return 0;
}
