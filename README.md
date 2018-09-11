# EmbeddedSystems: LCD_Driver

You may include LCD_prog.c in your Project.
## The defualt configurations are :
PORTD as Data Port
PORTB as Control Port 
RW_PIN is PORTB  pin 1
RS_PIN is PORTB  pin 0
EN_PIN is PORTB  pin 2

User can change these configurations at LCD_config.h file, you will also find the Commands so you can change it if you are using another chip.

## Example for using the driver:

#include <avr/io.h>

#include <util/delay.h>

#include "../libs/LCD_prog.c"

#define F_CPU 120000000      // FCPU Definition for util/delay


void main(void)
{

		LCD_initPorts();
		LCD_init();
		LCD_goto(1,2);
		LCD_print("Omer");
		LCD_goto(2,1);
		LCD_print("El-Shrief");

		while(1)
		{
			LCD_blink();

		}



}



