.include "xc.inc"          ; required "boiler-plate" (BP)

;the next two lines set up the actual chip for operation - required
config __CONFIG2, POSCMOD_EC & I2C1SEL_SEC & IOL1WAY_OFF & OSCIOFNC_ON & FCKSM_CSECME & FNOSC_FRCPLL & SOSCSEL_LPSOSC & WUTSEL_FST & IESO_OFF
config __CONFIG1, WDTPS_PS1 & FWPSA_PR32 & WINDIS_OFF & FWDTEN_OFF & BKBUG_ON & GWRP_ON & GCP_ON & JTAGEN_OFF

    .bss        ; put the following labels in RAM
counter:
    .space 2    ; a variable that takes two bytes (we won?t use
                ; it for now, but put here to make this a generic
                ; template to be used later).
stack:
    .space  32  ; this will be our stack area, needed for func calls

.text           ; BP (put the following data in ROM(program memory))

;because we are using the C compiler to assemble our code, we need a "_main" label
;somewhere. (There's a link step that looks for it.)
.global _main               ;BP
;your functions go here

_main:

    bclr    CLKDIV,#8                 ;BP
    nop
    ;; --- Begin your main program below here ---

    mov     #0x9fff,w0  
    mov     w0,AD1PCFG            ; Set all pins to digital mode
    mov     #0b1111111111111110,w0  
    mov     w0,TRISA            ; set pin RA0 to output
    mov     #0x0001,w0  
    mov     w0,LATA            ; set pin RA0 high
    clr	    LATA	       ;  implement a start low end low for ILED
    
    foreverLoop:
	;red
	call	write_0
	call	write_0
	call	write_0
	call	write_0
	call	write_0
	call	write_0
	call	write_0
	call	write_0
	
	;green
	call	write_0
	call	write_0
	call	write_0
	call	write_0
	call	write_0
	call	write_0
	call	write_0
	call	write_0
	
	;blue
	call	write_1
	call	write_1
	call	write_1
	call	write_1
	call	write_1
	call	write_1
	call	write_1
	call	write_1
	
	; after we send color we need to clear the lata and have a reset delay
	clr LATA;
	call delay_100us;
	bra     foreverLoop

	
    write_0: 
	    
	inc	LATA	; this cycle count will be figuered into next write
	repeat #3	;
	nop
	clr     LATA	; set pin RA0 low = 1 cycle
	; takes one cycle to become high then is high for 6 cycles
	
	
	;can be low for 14 cycles but must account for return and call of next write
	;14-5=9
	;must also account for cycle to inc lata in next write
	;9-1=8 cycles left in write_0
	
	repeat #6
	nop 
	return; 3 cycles for return
	
    write_1: ;
	inc	LATA; this cycle count is figuered for the next write
	; be high for 11 cycles
	repeat #8     ; 9 cycles
	nop	     ; 1 cycle   
	clr	LATA ; 1 cycle
	
	
	; 9 cycle low
	; 1 cycle to inc in next write
	; 3 cycles for return
	; 2 cycles for call to next write 
	; 9-1-3-2=9-6=3
	repeat #1
	nop
	return ; 3 cycles for return
	
	
	
	
    write_bit_stream:
			; 2 cycles for function call, 2 cycles after the brach to foreverloop
       repeat #14       ; 1+3 cycles from the end of the fucntion
       nop              ;1+3+2+2+16=24

	       ; total 24 cycles high

       clr     LATA   ; set pin RA0 low = 1 cycle

       repeat #29        ; 1 
       nop              ; 29+1 cycles to execute NOP 30 times

	       ; total 32 cycles low 1+1+1+29=32

       inc     LATA    ; set pin RA0 high = 1 cycle

       return           ; 3 cycles for the return 

       delay_100us:
	    ; for 100 us need 1,600 clock cycle delays
	    ; 2 cycles for function call

	    repeat #1594    ; 1 cycle 
	    nop          ;1593+1 cycles to execute NOP 1594 times 

	    return ; 3 cycles for the return

       delay_1ms:
	    ; for 1 ms need 16,000 clock cycle delays
	    ; 2 cycles for function call

	    repeat #15993    ; 1 cycle
	    nop          ;15993+1 cycles to execute NOP 15994 times

	    return ; 3 cycles for the return


       .end


