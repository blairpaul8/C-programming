#include <avr/io.h>
#include <util/delay.h>

int main() {
  //set portb to be an output
  DDRB |= (1 << DDB5);

  //blink the led
  while (1) {
    //Set pin five of PORTB to high
    PORTB |= (1 << PORTB5);
    
    //Wait
    _delay_ms(1000);

    //Unset pin 5 of PORTB
    PORTB &= ~(1 << PORTB5);

    //Wait again
    _delay_ms(1000);

  }


}
