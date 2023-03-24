#include "xc.h"
#include "wodzinski_lab3_util.h"

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



void init7seg(void)
{
    // bp stuff
    CLKDIVbits.RCDIV = 0;//Set RCDIV=1:1 (default 2:1) 32MHz or FCY/2=16M
    AD1PCFG = 0x9fff;   //sets all pins to digital I/O
    TRISB = 0x0003;    //set pins RB2-RB11  to output,
    LATB = 0xF3FF;    //sets all of lat B to high except the common anodes
                     //0b1111 0011 1111 1111 = f 3 F F  
}


void cleardisplay(){
    LATB = 0xF3FF;
}

    //where myChar is the character being displayed
    //where myDigit indicates LEFT (1) or RIGHT (0)
    // or with a 0 doesn't change output, but will with a 1
void showChar7seg (char myChar, int CharacterNum){
        
    if(CharacterNum){          //display to left digit set pin13/RB 11 to high
        LATB=(LATB | 0x0800); // this line will connect the common anode pin 13 to high
    }
        
    if(!CharacterNum){        // we want to display to the right digit
        LATB=(LATB | 0x0400);// set pin 14 or RB10 to high
    }
    
    // anding with a 0 turns specific bits off, but with a 1 does nothing
    if(myChar=='a'){
        LATB=(LATB & 0xFDFF); //RB9
    }
    else if(myChar=='B'){
        LATB=(LATB & 0xFEFF); //RB8
    }
    else if(myChar=='c'){
        LATB=(LATB & 0xFF7F); //RB7
    }
    else if(myChar=='D'){
        LATB=(LATB & 0xFFBF); //RB6
    }
    else if(myChar=='e'){
        LATB=(LATB & 0xFFDF); //RB5
    }
    else if(myChar=='f'){
        LATB=(LATB & 0xFFEF); //RB4
    }
    else if(myChar=='g'){
        LATB=(LATB & 0xFFF7); //RB3
    }
    else if(myChar=='.'){
        LATB=(LATB & 0xFFFB); //RB2
    }   

    if (myChar == '0'){
        write_0(CharacterNum);
    }
    else if (myChar == '1'){
        write_1(CharacterNum);
    }
    else if (myChar == '2'){
        write_2(CharacterNum);
    }
    else if (myChar == '3'){
        write_3(CharacterNum);
    }
    else if (myChar == '4'){
        write_4(CharacterNum);
    }
    else if (myChar == '5'){
        write_5(CharacterNum);
    }
    else if (myChar == '6'){
        write_6(CharacterNum);
    }
    else if (myChar == '7'){
        write_7(CharacterNum);
    }
    else if (myChar == '8'){
        write_8(CharacterNum);
    }
    else if (myChar == '9'){
        write_9(CharacterNum);
    }
    else if (myChar == 'A'){
        write_A(CharacterNum);
    }
    else if (myChar == 'b'){
        write_b(CharacterNum);
    }
    else if (myChar == 'C'){
        write_C(CharacterNum);
    }
    else if (myChar == 'd'){
        write_d(CharacterNum);
    }
    else if (myChar == 'E'){
        write_E(CharacterNum);
    }
    else if (myChar == 'F'){
        write_F(CharacterNum);
    }
}
void write_dp(int CharacterNum){
    showChar7seg('.',CharacterNum);
}
void write_1(int CharacterNum){
    showChar7seg('B',CharacterNum);
    showChar7seg('c',CharacterNum);
}

void write_2(int CharacterNum){
    showChar7seg('a',CharacterNum);
    showChar7seg('B',CharacterNum);
    showChar7seg('g',CharacterNum);
    showChar7seg('e',CharacterNum);
    showChar7seg('D',CharacterNum);
}

void write_3(int CharacterNum){
    write_1(CharacterNum);
    showChar7seg('D',CharacterNum);
    showChar7seg('a',CharacterNum);
    showChar7seg('g',CharacterNum);
}

void write_4(int CharacterNum){
    write_1(CharacterNum);
    showChar7seg('g',CharacterNum);
    showChar7seg('f',CharacterNum);
}

