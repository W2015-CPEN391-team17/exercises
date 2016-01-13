/*
 * CPEN 391 - Exercise 1.1
 * Nicholas Mulvenna
 *
 * Increases count when buttons are pressed. If more than one button is
 * pressed, count will not increase until they are all released.
 * Hardware will reset if all four buttons are held simultaneously.
 */

#include <stdio.h>
#include "altera_up_avalon_character_lcd.h"

// upper four bits of KEYS_ACTIVE_HIGH are always zero (see VHDL)
#define KEYS_ACTIVE_HIGH (volatile char *) 0x00001000
#define SWITCHES (volatile char*) 0x00001020
#define LEDS (char *) 0x00001010

#define LCD_LINE_LENGTH 16

#define KEY0_MASK 0x01
#define KEY1_MASK 0x02
#define KEY2_MASK 0x04
#define KEY3_MASK 0x08

#define KEY_STRING "KEY "
#define KEY_STRING_EMPTY "     "

int main()
{
  printf("Exercise 1.1 - Press all four keys simultaneously to reset\n");

  alt_up_character_lcd_dev * char_lcd_dev;

  char_lcd_dev = alt_up_character_lcd_open_dev("/dev/character_lcd_0");
  if (char_lcd_dev == NULL) {
	  printf("Error could not open character LCD device\n");
  } else {
	  printf("Opened character LCD device\n");
  }

  alt_up_character_lcd_init(char_lcd_dev);

  while (1) {
	  if (*KEYS_ACTIVE_HIGH) {
		  if (KEY0_MASK & *KEYS_ACTIVE_HIGH) {
			  alt_up_character_lcd_set_cursor_pos(char_lcd_dev,0,0);
			  alt_up_character_lcd_string(char_lcd_dev, "KEY0");
		  } else if (KEY1_MASK & *KEYS_ACTIVE_HIGH) {
			  alt_up_character_lcd_set_cursor_pos(char_lcd_dev,0,0);
			  alt_up_character_lcd_string(char_lcd_dev, "KEY1");
		  } else if (KEY2_MASK & *KEYS_ACTIVE_HIGH) {
			  alt_up_character_lcd_set_cursor_pos(char_lcd_dev,0,0);
			  alt_up_character_lcd_string(char_lcd_dev, "KEY2");
		  } else if (KEY3_MASK & *KEYS_ACTIVE_HIGH) {
			  alt_up_character_lcd_set_cursor_pos(char_lcd_dev,0,0);
			  alt_up_character_lcd_string(char_lcd_dev, "KEY3");
		  }
	  }
  }

  return 0;
}
