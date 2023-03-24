/*
 * File:   wodzinski_lab3_main.c
 * Author: adan
 *
 * Created on February 19, 2023, 2:39 PM
 */


#include <stdio.h>
#include <stdlib.h>
#include "stdint.h"
#include "xc.h"

#include "wodzinski_lab3_display.h"
#include "wodzinski_lab3_keypad.h"
#include "wodzinski_lab3_util.h"
/*
 read key gives values
        {1,2,3,10},
        {4,5,6,11},
        {7,8,9,12},
        {14,0,15,13}
 * 
 *  this actually means:
 * 
        {E,0,F,d},
        {7,8,9,b},
        {4,5,6,C},
        {1,2,3,A}
 * Because i didn't flip along the x axis earlier,
 * I will not go back and edit read keypad to make this easier,
 * I will just address the issue in main, for anyone reading this doc be aware
 * of this if main seems weirdly confusing and/or just wrong
 
 */
int main(void) {
    init7seg();
    initKeyPad();
    int prevkey=-1;
    char leftChar = '\0'; 
    char rightChar = '\0';
    
    // prelab demo
    while (0){
        display_test();
    }

    // final demo
    while(1){
        
        delay(1);
        int key = readKeyPad();
        
        if(key!=prevkey){
            if (key >= 0) { 
                leftChar=rightChar;
                
                if(key==0){
                    rightChar='2';
                }
                if(key==1){
                    rightChar='E';
                }
                if(key==2){
                    rightChar='0';
                }
                if(key==3){
                    rightChar='F';
                }
                if(key==4){
                    rightChar='7';
                }
                if(key==5){
                    rightChar='8';
                }
                if(key==6){
                    rightChar='9';
                }if(key==7){
                    rightChar='4';
                }
                if(key==8){
                    rightChar='5';
                }
                if(key==9){
                    rightChar='6';
                }
                if(key==10){
                    rightChar='d';
                }
                if(key==11){
                    rightChar='C';
                }
                if(key==12){
                    rightChar='b';
                }
                if(key==13){
                    rightChar='A';
                }
                if(key==14){
                    rightChar='1';
                }
                if(key==15){
                    rightChar='3';
                }
            }
            prevkey=key;
            if(rightChar == '\0'){ // we haven't pressed a button yet
                showChar7seg('.',1);
                showChar7seg('.',0);
            }
            else if(leftChar == '\0' && rightChar != '\0'){ // we have pressed one button
                delay(2);
                cleardisplay();
                showChar7seg('.',1);
                showChar7seg('.',0);
                showChar7seg(rightChar,0);
            }
            else{
                     // if we have pressed buttons 2+ times
                cleardisplay();
                showChar7seg('.',1);
                showChar7seg(leftChar,1);
                delay(2);
                cleardisplay();
                showChar7seg('.',0);
                showChar7seg(rightChar,0);
            }   
        }
        // the below code seems redundant but is useful for continuing to show the the nums
        // on the display, while making it so we avoid one but press being counted as two.
        cleardisplay();
        showChar7seg('.',1);
        showChar7seg(leftChar,1);
        delay(2);
        cleardisplay();
        showChar7seg('.',0);
        showChar7seg(rightChar,0);
    }
    return 0;
}


