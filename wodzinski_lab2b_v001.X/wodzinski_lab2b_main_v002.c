/* 
 * File:   wodzisnki_lab2b_main_v001.c
 * Author: 
 * 
 *
 * Created on February 6, 2023, 8:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
# include "stdint.h"

#include "xc.h"
#include "wodzinski_lab2b_asmLib_v001.h"

// boiler plate stuff

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

#define PERIOD 5

void delay(int delay_in_ms){
    for (int i =0;i<delay_in_ms;i++){
        wait_1ms();
    }
    return;
}


void setup(void)
{
    // bp stuff
    CLKDIVbits.RCDIV = 0;  //Set RCDIV=1:1 (default 2:1) 32MHz or FCY/2=16M
    AD1PCFG = 0x9fff;            //sets all pins to digital I/O
    TRISA = 0b1111111111111110;  //set pin RA0 to output, 
    
    
    LATA = 0x0000;               // since i use a start low end low pulse i actually need to clear lata
}

void prelab_loop() {

    //red
    write_0();
    write_0();
    write_0();
    write_0();
    write_0();
    write_0();
    write_0();
    write_0();

    //green
    write_0();
    write_0();
    write_0();
    write_0();
    write_0();
    write_0();
    write_0();
    write_0();
    
    // blue
    write_1();
    write_1();
    write_1();
    write_1();
    write_1();
    write_1();
    write_1();
    write_1();
    
    // after we send color we need to clear lata and reset
    LATA = 0x0000;
    wait_100us();
}


unsigned long int packColor(unsigned char Red, unsigned char Grn, unsigned char Blu){
    //0x00(red)(red)(green)(green)(blue)(blue)
    return ((long) Red << 16) | ((long) Grn << 8) | ((long) Blu);
}
unsigned char getR(unsigned long int RGBval){ 
   // will need to type cast RGBval to from an unsigned 32 bit int to an unsigned to char
    return (unsigned char) (RGBval >> 16); // shift past blue and green to see red
}
unsigned char getG(unsigned long int RGBval){
     return (unsigned char) (RGBval >> 8); // shift past blue to see green
}
unsigned char getB(unsigned long int RGBval){
    return (unsigned char) (RGBval); // requires no shifting to see blue, is the last 8 bits 
}

void writePacCol(unsigned long int PackedColor){
    // will need to type cast packed color to int

    int r = (int) getR(PackedColor);
    int g = (int) getG(PackedColor);
    int b = (int) getB(PackedColor);
    
    writeColor(r, g, b);
}

void writeColor(int r, int g, int b) {
    
    for (int i = 7; i >= 0; i--) {
        // shift red by i, if its a one then then write one,
        // else we need to write 0, same for green and blue
        // data should go in least significant bit to most
        if ((r >> i) & 1) {
            write_1();
        }
        else write_0();
    }
    for (int i = 7; i >= 0; i--) {
        if ((g >> i) & 1) {
            write_1();
        }
        else write_0();
    }
    for (int i = 7; i >= 0; i--) {
        if ((b >> i) & 1) {
            write_1();
        }
        else write_0();
    }
    LATA = 0x0000;
    wait_100us();
    return;
}

unsigned long int gradient(unsigned char frampos){ 
    // based off of adafruit wheel function
    // hard coded to give a red to blue to red gradient
    
    if(frampos < 63) {
        return packColor(255 , 0, frampos * 4);//red purple
    }
    
    if(frampos < 127) {
        frampos -= 63;
        return packColor(255 - frampos * 4, 0, 255); //purple to blue
    }
    if(frampos < 191) {
        frampos -= 127;
        return packColor( frampos * 4, 0,255);//blue to purple
    }
    if(frampos < 255) {
        frampos -= 191;
        return packColor(255, 0, 255 - frampos * 4); //purple to red
    }
}

unsigned long int Wheel(unsigned char WheelPos) {
    WheelPos = 255 - WheelPos;
    // all lower code was taken almost entirely from the 
    //adafruit wheel library example provided in the manual
    if(WheelPos < 85) {
        return packColor(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if(WheelPos < 170) {
        WheelPos -= 85;
        return packColor(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return packColor(WheelPos * 3, 255 - WheelPos * 3, 0);
}

int main(void) {
    
    setup();
    unsigned long int color_test; // used for wheel
    unsigned long int gradient_test; // used for gradient test
    unsigned int byteFrame = 255;
    int swap = 0; // will be used to swap the flow across the color spectrum
    
    while (1){
        
        //test wheel function
//        color_test = Wheel(byteFrame);
//        writePacCol(color_test);
        
        //gradient test
        gradient_test=gradient(byteFrame);
        writePacCol(gradient_test);
        
        // if frame at 255 set swap to 0
        // then decrease frame by one every iteration
        // once frame hits 0 set swap to one
        // and as long as swap is one increase byte until 255...
        
        if (byteFrame == 255){
            swap = 0;
        }
        else if (byteFrame == 0){
            swap = 1;
        }
        
        
        if (swap) {
            byteFrame++;
        }
        else {
            byteFrame--;
        }

       //writeColor(00000000,00000000,00000000); // writeColor test
//        prelab_loop(); // should emit a solid blue light
        delay(PERIOD);
    }
    return 0;
}
