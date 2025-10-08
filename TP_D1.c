#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "macros.h"
 
#define MORSE_DELAY_MS 500

//void led_on(void)     { PORTC |=  (1 << PORTC7); } //allume led orange
//void led_off(void)    { PORTC &= ~(1 << PORTC7); } //éteint led orange
//void led_enable(void) { DDRC  |=  (1 << DDC7); } //assigne en sortie 


void morse_pulse()
{
    //if (symbol != ' ') {
    SETBIT(PORTC,PORTC7) ; //on allume en passant bit à 1
    CLRBIT(PORTD,PORTD5) ;
    CLRBIT(PORTB,PORTB0); 

    _delay_ms(MORSE_DELAY_MS);

    //if (symbol != '.') 
    //_delay_ms(MORSE_DELAY_MS); 
    CLRBIT(PORTC,PORTC7); //on éteint
    SETBIT(PORTD,PORTD5);
    SETBIT(PORTB,PORTB0);
    

    _delay_ms(MORSE_DELAY_MS);
}

int main (void)
{
    //char msg[] = ".... . .-.. .-.. ---";
    SETBIT(DDRC,DDC7); //on passe en mode sortie
    SETBIT(DDRD,DDD5);
    SETBIT(DDRB,DDB0);
    while (true) {
        //for (int i=0; msg[i]; i++)
        morse_pulse();

        //_delay_ms(5000);
    }   
}

