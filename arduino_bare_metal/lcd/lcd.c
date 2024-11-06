#include <avr/io.h>
#include <util/delay.h>

// All Commands for the LCD
#define LCD_CLEAR 0x01
#define LCD_ENRTY_MODE 0x06
#define LCD_ON 0x0F

#define PULSE_ENABLE()                                                         \
  PORTB |= (1 << PORTB3);                                                      \
  _delay_us(2);                                                                \
  PORTB &= ~(1 << PORTB3);                                                     \
  _delay_ms(2);

int main(void) {
  // Set all DDRD pins to 1 for output
  DDRD = 0xFF;
  // Set all PORTD pins to 0
  PORTD = 0x00;
  // Set pin 3 and 4 of DDRB to 1 for output
  DDRB |= (1 << DDB3);
  DDRB |= (1 << DDB4);

  // Set PORTB3 and PORTB4 to 0
  PORTB &= ~(1 << PORTB4); // RS
  PORTB &= ~(1 << PORTB3); // EN

  _delay_ms(15);
  // clear the display
  PORTD = 0x01;
  PORTB |= (1 << PORTB3);
  _delay_us(2);
  PORTB &= ~(1 << PORTB3);
  _delay_ms(2);

  // Entry mode set move cursor right upon writing character
  PORTD = 0x06;
  PORTB |= (1 << PORTB3);
  _delay_us(2);
  PORTB &= ~(1 << PORTB3);
  _delay_ms(2);

  // Turn display on
  PORTD = 0x0F;
  PORTB |= (1 << PORTB3);
  _delay_us(2);
  PORTB &= ~(1 << PORTB3);
  _delay_ms(2);

  PORTB |= (1 << PORTB4);
  PORTD = 0x41;
  /* PORTB |= (1 << PORTB3);
   _delay_us(2);
   PORTB &= ~(1 << PORTB3);
   _delay_ms(2);*/
  PULSE_ENABLE();
}
