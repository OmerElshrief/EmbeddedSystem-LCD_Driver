

/*******************************************************************************************************/
/************************************* LCD DRIVER for ATMEGA32 *****************************************/

/***************************************************************************************/
/* Description ! 16x2 Character LCD Driver                                             */
/* Release Date! 11/9/2018                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/


#include "LCD_config.h"
#include "LCD_interface.h"
#include <avr/io.h>
#include <util/delay.h>


/***********************************************************************/
/* Desription: Function to send commands to the LCD Module             */
/* Parameters: Command as Hexadecimal                                  */
/* Return: Void                                                        */
/* Sending commands to the Data port by Setting RS=0 & RW=0            */
/***********************************************************************/

void LCD_send_command(unsigned char cmnd)
{
  DATA_PORT = cmnd;             ////Send the Command to the Data PORT

  CNTRL_PORT &= ~(1<<RW_PIN);   ////Clear the RW Pin at the CONTROL PORT
  CNTRL_PORT &= ~(1<<RS_PIN);   ////Clear the RS pin at the Control Port

  CNTRL_PORT |= (1<< EN_PIN);            //// Toggling the Enable Pin to apply the changes
  _delay_us(2);
  CNTRL_PORT &= ~(1<< EN_PIN);
  _delay_us(100);

}


/***********************************************************************/
/* Desription: Function to send Data to the LCD Data Register in       */
/*              order to diplay the Data on the LCD                    */
/* Parameters: Data as char                                            */
/* Return: Void                                                        */
/* Sending data by setting RW=0 & RS=1                                 */
/***********************************************************************/
void LCD_send_data(unsigned char data)
{
    DATA_PORT = data;   ////Send the Command to the Data PORT

    CNTRL_PORT &= ~(1<<RW_PIN);        ////Clear the RW Pin at the CONTROL PORT
    CNTRL_PORT |=  (1<<RS_PIN);        ////Set the RS pin at the Control Port

    CNTRL_PORT |= (1<< EN_PIN);        //// Toggling the Enable Pin to apply the changes
    _delay_us(2);
    CNTRL_PORT &= ~(1<< EN_PIN);
    _delay_us(100);





}


/***********************************************************************/
/* Desription: Function to Initialize LCD by sending commands          */
/* Parameters: Void                                                    */
/* Return: Void                                                        */
/* Commands can be changed from the LCD_config.h file                  */
/***********************************************************************/
void LCD_init(void)
{
  LCD_clear();
  _delay_ms(10);
	LCD_send_command(CMND_2LINES);
	LCD_send_command(CMND_DISPLAYONCURSORON);
	LCD_send_command(CMND_CLEARDISPLAY);
	_delay_ms(10);
	LCD_send_command(CMND_INCREMENTCURSOR);


}


/***********************************************************************/
/* Desription: Function to put the cursor on a specific position X,Y   */
/* Parameters: X as a Char & Y as a Char                               */
/* Return: Void                                                        */
/***********************************************************************/
void LCD_goto(unsigned char y, unsigned char x)
{
  unsigned char firstAddress[] = {0x80,0xC0,0x94,0xD4};

	LCD_send_command(firstAddress[y-1] + x-1);
	_delay_ms(10);
}



/************************************************************************/
/* Desription: Function to print a String using the LCD_send_data func  */
/* Parameters: Pointer to char array (String)                           */
/* Return: Void                                                         */
/************************************************************************/
void LCD_print(char *string)
{
  while(*string > 0)
  {
    LCD_send_data(*string++);

  }

}


/***********************************************************************/
/* Desription: Function to the Blinking Effect                         */
/* Parameters: Void                                                    */
/* Return: Void                                                        */
/***********************************************************************/
void LCD_blink(void)
{
  LCD_send_command(CMND_DISPLAYONCURSOROFF);
  _delay_ms(250);
  LCD_send_command(CMND_DISPLAYONCURSORON);
  _delay_ms(250);

}

/***********************************************************************/
/* Desription: Function to clear the LCD Display by sending command    */
/* Parameters: Void                                                    */
/* Return: Void                                                        */
/***********************************************************************/
void LCD_clear(void)
{
  LCD_send_command(CMND_CLEARDISPLAY);
  _delay_ms(100);
}


/***********************************************************************/
/* Desription: function to Initialize DATA & control Ports             */
/* Parameters: Void                                                    */
/* Return: Void                                                        */
/* DATA and Control Ports can be changed from the LCD_config.h file    */
/***********************************************************************/
void LCD_initPorts()
{
  DATA_PORT=0x00;
  DATA_DDR = 0xff;

  CNTRL_PORT=0x00;
  CNTRL_DDR= 0xff;
}
