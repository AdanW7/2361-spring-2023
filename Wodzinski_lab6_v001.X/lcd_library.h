/* 
 * File:   lcd_library.h
 * Author: adan
 *
 * Created on April 6, 2023, 8:03 PM
 */

#ifndef LCD_LIBRARY_H
#define	LCD_LIBRARY_H

#ifdef	__cplusplus
extern "C" {
#endif

void delay(unsigned int);
void lcd_cmd(char);
void lcd_init(); // initialize lcd screen for future use
void lcd_setCursor(char, char);
void lcd_printChar(char); // print a specified char to screen
void shiftRight();
void shiftLeft();
void lcd_printStr(const char cString[]);


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_LIBRARY_H */

