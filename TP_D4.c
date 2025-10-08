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

volatile int interrupt_count_d = 0;
volatile int interrupt_count_g = 0;
volatile int prev_rightb = 0, prev_righta = 0, prev_leftb = 0, prev_lefta = 0;

ISR(INT6_vect) {
    //pour la droite
    int rightxor = get_bit(PINE,PINE6);
    int rightb   = get_bit(PINF,PINF0);
    int righta   = rightxor^rightb;

    if (righta == prev_rightb) {//forward 
        interrupt_count_d--;
    }
    else if (rightb == prev_righta) { //backward
        interrupt_count_d++;
    }
    prev_rightb = rightb;
    prev_righta = righta;


    
}

ISR(PCINT0_vect) {
    //pour la gauche
    int leftxor = get_bit(PINB,PINB4);
    int leftb = get_bit(PINE,PINE2);
    int lefta = leftxor^leftb;

    if (lefta == prev_leftb) { //forward 
        interrupt_count_g--;
    }
    else if (leftb == prev_lefta) { //backward
        interrupt_count_g++;
    }
    prev_leftb = leftb;
    prev_lefta = lefta;
}

int main() {
    //droit
    SETBIT(EIMSK,INT6); //autorisations
    SETBIT(EICRB,ISC60);
    CLRBIT(EICRB,ISC61);
    
    CLRBIT(DDRE,DDE6); //passage en mode entrée
    CLRBIT(DDRF,DDF0);

    //gauche
    SETBIT(PCICR,PCIE0);
    SETBIT(PCMSK0,PCINT4);

    CLRBIT(DDRB,DDB4);
    CLRBIT(DDRE,DDE2);


    sei();

    prev_righta = 0;
    prev_rightb = get_bit(PINF,PINF0);
    prev_lefta = 0;
    prev_leftb = get_bit(PINE,PINE2);
    // righta = rightxor^rightb;
    // prev_rightb = rightb;

    while (true) {
        clear();
        printf("Moteur droit : %d\n Moteur gauche : %d",interrupt_count_d,interrupt_count_g);
        _delay_ms(50);
    }
}