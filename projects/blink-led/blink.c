/* blink.c
 *
 * Simple LED Blink 
 *
 * Will blink Pin 0 on Port B*
 *
 */
#define F_CPU 1000000UL
#define DELAY 1000

#include <avr/io.h>
#include <util/delay.h>

int main()
{
    DDRB = 0xff; 

    while(1)
    {
        PORTB = 0x01;
        _delay_ms(DELAY);
        PORTB = 0x00;
        _delay_ms(DELAY);
    }
    
    return 0;
}
