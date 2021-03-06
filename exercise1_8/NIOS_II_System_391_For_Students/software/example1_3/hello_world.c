/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>

int main()
{
  printf("Hello from Nios II!\n");

  return 0;
}

/////

/**************************************************************************
/*  Subroutine to initialise the RS232 Port by writing some data
**  to the internal registers.
**  Call this function at the start of the program before you attempt
**  to read or write to data via the RS232 port
**
**  Refer to 6850 data sheet for details of registers and
***************************************************************************/

void Init_RS232(void)
{
	// set up 6850 Control Register to utilise a divide by 16 clock,
	// set RTS low, use 8 bits of data, no parity, 1 stop bit,
	// transmitter interrupt disabled
	// program baud rate generator to use 115k baud
}

int putcharRS232(int c)
{
	// poll Tx bit in 6850 status register. Wait for it to become '1'
	// write 'c' to the 6850 TxData register to output the character
	return c ;    // return c
}
int getcharRS232(void)
{
	// poll Rx bit in 6850 status register. Wait for it to become '1'
	// read received character from 6850 RxData register.
}

// the following function polls the 6850 to determine if any character
// has been received. It doesn't wait for one, or read it, it simply tests
// to see if one is available to read

int RS232TestForReceivedData(void)
{
	// Test Rx bit in 6850 serial comms chip status register
	// if RX bit is set, return TRUE, otherwise return FALSE
}
