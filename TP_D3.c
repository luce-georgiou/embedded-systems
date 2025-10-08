#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "macros.h"
#include <stdio.h>
#include "print.h"
#include "OLED.h"
#include "SH1106.h"
#include "m_usb.h"

//pour capteur droite DN4 PORTF4
//pour capteur gauche DN2 PORTF7

int capteur() {
    SETBIT(DDRD,DDD6);      //configuré le port en sortie
    SETBIT(PORTD,PORTD6);   // décharger le condensateur de Down1
    _delay_us(10);          // pendant 10 microsecondes (ça suffit)

    CLRBIT(DDRD,DDD6);      // on repasse le port en entrée
    CLRBIT(PORTD,PORTD6);   // on désactive la résistance de pullup

    SETBIT(DDRB,DDB7);      // on met l'émetteur Infrarouge en sortie
    SETBIT(PORTB,PORTB7);   // et on active la LED Infrarouge

    int count = 0;
    while ((get_bit(PIND,PIND6) != 0) && (count<30000)) { //tant qu'on est pas à l'état bas
        count = count+1;
        // printf("%d",count);
        // clear();
    }
    
    CLRBIT(PORTB,PORTB7); //on éteint la LED infrarouge
    return count; 
}

int capteur_droite() {
    SETBIT(DDRF,DDF4);      //configuré le port en sortie
    SETBIT(PORTF,PORTF4);   // décharger le condensateur de Down1
    _delay_us(10);          // pendant 10 microsecondes (ça suffit)

    CLRBIT(DDRF,DDF4);      // on repasse le port en entrée
    CLRBIT(PORTF,PORTF4);   // on désactive la résistance de pullup

    SETBIT(DDRB,DDB7);      // on met l'émetteur Infrarouge en sortie
    SETBIT(PORTB,PORTB7);   // et on active la LED Infrarouge

    int count = 0;
    while ((get_bit(PINF,PINF4) != 0) && (count<30000)) { //tant qu'on est pas à l'état bas
        count = count+1;
        // printf("%d",count);
        // clear();
    }
    
    CLRBIT(PORTB,PORTB7); //on éteint la LED infrarouge
    return count; 
}

int capteur_gauche() {
    SETBIT(DDRF,DDF7);      //configuré le port en sortie
    SETBIT(PORTF,PORTF7);   // décharger le condensateur de Down1
    _delay_us(10);          // pendant 10 microsecondes (ça suffit)

    CLRBIT(DDRF,DDF7);      // on repasse le port en entrée
    CLRBIT(PORTF,PORTF7);   // on désactive la résistance de pullup

    SETBIT(DDRB,DDB7);      // on met l'émetteur Infrarouge en sortie
    SETBIT(PORTB,PORTB7);   // et on active la LED Infrarouge

    int count = 0;
    while ((get_bit(PINF,PINF7) != 0) && (count<30000)) { //tant qu'on est pas à l'état bas
        count = count+1;
        // printf("%d",count);
        // clear();
    }
    
    CLRBIT(PORTB,PORTB7); //on éteint la LED infrarouge
    return count; 
}

// int main() {
//     while (true) {
//         clear();
//         printf("%d", capteur());
//         _delay_ms(200);
//     }
// }