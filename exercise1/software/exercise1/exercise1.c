/*
 * CPEN 391 - Exercise 1.1
 * Nicholas Mulvenna
 *
 * Increases count when buttons are pressed. If more than one button is
 * pressed, count will not increase until they are all released.
 * Hardware will reset if all four buttons are held simultaneously.
 */

#include <stdio.h>

// upper four bits of KEYS_ACTIVE_HIGH are always zero (see VHDL)
#define KEYS_ACTIVE_HIGH (volatile char *) 0x00001000
#define SWITCHES (volatile char*) 0x00001020
#define LEDS (char *) 0x00001010

int main()
{
  printf("Exercise 1.1 - Press all four keys simultaneously to reset\n");

  char number_of_button_presses = 0;
  char button_previously_held_down = 0;

  while (1) {
	  if (*KEYS_ACTIVE_HIGH) {
		  if (!button_previously_held_down) {
			  button_previously_held_down = 1;
		  }
	  } else {
		  if (button_previously_held_down) {
			  button_previously_held_down = 0;
			  number_of_button_presses++;
			  printf("%d\n", number_of_button_presses);
		  }
	  }
	  *LEDS = number_of_button_presses;
  }

  return 0;
}
