/*
 * File:   wodzinski_lab4_main.c
 * Author: adan
 *
 * Created on March 2, 2023, 8:13 PM
 */


#include "xc.h"
#include "wodzinski_lab4_asmlib.h"
#include "wodzinski_lab4_utility.h"
#include <stdlib.h>
//
// CW1: FLASH CONFIGURATION WORD 1 (see PIC24 Family Reference Manual 24.1)
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
//

#define buff_size 2
void setup();

void init_servo();
void set_servo(double val);

void init_button();

volatile unsigned int overflow = 0;
volatile unsigned int press=0;
volatile unsigned long int time_current_click = 0;
volatile unsigned long int time_click1=0;
volatile unsigned long int time_click2=0;
volatile unsigned long int time_click3=0;


void setup(){
    
    AD1PCFG = 0xffff;   //sets all pins to digital I/O
    CLKDIVbits.RCDIV=0; // set frequency to 16 MHz 
    TRISBbits.TRISB8 = 1; // pin input for our button;
}

/* map output compare to pin rb/rp6
 * initialize timer3  and use it for output compare clock source
 * settings for timer3 were obtained in prelab video
 * 
 */
void init_servo(){

    TRISBbits.TRISB6=0; // set pin b 6 to output
    // map output compare to pin b6
    __builtin_write_OSCCONL(OSCCON & 0xbf); // forces pin6 to be a 0 on OSCON (unlock)
    RPOR3bits.RP6R = 18;  // Use Pin RP6/RB6 for Output Compare 
    __builtin_write_OSCCONL(OSCCON | 0x40); // forces pin6 to be a 0 on OSCON (lock)
    
    
    OC1CON = 0;
    OC1CONbits.OCTSEL = 0b1; // use timer3 is the clock source for output compare
    OC1CONbits.OCM = 0b110;

    T3CON = 0;
    T3CONbits.TCKPS = 0b01; //1:8 prescaler
    TMR3=0;
    PR3 = 40000-1; // 20 ms
    T3CONbits.TON = 1; //turn on the timer3
    
    // below is given in lab manual
    OC1R = 1234;   // servo start position. We won't touch OC1R again
    OC1RS = 1234;  // We will only change this once PWM is turned on
  
}

/*
 * set servo to an angle, 
 * a larger value results in a longer pulse
 * implemented through output compare
 * the range of val is 0 to PR3 (40000-1)
 */
void set_servo(double val){
    // we can consider the val as the duty in ms
    // to achieve this we must first make val /=20 because we have a period of 20 ms
    // then multiply the final result by pr3 to make our ratio properly match the bounds 0?val?pr3
    val=(val/20)*PR3;
    OC1RS=val; // shadow register
}

/*
 * initialize pin connected to the button as an input and adds a pull up resistor 
 * to provide a default read value. then map that pin to the input capture peripheral 
 * to trigger a section of code immediately when a button is pressed 
 * 
 * also initialize timer2 for input capture
 * all values for timer2 settings were gotten from the prelab video 
 */
void init_button(){
    TRISBbits.TRISB8= 1; // rb8 is input pin for button
    CNPU2bits.CN22PUE=1; //Pull up resistor on RB8 (button)
    
    __builtin_write_OSCCONL(OSCCON & 0xbf); // (unlock)
    RPINR7bits.IC1R = 8;  // Use Pin RP8/RB for input Compare 1 
    __builtin_write_OSCCONL(OSCCON | 0x40); // (lock)
    
    T2CON = 0x0010;
    T2CONbits.TCKPS=0b11; // prescaler of 1:256 //
    PR2=62499; // 1 second period
    TMR2=0;
    _T2IE=1; // enable interupt 
    _T2IF=0; // set the interrupt flag to 0
    T2CONbits.TON=1;
    
    IC1CON = 0; 
    IC1CONbits.ICTMR = 1; // ic1 uses tmr2
    IEC0bits.IC1IE = 1; // enable interrupt on ic1
    IC1CONbits.ICI = 0b00; // interrupt on every capture
    IC1CONbits.ICM = 0b010; // falling edge mode
    _IC1IF = 0;
}

void __attribute__((interrupt, auto_psv)) _T2Interrupt(void) {
    _T2IF = 0; // turn the interrupt flag back to 0
    overflow++; // and increase the overflow by one
}



/*
 * below is my first attempt at an input capture interrupt
 */
void __attribute__((interrupt, auto_psv)) _IC1Interrupt(void) {

    _IC1IF = 0;
    
    time_current_click = (unsigned long int)((unsigned long int)IC1BUF + (unsigned long int)overflow*(PR2+1));
    
    if(time_current_click>125){ //to achieve a 2ms debounce delay must find (2/1000)(PR2+1)=125
        TMR2 = 0; 
        overflow = 0;
        time_click3= time_click2;
        time_click2 = time_click1;
        time_click1 = time_current_click;

        if(!press&&(time_click1-time_click3<(PR2/4))&& time_click3 !=0){ // if three inputs in less then are equal to .25 second
            set_servo(1.2);
            press=1;
            
        } 
    }
}

int main(void) {
    setup();
    init_servo();
    init_button();

    // prelab led loop
    while(0){
        set_servo(5); // 25% duty cycle
        delay(1000); // wait 1 sec
        set_servo(15); //75 %
        delay(1000);
    }
    
    // back and forth servo every second: automated just tests how the servo moves
    while(0){
        set_servo(1.2); // -54 angle
        delay(1000); // wait 1 sec
        set_servo(1.8); //+54 degree
        delay(1000);

    } 
    


    // make a double click demo demo
    set_servo(1.8);
    while(0){
        
        delay(2); // 2 ms delay to avoid button debouncing
        
        while(_IC1IF == 0){
            if (overflow>=2){
                set_servo(1.8);
            }
        }
        IFS0bits.IC1IF=0;
        
        time_current_click = (TMR2+((unsigned long int)(PR2+1)*overflow));
        TMR2 = 0; 
        overflow = 0;
        time_click3= time_click2;
        time_click2 = time_click1;
        time_click1 = time_current_click;
            
        if((time_click1-time_click2<(PR2/2))&& time_click2 !=0){ // if two inputs in less then are equal to 0.5 seconds
            set_servo(1.2);
        } 
    }
    
    // double press using interrupts
    while(1){
        if (overflow>=2){
                set_servo(1.8);
                time_click1=0;
                press=0;
        }
    }
    
    return 0;
}
