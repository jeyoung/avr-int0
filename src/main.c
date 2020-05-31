#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void
delay_ms(uint16_t);

int
main(void)
{
    DDRB = _BV (PB7);
    EICRA = _BV (ISC00);

    EIMSK |= _BV (INT0);
    sei();

    while (1)
        ;
}

void
delay_ms(uint16_t ms)
{
    while (--ms > 0)
        _delay_ms(1);
}

ISR(INT0_vect)
{
    PORTB = PIND & _BV (PD0) ? PORTB | _BV (PB7) : PORTB & ~ _BV (PB7);
}
