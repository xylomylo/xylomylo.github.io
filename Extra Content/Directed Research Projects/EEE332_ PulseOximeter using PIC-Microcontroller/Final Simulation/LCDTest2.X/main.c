
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

//#include "config.h"

#include "I2C_LCD.h"
 
void main(void) {
 
  I2C_Master_Init();
  LCD_Init(0x4E); // Initialize LCD module with I2C address = 0x4E
 
  LCD_Set_Cursor(1, 1);
  LCD_Write_String(" Insert Text");
  LCD_Set_Cursor(2, 1);
  LCD_Write_String(" DeepBlue");
  
  for(i=1;i<50000;i++);
  LCD_Clear();
  
  LCD_Set_Cursor(1, 1);
  LCD_Write_String(" Insert Text");
  LCD_Set_Cursor(2, 1);
  LCD_Write_String(" DeepBlue");
 
  while(1)
  {
 
  }
  return;
}