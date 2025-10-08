void led_yellow_on_off()
{
    //if (symbol != ' ') {
    SETBIT(PORTC,PORTC7) ;
    _delay_ms(MORSE_DELAY_MS);

    //if (symbol != '.') 
    //_delay_ms(MORSE_DELAY_MS); 
    CLRBIT(PORTC,PORTC7);
    _delay_ms(MORSE_DELAY_MS);
}