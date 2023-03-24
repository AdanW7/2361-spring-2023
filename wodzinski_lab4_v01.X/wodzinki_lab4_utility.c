#include "xc.h"
#include "wodzinski_lab4_asmlib.h"

void delay(int delay);
void delay(int delay_in_ms){
    int i;
    for (i =0;i<delay_in_ms;i++){
        wait_1ms();
    }
    return;
}

