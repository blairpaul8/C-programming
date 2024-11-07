#ifndef LCD_H
#define LCD_H 
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

void pulse_enable();
void lcd_init();
void clear();
void write_character(uint8_t c);
void lcd_print(char *c);

#endif //LCD_H
