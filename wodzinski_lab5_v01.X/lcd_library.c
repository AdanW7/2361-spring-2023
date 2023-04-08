#include "xc.h"
#include "string.h"
#include "lcd_library.h"



void delay(unsigned int delay_ms){
    while(delay_ms-- > 0){
        asm("repeat #15998");
        asm("nop");
    }
}

void lcd_cmd(char Package){
    
    I2C2CONbits.SEN = 1; // begin start sequence
    while(I2C2CONbits.SEN==1); // SEN will clear when Start Bit is complete
    IFS3bits.MI2C2IF=0; // clear interrupt flag
    
    //send address and write command
    I2C2TRN = 0b01111100; // 8-bits consisting of the slave address and the R/nW bit
    while(IFS3bits.MI2C2IF==0);
    IFS3bits.MI2C2IF=0;
    
    
    //send high byte (always 0x00)
    I2C2TRN = 0b00000000; // 8-bits consisting of control byte
    while(IFS3bits.MI2C2IF==0);
    IFS3bits.MI2C2IF=0;
    
    
    // send Package
    I2C2TRN = Package; // 8-bits consisting of the data byte
    while(IFS3bits.MI2C2IF==0);
    IFS3bits.MI2C2IF=0;
    
    // send stop
    I2C2CONbits.PEN = 1; // begin stop sequence
    while(I2C2CONbits.PEN==1);// PEN will clear when Stop bit is complete
}

void lcd_init(void) { 
    // then entirety of the following function is derived from provided code in slide show
    // Data sheet page 153 has a table that gives I2C2BRG val for 100k using 16MHz clock
    I2C2BRG = 0x9D;         // set to a clock frequency of 100kHz,
    IFS3bits.MI2C2IF = 0;  // clear the interrupt flag
    I2C2CONbits.I2CEN = 1; // enable I2c mode 

    
    delay(50);
    lcd_cmd(0b00111000); // function set, normal instruction mode
    lcd_cmd(0b00111001); // function set, extended instruction mode
    lcd_cmd(0b00010100); // interval osc
    lcd_cmd(0b01110000); // contrast C3-C0
    lcd_cmd(0b01011110); // Ion, Bon, C5-C4
    lcd_cmd(0b01101100); // follower control

    
    delay(200);
    lcd_cmd(0b00111000); // function set, normal instruction mode
    lcd_cmd(0b00001100); // Display On
    lcd_cmd(0b00000001); // Clear Display
    delay(1);
}

void lcd_setCursor(char x, char y) {
    lcd_cmd((0x40*y + x) + 0b10000000);
    // The MSB is always 1 in the instruction code for the ?Set DDRAM address? command.
}

void lcd_printChar(char Package){
    
    I2C2CONbits.SEN = 1; // begin start sequence
    while(I2C2CONbits.SEN==1); // SEN will clear when Start Bit is complete
    IFS3bits.MI2C2IF=0; // clear interrupt flag
    
    //send address and write command
    I2C2TRN = 0b01111100; // 8-bits consisting of the slave address and the R/nW bit
    while(IFS3bits.MI2C2IF==0);
    IFS3bits.MI2C2IF=0;
    
    
    //send high byte (always 0x00)
    I2C2TRN = 0b01000000; // 8-bits consisting of control byte  /w RS=1
    while(IFS3bits.MI2C2IF==0);
    IFS3bits.MI2C2IF=0;
    
    
    // send Package
    I2C2TRN = Package; // 8-bits consisting of the data byte
    while(IFS3bits.MI2C2IF==0);
    IFS3bits.MI2C2IF=0;
    
    // send stop
    I2C2CONbits.PEN = 1; // begin stop sequence
    while(I2C2CONbits.PEN==1);// PEN will clear when Stop bit is complete
}

void shiftRight() {
    lcd_cmd(0b00011100);
}

void shiftLeft() {
    lcd_cmd(0b00011000);
}
/*
 * follow the same premise of print char but use for loop to iterate 
 * thought the c-string array and send all of the letters to the screen
 */ 
void lcd_printStr(const char cString[]) {
    int size = strlen(cString);
    
    I2C2CONbits.SEN = 1;        //Start
        while(I2C2CONbits.SEN);
    IFS3bits.MI2C2IF=0;
    
    I2C2TRN= 0b01111100;        //Slave address and R/W bit
    while(!IFS3bits.MI2C2IF);
    IFS3bits.MI2C2IF=0;
    
    int i;
    for (i=0; i < size - 1; i++) {
        I2C2TRN = 0b11000000;       //Control byte, RS = 1
        while(!IFS3bits.MI2C2IF);
        IFS3bits.MI2C2IF=0;
        I2C2TRN = cString[i];          //Data byte
        while(!IFS3bits.MI2C2IF);
        IFS3bits.MI2C2IF=0;
    }
    
    I2C2TRN = 0b01000000;       //Control byte, RS = 1
    while(!IFS3bits.MI2C2IF);
    IFS3bits.MI2C2IF=0;
    
    I2C2TRN = cString[size-1];          //Data byte
    while(!IFS3bits.MI2C2IF);
    IFS3bits.MI2C2IF=0;
    
    I2C2CONbits.PEN = 1;        //Stop
    while(I2C2CONbits.PEN);
}
