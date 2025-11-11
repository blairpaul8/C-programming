#include <lcd.h>
#include <dht.h>
#include <util/delay>
#include <avr/io>
#include <stdio.h>
#include <stdlib.h>

dht DHT;

#define DHT11_PIN 7

int main() {
  char temp_str[8];
  lcd_init();
  
  while(1) {
    lcd_print("Temp: ");
    int dht_check = DHT.read(DHT11_PIN);
    
    if (dht_check == DHTLIB_OK) {
      dtostrf(DHT.temperature, 4, 1, temp_str);
      lcd_print(temp_str);
      lcd_print("F");
    }
    else {
      lcd_print("ERROR");
    }

    _delay_ms(5000);
    clear();
  }
  
}