void write_5(int CharacterNum){
    showChar7seg('a',CharacterNum);
    showChar7seg('f',CharacterNum);
    showChar7seg('g',CharacterNum);
    showChar7seg('c',CharacterNum);
    showChar7seg('D',CharacterNum);
}

void write_6(int CharacterNum){
    showChar7seg('f',CharacterNum);
    showChar7seg('e',CharacterNum);
    showChar7seg('g',CharacterNum);
    showChar7seg('c',CharacterNum);
    showChar7seg('D',CharacterNum);
}

void write_7(int CharacterNum){
    showChar7seg('a',CharacterNum);
    write_1(CharacterNum);
}

void write_8(int CharacterNum){
    write_6(CharacterNum);
    showChar7seg('a',CharacterNum);
    showChar7seg('B',CharacterNum);
}

void write_9(int CharacterNum){
    write_4(CharacterNum);
    showChar7seg('a',CharacterNum);
}

void write_0(int CharacterNum){
    write_7(CharacterNum);
    showChar7seg('f',CharacterNum);
    showChar7seg('e',CharacterNum);
    showChar7seg('D',CharacterNum);
}

void write_A(int CharacterNum){
    write_7(CharacterNum);
    showChar7seg('f',CharacterNum);
    showChar7seg('e',CharacterNum);
    showChar7seg('g',CharacterNum);
}

void write_b(int CharacterNum){
    write_6(CharacterNum);
}

void write_C(int CharacterNum){
    showChar7seg('f',CharacterNum);
    showChar7seg('e',CharacterNum);
    showChar7seg('a',CharacterNum);
    showChar7seg('D',CharacterNum);
}

void write_d(int CharacterNum){
    write_1(CharacterNum);
    showChar7seg('g',CharacterNum);
    showChar7seg('e',CharacterNum);
    showChar7seg('D',CharacterNum);
}

void write_E(int CharacterNum){
    write_C(CharacterNum);
    showChar7seg('g',CharacterNum);
}

void write_F(int CharacterNum){
    showChar7seg('f',CharacterNum);
    showChar7seg('e',CharacterNum);
    showChar7seg('a',CharacterNum);
    showChar7seg('g',CharacterNum);
}

void display_test(){
    
    write_dp(0); // right digit
    delay(250);
    cleardisplay();
    write_dp(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_0(0); // right digit
    delay(250);
    cleardisplay();
    write_0(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_1(0); // right digit
    delay(250);
    cleardisplay();
    write_1(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_2(0); // right digit
    delay(250);
    cleardisplay();
    write_2(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_3(0); // right digit
    delay(250);
    cleardisplay();
    write_3(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_4(0); // right digit
    delay(250);
    cleardisplay();
    write_4(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_5(0); // right digit
    delay(250);
    cleardisplay();
    write_5(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_6(0); // right digit
    delay(250);
    cleardisplay();
    write_6(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_7(0); // right digit
    delay(250);
    cleardisplay();
    write_7(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_8(0); // right digit
    delay(250);
    cleardisplay();
    write_8(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_9(0); // right digit
    delay(250);
    cleardisplay();
    write_8(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_A(0); // right digit
    delay(250);
    cleardisplay();
    write_A(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_b(0); // right digit
    delay(250);
    cleardisplay();
    write_b(1);//  left digit
    delay(250);
    cleardisplay();
    
    write_C(0); // right digit
    delay(250);
    cleardisplay();
    write_C(1);//  left digit
    delay(250);
    cleardisplay();
    
    
    write_d(0); // right digit
    delay(250);
    cleardisplay();
    write_d(1);//  left digit
    delay(250);
    cleardisplay();
     
    
    write_E(0); // right digit
    delay(250);
    cleardisplay();
    write_E(1);//  left digit
    delay(250);
    cleardisplay();
      
    
    write_F(0); // right digit
    delay(250);
    cleardisplay();
    write_F(1);//  left digit
    delay(250);
    cleardisplay();
}


