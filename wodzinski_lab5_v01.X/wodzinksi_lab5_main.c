/*
 * File:   wodzinksi_lab5_main.c
 * Author: adan
 *
 * Created on March 23, 2023, 7:48 PM
 */


#include "xc.h"

#include "lcd_library.h"

//CW1: FLASH CONFIGURATION WORD 1 (see PIC24 Family Reference Manual 24.1)
#pragma config ICS = PGx1          // Comm Channel Select (Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1)
#pragma config FWDTEN = OFF        // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config GWRP = OFF          // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF           // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF        // JTAG Port Enable (JTAG port is disabled)


// CW2: FLASH CONFIGURATION WORD 2 (see PIC24 Family Reference Manual 24.1)
#pragma config I2C1SEL = PRI       // I2C1 Pin Location Select (Use default SCL1/SDA1 pins)
#pragma config IOL1WAY = OFF       // IOLOCK Protection (IOLOCK may be changed via unlocking seq)
#pragma config OSCIOFNC = ON       // Primary Oscillator I/O Function (CLKO/RC15 functions as I/O pin)
#pragma config FCKSM = CSECME      // Clock Switching and Monitor (Clock switching is enabled, 
                                       // Fail-Safe Clock Monitor is enabled)
#pragma config FNOSC = FRCPLL      // Oscillator Select (Fast RC Oscillator with PLL module (FRCPLL))



void pic24_init(); // 16MHz clock and digital pins






void pic24_init(){
    AD1PCFG = 0xffff;   //sets all pins to digital I/O
    CLKDIVbits.RCDIV=0; // set frequency to 16 MHz 
}


int main(void) {
    pic24_init();
    lcd_init();
  
    // print a letter to the screen
//    lcd_setCursor(4,0);
//    lcd_printChar('a');
    
    
    // print hello world to screen demo
    
//    lcd_setCursor(0,0);
//    lcd_printStr("Hello,");
//    lcd_setCursor(0,1);
//    lcd_printStr("World!");
    
    //have text float accross the screen
    
    
    int counter=0;
    while (1){
        if(counter==0){ // intialize the sceen
            lcd_setCursor(0,0);
            lcd_printStr("Hello,");
            lcd_setCursor(0,1);
            lcd_printStr("World!");
        }
        
        if(counter%8 != 0){
            delay(100);
            shiftRight();
        }
        else{
            lcd_cmd(0b00000001); // Clear Display
            lcd_setCursor(0,0);
            lcd_printStr("Hello,");
            lcd_setCursor(0,1);
            lcd_printStr("World!");
        }
        counter++;
        
    }
    return 0;
}
