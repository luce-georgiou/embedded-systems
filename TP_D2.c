#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "macros.h"

//TP2
//if RRA == test_bit... allumer led yellow

void etat_ledA() {
    CLRBIT(DDRB,DDB3); //on passe en mode entrée
    SETBIT(PORTB,PORTB3); //resistance de pull-up activée
    while (true) {
        if (get_bit(PINB,PINB3) != 1) {
            SETBIT(DDRC,DDC7);            
            SETBIT(PORTC,PORTC7);

        }
        CLRBIT(PORTC,PORTC7);

        //_delay_ms(1000);
    }
}

void etat_ledB() {
    CLRBIT(DDRD,DDD5); //on passe en mode entrée
    CLRBIT(PORTD,PORTD5); //resistance de pull-up désactivée
    while (true) {
        if (get_bit(PIND,PIND5) != 1) {
            SETBIT(DDRC,DDC7);            
            SETBIT(PORTC,PORTC7);
        }
        CLRBIT(PORTC,PORTC7);
    }
}

int main() {
    etat_ledB();
    return 0;
}