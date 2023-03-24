/* 
 * File:   wodzinski_lab3_display.h
 * Author: adan
 *
 * Created on February 19, 2023, 2:41 PM
 */

#ifndef WODZINSKI_LAB3_DISPLAY_H
#define	WODZINSKI_LAB3_DISPLAY_H

#ifdef	__cplusplus
extern "C" {
#endif



void init7seg(void);
void showChar7seg(char myChar, int myDigit);
void cleardisplay(void);

void write_dp(int CharacterNum);
void write_1 (int CharacterNum);
void write_2 (int CharacterNum);
void write_3 (int CharacterNum);
void write_4 (int CharacterNum);
void write_5 (int CharacterNum);
void write_6 (int CharacterNum);
void write_7 (int CharacterNum);
void write_8 (int CharacterNum);
void write_9 (int CharacterNum);
void write_0 (int CharacterNum);
void write_A (int CharacterNum);
void write_b (int CharacterNum);
void write_C (int CharacterNum);
void write_d (int CharacterNum);
void write_E (int CharacterNum);
void write_F (int CharacterNum);
void display_test(void);

#ifdef	__cplusplus
}
#endif

#endif	/* WODZINSKI_LAB3_DISPLAY_H */

