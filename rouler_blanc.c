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

#include "projet.h"

volatile int interrupt_count_d = 0;
volatile int interrupt_count_g = 0;
volatile int prev_rightb = 0, prev_righta = 0, prev_leftb = 0, prev_lefta = 0;

ISR(INT6_vect)
{
    // pour la droite
    int rightxor = get_bit(PINE, PINE6);
    int rightb = get_bit(PINF, PINF0);
    int righta = rightxor ^ rightb;

    if (righta == prev_rightb)
    { // forward
        interrupt_count_d--;
    }
    else if (rightb == prev_righta)
    { // backward
        interrupt_count_d++;
    }
    prev_rightb = rightb;
    prev_righta = righta;
}

ISR(PCINT0_vect)
{
    // pour la gauche
    int leftxor = get_bit(PINB, PINB4);
    int leftb = get_bit(PINE, PINE2);
    int lefta = leftxor ^ leftb;

    if (lefta == prev_leftb)
    { // forward
        interrupt_count_g--;
    }
    else if (leftb == prev_lefta)
    { // backward
        interrupt_count_g++;
    }
    prev_leftb = leftb;
    prev_lefta = lefta;
}

void init_encodeurs()
{
    SETBIT(EIMSK, INT6); // autorisations
    SETBIT(EICRB, ISC60);
    CLRBIT(EICRB, ISC61);

    CLRBIT(DDRE, DDE6); // passage en mode entrée
    CLRBIT(DDRF, DDF0);

    // gauche
    SETBIT(PCICR, PCIE0);
    SETBIT(PCMSK0, PCINT4);

    CLRBIT(DDRB, DDB4);
    CLRBIT(DDRE, DDE2);

    sei();

    prev_righta = 0;
    prev_rightb = get_bit(PINF, PINF0);
    prev_lefta = 0;
    prev_leftb = get_bit(PINE, PINE2);
}

void ligne_droite()
{
    float K_encodeur = 2.5;
    moteurs();
    init_encodeurs();
    int val_d = capteur_droite();
    int val_g = capteur_gauche();
    int epsilone = interrupt_count_d - interrupt_count_g;
    float u = K_encodeur * (float)epsilone;
    OCR1A = 30 - (int)u;
    OCR1B = 30 + (int)u;
    clear();
    printf("capteur gauche : %d\n", val_g);
    printf("capteur droit : %d\n", val_d);
    printf("%d", epsilone);
}

// int main()
// {
//     while (true)
//     {
//         ligne_droite();
//         // float K_encodeur = 2.7;
//         // moteurs();
//         // init_encodeurs();
//         // int val_d = capteur_droite();
//         // int val_g = capteur_gauche();
//         // int epsilone = interrupt_count_d - interrupt_count_g;
//         // float u = K_encodeur * (float)epsilone;
//         // OCR1A = 30 - (int)u;
//         // OCR1B = 30 + (int)u;
//         // // if (epsilone <= 0)
//         // // {
//         // //     float u = K_encodeur * (float)epsilone;
//         // //     OCR1A = (int)(30.0 * abs(u));
//         // //     OCR1B = 30;
//         // //     clear();
//         // clear();
//         // printf("capteur gauche : %d\n", val_g);
//         // printf("capteur droit : %d\n", val_d);
//         // printf("%d", epsilone);
//         // }
//         // if (epsilone >= 0)
//         // {
//         //     float u = K_encodeur * (float)epsilone;
//         //     OCR1A = 30;
//         //     OCR1B = (int)(30.0 * abs(u));
//         //     clear();
//         //     printf("capteur gauche : %d\n", val_g);
//         //     printf("capteur droit : %d\n", val_d);
//         //     printf("Moteur droit : %d\n Moteur gauche : %d", interrupt_count_d, interrupt_count_g);
//         // }

//         //_delay_ms(100);
//     }

//     // while ((val_d < 1050) && (val_g < 1050))
//     // {

//     //     OCR1A = 30;
//     //     OCR1B = 30;
//     //     int epsilone = abs(interrupt_count_d - interrupt_count_g);
//     //     while (epsilone > 1)
//     //     {
//     //         float u = K_encodeur * (float)epsilone;
//     //         OCR1A = (int)(30.0 * u);
//     //         OCR1B = (int)(30.0 * u);
//     //         clear();
//     //     printf("capteur gauche : %d\n", val_g);
//     //     printf("capteur droit : %d\n", val_d);
//     //     printf("Moteur droit : %d\n Moteur gauche : %d", interrupt_count_d, interrupt_count_g);
//     //     _delay_ms(100);
//     //     }
//     //     clear();
//     //     printf("capteur gauche : %d\n", val_g);
//     //     printf("capteur droit : %d\n", val_d);
//     //     printf("Moteur droit : %d\n Moteur gauche : %d", interrupt_count_d, interrupt_count_g);
//     //     _delay_ms(100);
//     //     val_d = capteur_droite();
//     //     val_g = capteur_gauche();
//     // }
// }
