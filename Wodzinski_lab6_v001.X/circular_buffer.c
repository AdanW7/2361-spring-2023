
#include "xc.h"

#define BUFSIZE 1024
#define NUMSAMPLES 128

int adc_buffer[BUFSIZE];
unsigned int buffer_index =0; // i use unsigned because i intentionally want the ability to overflow backwards




void initBuffer(); // make all of values in the buffer 0
void putVal(int);  // add a new value to the buffer
int get_avg();     // average all buffer values

void initBuffer(){
    int i;
    for(i=0;i<BUFSIZE;i++){
        adc_buffer[i]=0;
    }
}
void putVal(int ADCvalue) {
    adc_buffer[buffer_index++] = ADCvalue;
    if(buffer_index>=BUFSIZE){
        buffer_index=0;
    }
}

int get_avg(){
    unsigned long int sum = 0;
    int i;
    // get the most recent 128 samples
    for (i = buffer_index; i >buffer_index-NUMSAMPLES; i--) {
        sum += adc_buffer[i];
    }
    return sum/NUMSAMPLES;
}