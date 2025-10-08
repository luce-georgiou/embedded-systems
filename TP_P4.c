#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "macros.h"
#include <stdio.h>
#include "print.h"
#include "OLED.h"
#include "SH1106.h"
#include "m_usb.h"

// correct phase
// TCCR1A => WGM11 et WGM10
// => COM1A1 COM1A0 COM1B1 COM1B0 1 0 (clear)

// TCCR1B => WGM13 et WGM12 
// => CS12 CS11 CS10 clock 0 0 1

void moteurs() {
    //registre A
    CLRBIT(TCCR1A,WGM11);
    SETBIT(TCCR1A,WGM10);
    SETBIT(TCCR1A,COM1A1);
    CLRBIT(TCCR1A,COM1A0);
    SETBIT(TCCR1A,COM1B1);
    CLRBIT(TCCR1A,COM1B0);

    //registre B
    CLRBIT(TCCR1B,WGM13);
    CLRBIT(TCCR1B,WGM12);
    CLRBIT(TCCR1B,CS12);
    CLRBIT(TCCR1B,CS11);
    SETBIT(TCCR1B,CS10);

    //passer les port en sorties
    SETBIT(DDRB,DDB6);
    SETBIT(DDRB,DDB5);
    SETBIT(DDRB,DDB1);
    SETBIT(DDRB,DDB2);

    //on active
    SETBIT(PORTB,PORTB6);
    SETBIT(PORTB,PORTB5);
    CLRBIT(PORTB,PORTB1);
    CLRBIT(PORTB,PORTB2);
}

// OCR1A = 20, 40

// int main() {
    

//     moteurs();
//     while (true) {
//         for (int i = 0; i < 256; i++)
//         {
//             OCR1A = i;
//             OCR1B = i;
//             _delay_ms(12);
//         } 
//         // OCR1A = 40;
//         clear();
//         printf("TCCR1A : %d\n", TCCR1A);
//         printf("TCCR1B : %d", TCCR1B);
//     }
//     return 0;
// }