/*
 * Exercise 1.3
 * Sends a string using the RS232 port
 *
 */

#include <stdio.h>

#define RS232_CONTROL (*(volatile unsigned char *)(0x84000200))
#define RS232_STATUS (*(volatile unsigned char *)(0x84000200))
#define RS232_TXDATA (*(volatile unsigned char *)(0x84000202))
#define RS232_RXDATA (*(volatile unsigned char *)(0x84000202))
#define RS232_BAUD (*(volatile unsigned char *)(0x84000204))

#define RS232_STATUS_TX_MASK 0x02
#define RS232_STATUS_RX_MASK 0x01

//call this function at the start of the program before
//attempting to read or write via rs232 port
void init_rs232(void)
{
	//set up 6850 control register to utilize a divide by 16 clock,
	//set RTS low, use 8 bits of data, no parity, 1 stop bit
	//transmitter interrupt disabled
	//program baud rate generator to use 115k baud
	RS232_CONTROL = 0x15;
	RS232_BAUD = 0x01;
}

char putchar_rs232(char c)
{
	//poll Tx bit in 6850 status register. Wait for it to become '1'
	//write 'c' to the 6850 TxData register to output the character
	while(1)
	{
		if (RS232_STATUS & RS232_STATUS_TX_MASK)
		{
			RS232_TXDATA = c;
			return c;
		}
	}
}

char getchar_rs232(void)
{
	//poll Rx bit in 6850 status register. Wait for it to become '1'
	//read received character from 6850 register
	while(1)
	{
		if (RS232_STATUS & RS232_STATUS_RX_MASK)
		{
			return RS232_RXDATA;
		}
	}
}

//simply tests if a character is available to read
int rs232_test_for_received_data(void)
{
	//test Rx bit in 6850 serial comms chip status register
	//if Rx bit is set, return TRUE, otherwise return FALSE
	if (RS232_STATUS & RS232_STATUS_RX_MASK)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
  printf("Use Hyperterminal with 115k baud, 8 bit, no parity, 1 stop bit\n");
  init_rs232();
  const char hello_world[] = "Hello world!\n\r";
  char c;
  int i;
  for(i = 0; i <= 13; i++) {
	  c = hello_world[i];
	  putchar_rs232(c);
  }
  return 0;
}
