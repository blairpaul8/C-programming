#include <avr/io.h>
#include <util/delay.h>

//#define LCD_DDR DDRD
//#define LCD_PORT PORTD

//Toggle the enable pin to send the comand
void pulse_enable() {
  PORTB |= (1 << PORTB3);
  _delay_us(1);
  PORTB &= ~(1 << PORTB3);
  _delay_us(50);
}

void write_character(char c) {
  PORTB |= (1 << PORTB4);
  PORTD = c;
  pulse_enable();
  PORTB &= ~(1 << PORTB4);
}

void lcd_command(uint8_t cmd) {
  PORTB &= ~(1 << PORTB4);    // Set RS low for command mode
  PORTD = cmd;            // Place command on data lines
  pulse_enable();         // Pulse enable to send command
}

int main() {

  //Set Data Direction Register D (DDRD) to output pins to write to the LCD
  DDRD = 0xFF;
  //Set PD0-PD7 to low
  PORTD = 0x00;

  DDRB |= (1 << DDB3);  //Enable pin for the LCD
  DDRB |= (1 << DDB4);  //Register Select pin 
  
  PORTB &= ~(1 << PORTB3);  // Enable
  PORTB &= ~(1 << PORTB4);  // RS
  
  _delay_ms(100);

  //First Function set to set into 8 bit mode
  lcd_command(0x30);
  _delay_ms(5);

  //Second Function set instruction
  lcd_command(0x30);
  _delay_us(100);

  //Third Function set instruction.
  lcd_command(0x30);
  _delay_us(100);
  
  // FInal Funtion Set
  lcd_command(0x38);
  _delay_us(100);

  //Display on/off 
  lcd_command(0x08);
  _delay_us(100);

  //Clear Display 
  lcd_command(0x01);
  _delay_ms(2);

  //Entry Mode Set 
  lcd_command(0x06);
  _delay_us(100);

  lcd_command(0x0F);
  _delay_us(100);
  //Write a single character
  write_character('H');
}
