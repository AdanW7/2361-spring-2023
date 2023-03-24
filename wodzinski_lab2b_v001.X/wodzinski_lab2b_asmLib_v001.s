

.include "xc.inc"

.text  ;BP (put the following data in ROM(program memory))

; This is a library, thus it can *not* contain a _main function: the C file will
; define main().  However, we will need a .global statement to make available ASM
; functions to C code.
; All functions utilized outside of this file will need to have a leading 
; underscore (_) and be included in a comment delimited list below.
.global _write_0, _write_1, _wait_100us, _wait_1ms
    
;1.25 µs period, 20 cycles
;assume starting low   
_write_0:
	
    inc	LATA	; this cycle count will be figuered into next write
    repeat #3	;
    nop
    clr     LATA; set pin RA0 low = 1 cycle
		; takes one cycle to become high then is high for 6 cycles
	
	
		;can be low for 14 cycles but must account 
		;for return and call of next write
		;14-5=9
		;must also account for cycle to inc lata in next write
		;9-1=8 cycles left in write_0
	
    repeat #6
    nop 
    return
    
;1.25 µs period, 20 cycles
;assume starting low
_write_1:
    inc	LATA	; this cycle count is figuered for the next write
		; be high for 11 cycles
    repeat #8   ; 9 cycles
    nop		; 1 cycle   
    clr	LATA	; 1 cycle	
		; 9 cycle low
		; 1 cycle to inc in next write
		; 3 cycles for return
		; 2 cycles for call to next write 
		; 9-1-3-2=9-6=3
    repeat #1
    nop
    return 
    
;1600 cycles total
_wait_100us:
    repeat #1593
    nop
    return
    
;16000 cycles total
_wait_1ms:
    repeat #15993
    nop
    return
  
