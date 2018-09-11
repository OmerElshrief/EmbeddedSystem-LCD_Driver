//*****************************************************************************************************//
//****************************************LCD DRIVER******************************************************//

#ifndef LCD_interface.h
#define LCD_interface.h

/***************************************************************************************/
/* Description ! 16x2 Character LCD Driver                                             */
/* Release Date! 11/9/2018                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/


/***********************************************************************/
/* Desription: Function to send commands to the LCD Command Register   */
/* Parameters: Command as Hexadecimal                                  */
/* Return: Void                                                        */
/***********************************************************************/
void LCD_send_command(unsigned char cmnd);

/***********************************************************************/
/* Desription: Function to send Data to the LCD Data Register in       */
/*              order to diplay the Data on the LCD   */
/* Parameters: Data as char                                            */
/* Return: Void                                                        */
/***********************************************************************/
void LCD_send_data(unsigned char data);

/***********************************************************************/
/* Desription: Function to Initialize LCD by sending commands          */
/* Parameters: Void                                                    */
/* Return: Void                                                        */
/***********************************************************************/
void LCD_init(void);

/***********************************************************************/
/* Desription: Function to put the cursor on a specific position X,Y   */
/* Parameters: X as a Char & Y as a Char                               */
/* Return: Void                                                        */
/***********************************************************************/
void LCD_goto(unsigned char y, unsigned char x);

/************************************************************************/
/* Desription: Function to print a String using the LCD_send_data func  */
/* Parameters: Pointer to char array (String)                           */
/* Return: Void                                                         */
/************************************************************************/
void LCD_print(char *string);

/***********************************************************************/
/* Desription: Function to the Blinking Effect                         */
/* Parameters: Void                                                    */
/* Return: Void                                                        */
/***********************************************************************/
void LCD_blink(void);

/***********************************************************************/
/* Desription: Function to clear the LCD Display by sending command    */
/* Parameters: Void                                                    */
/* Return: Void                                                        */
/***********************************************************************/
void LCD_clear(void);

#endif
