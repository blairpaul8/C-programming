#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

// All Commands for the LCD
#define LCD_CLEAR 0x01
#define LCD_ENRTY_MODE 0x06
#define LCD_ON 0x0F

void pulse_enable() {
  PORTB |= (1 << PORTB3);                                                      
  _delay_us(2);                                                                
  PORTB &= ~(1 << PORTB3);                                                     
  _delay_ms(2);
}

void lcd_init() {
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
  pulse_enable();

  // Entry mode set move cursor right upon writing character
  PORTD = 0x06;
  pulse_enable();

  // Turn display on
  PORTD = 0x0F;
  pulse_enable();

}

void second_row() {
  PORTD = 0x40;
  PORTB |= (1 << PORTB3);
  _delay_us(2);
  PORTB &= ~(1 << PORTB3);
  _delay_ms(2);
}



void write_character(uint8_t c) {
  PORTB |= (1 << PORTB4);
  PORTD = c;
  pulse_enable();
  PORTB &= ~(1 << PORTB4);
  _delay_ms(2);
}

void lcd_print(char *c) {
  for (int i = 0; i < strlen(c); i++) {
    write_character(c[i]);
  }

}

int main(void) {
  //initialize the lcd
  lcd_init();
  //char *c = "Hello World";
  lcd_print("Hello World");
  
}
