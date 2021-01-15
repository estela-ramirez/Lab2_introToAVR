/*	Author: Estela Ramirez Ramirez
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	// = 0xF0, sets hight bits to outputs and low bits to inputs
	// PORTA - write only, PINA - readonly
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
    
   // unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
   // unsigned char tmpC = 0x00; // Temporary variable to hold the output for C
    unsigned char cnt = 0x00;
    unsigned char cntavail = 0x00;
   
while(1) {

        // 1) Read input and 2.) compute
	cnt =( ( PINA & 0x08) >> 3) + ((PINA & 0x04) >> 2) + ((PINA & 0x02) >> 1) + (PINA & 0x01) ;           

        cntavail = (4-cnt); 
        // 3) Write output
		
        PORTC = cntavail;
}
return 0;
}
