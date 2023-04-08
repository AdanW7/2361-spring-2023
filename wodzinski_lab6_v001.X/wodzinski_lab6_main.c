/*
 * File:   wodzinski_lab6_main.c
 * Author: adan
 *
 * Created on April 6, 2023, 7:57 PM
 */


#include "xc.h"
#include <stdio.h>
#include "lcd_library.h"
#include "circular_buffer.h"


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
void adc_init(); // initialize the adc on the pic24
void timer1_init(); // initialize a timer for 100 ms




void pic24_init(){
    AD1PCFG = 0xffff;   //sets all pins to digital I/O
    CLKDIVbits.RCDIV=0; // set frequency to 16 MHz 
}

void adc_init(){

    TRISAbits.TRISA0 = 1; // should be input by default, but just for safety..
    
    AD1PCFGbits. PCFG0 = 0; // setup I/O
    
    AD1CON2bits.VCFG = 0b000;// Use AVDD (3.3V) and AVSS (OV) as max/min
    AD1CON3bits.ADCS = 0b1;  // You want TAD >= 75ns (Tcy 62.5ns)
    AD1CON1bits.SSRC = 0b010;// sample on timer3 events
    AD1CON3bits.SAMC = 0b1;  // atleast one auto sample time bit
    AD1CON1bits.FORM = 0b00; // get result as an unsigned int
    AD1CON1bits.ASAM = 0b1 ; // Sampling begins immediately after last conversion completes; 
    AD1CON2bits.SMPI = 0b0 ; // Interrupts at the completion of conversion for each sample/convert sequence
    AD1CON1bits.ADON = 1;    // turn on the adc
    
    _AD1IF = 0;              // Clear IF
    _AD1IE = 1;              // Enable interrupt
    
    TMR3 = 0;                // Clear timer 3
    T3CON = 0;
    T3CONbits.TCKPS = 0b10;  //1:64
    PR3 = 15624;             // 15624:k=16 times per second, 1952:k=128 times per second
    T3CONbits.TON = 1;

}

void timer1_init(){
    
    T1CON = 0;
    TMR1 = 0;
    T1CONbits.TCKPS = 0b10;  //1:64
    PR1 = 24999;             //100ms period
    T1CONbits.TON = 1;
    _T1IF = 0;
    _T1IE = 1;
    

}

void __attribute__((__interrupt__, __auto_psv__)) _ADC1Interrupt(void) {
    IFS0bits.AD1IF = 0;
        
    int adValue = ADC1BUF0;
    putVal(adValue);
    
}
void __attribute__((__interrupt__, __auto_psv__)) _T1Interrupt(void) {
    _T1IF = 0; 
    TMR1 = 0;
    char adStr[20];
    lcd_setCursor(0,0);
    sprintf(adStr, "%6.4f V", (3.3/1024)*ADC1BUF0);  // x.xxxx V?
                                                     // 6.4 in the format string ?%6.4f? means 6 placeholders for the whole
                                                     // floating-point number, 4 of which are for the fractional part.
    lcd_printStr(adStr);
    lcd_setCursor(0,1);
    lcd_printStr("Attempt?");
}



int main(void) {
    pic24_init();
    lcd_init();
    adc_init();
    timer1_init();
    initBuffer();
    
    while(1);
    
    return -1;
}
