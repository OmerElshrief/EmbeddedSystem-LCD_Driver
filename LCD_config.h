

/**************************************************************************************************************/
/**********************************LCD Configuration file******************************************************/
/*The user may change configuration in this file, like Data port and Command Port, control pins and data pins */


#define DATA_PORT PORTD                ////Port D is the Data Port, user may change this define as needed.
#define DATA_DDR	DDRD                 ////Data Port Direction set as DDRD because DataPort is D, user May change this define

#define CNTRL_PORT	PORTB              ////Port B is the Control Port, user may change this define as needed.
#define CNTRL_DDR	  DDRB               ////CNTRL Port Direction set as DDRB because CTRL is B, user May change this define

#define RW_PIN 1                       //// RW pin is connected to the second pin at PORT B
#define RS_PIN 0                       //// RS pin is connected to the first pin at PORT B
#define EN_PIN 2                       //// Enable pin is connected to the third pin at PORT B

/********************************************************************************/
/*                Commands for the LCD Command Register                         */
/********************************************************************************/
#define CMND_CLEARDISPLAY         0X01
#define CMND_RETURNHOME           0X02          ////Set DDRAM address to 0 in address counter also return display from being shifted
#define CMND_DECREMENTCURSOR      0X04          ////Shift cursor to the left
#define CMND_INCREMENTCURSOR      0X06          ////Shift cursor to the right
#define CMND_SHIFTDISPLAYRIGHT    0X05          ////Shift the display to the Right
#define CMND_SHIFTDIsPLAYLEFT     0x07          ////Shift display to the Left
#define CMND_DISPLAYOFFCURSOROFF  0X08          ////Display is OFF and cursor is OFF
#define CMND_DISPLAYOFFCURSORON   0X0A          ////Display is OFF and cursor is ON
#define CMND_DISPLAYONCURSOROFF   0X0C          ////Display is On cursor is OFF
#define CMND_DISPLAYONCURSORON    0X0E          ////Display ON Cursor is Blinking
#define CMND_SHIFTCURSORLEFT      0x10          ////Shift the cursor position to the Left
#define CMND_SHIFTCURSORRIGHT     0x14          ////Shift the cursor position to the Right
#define CMND_SHIFTALLDISPLAYLEFT  0X18          ////Shift entire display to the Left
#define CMND_SHIFTALLDISPLAYRIGHT 0X1C          ////Shift entire display to the Right
#define CMND_TOTHE1STLINE         0x80          ////Force the cursor to the beginning of the 1st Line
#define CMND_TOTHE2STLINE         0xC0          ////Force the cursor to the beginning of the 2st Line
#define CMND_2LINES               0X38          ////2 Lines and 5x7 matrix

/*******************************************************************************/
