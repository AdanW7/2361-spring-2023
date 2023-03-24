#include "xc.h"
#include "wodzinski_lab3_util.h"

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

void initKeyPad(void);
int readKeyPad(void);
int colTester(void);

void initKeyPad(){

    //pins 1-4 columns, initial high
    // pins 5-8 rows, initial high, check each row for low by setting each low.
    AD1PCFG = 0x9fff;   //sets all pins to digital I/O
    TRISB= 0x0003;    //set pins RB12-15 to output
    TRISA= 0x000F; // we only care about pins RA0:RA3 (pins 1-4)  
    CNPU1bits.CN2PUE = 1;  // turn on pull-up for micro-pin:2/RA0  /keypad pin 1
    CNPU1bits.CN3PUE = 1;  // turn on pull-up for micro-pin:3/RA1  /keypad pin 2
    CNPU2bits.CN30PUE = 1; // turn on pull-up for micro-pin:9/RA2  /keypad pin 3
    CNPU2bits.CN29PUE = 1; // turn on pull-up for micro-pin:10/RA3 /keypad pin 4
    
}

int colTester(){
    unsigned int Portamask=0x0007;
    int i;
    for (i = 0; i < 4; i++) {
        if ((PORTA | Portamask) < 0x000F){ // we have a 0 and are grounded, we have a hit
            return i;
        }
        else{
            if(i==0){
            Portamask = (Portamask >> 1); // shift the 0 over to the next bit/ test the next col
            PORTA= PORTA|0x0008;
            }
            if(i==1){
            Portamask = (Portamask >> 1); // shift the 0 over to the next bit/ test the next col
            PORTA= PORTA|0x0004;
            }
            if(i==2){
            Portamask = (Portamask >> 1); // shift the 0 over to the next bit/ test the next col
            PORTA= PORTA|0x0002;
            }
            
                                         
        }
    }    
    return -1;
}

int readKeyPad(){
    int colnum=-1;
    unsigned int matrix[4][4]={
        {1,2,3,10}, // col 1
        {4,5,6,11}, // col 2
        {7,8,9,12}, // col 3
        {14,0,15,13}  // col 4
    };
    
    int keyPressed=-1; // arbitrary num that shouldn't happen at all
    
    
    //reset all the rows to high
    LATB=LATB | 0xF000; //1111 0000 0000 0000 
    // set row 1 to low while 2,3,4 to high
    LATB=LATB & 0x7FFF; //0111 1111 1111 1111 , pin 5 is set low 
    
    if (colTester()!=-1){
        colnum=colTester();
        keyPressed=matrix[0][colnum];
        return keyPressed;
    }
    
    if(keyPressed==-1){
        //reset all the rows to high
        LATB=LATB | 0xF000; //1111 0000 0000 0000 
        // set row 2 to low while 1,3,4 to high
        LATB=LATB & 0xBFFF; //1011 1111 1111 1111 pin 6 is set low
        if (colTester()!=-1){
            colnum=colTester();
            keyPressed=matrix[1][colnum];
            return keyPressed;
        }
    }
    
    if(keyPressed==-1){
        //reset all the rows to high
        LATB=LATB | 0xF000; //1111 0000 0000 0000     
        // set row 3 to low while 1,2,4 to high
        LATB=LATB & 0xDFFF; //1101 1111 1111 1111 pin 7 set low
        if (colTester()!=-1){
         colnum=colTester();   
        keyPressed=matrix[2][colnum];
        return keyPressed;
        }
    }
    
    if(keyPressed==-1){
        //reset all the rows to high
        LATB=LATB | 0xF000; //1111 0000 0000 0000 
        // set row 4 to low while 1,2,3 to high
        LATB=LATB & 0xEFFF; //1110 1111 1111 1111 pin 8 set low
        if (colTester()!=-1){
            colnum=colTester();
            keyPressed=matrix[3][colnum];
            return keyPressed;
        }
    }
    return -1;
}

