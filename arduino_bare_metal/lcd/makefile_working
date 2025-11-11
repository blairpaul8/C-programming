PORT = /dev/cu.usbmodem1201

default:
	avr-gcc -Os -Wall -ffunction-sections -fdata-sections -DF_CPU=16000000UL -mmcu=atmega328p -c -o lcd.o lcd.c 
	avr-gcc -Os -mmcu=atmega328p -ffunction-sections -fdata-sections -Wl,--gc-sections -o lcd.bin lcd.o
	avr-objcopy -O ihex -R .eeprom lcd.bin lcd.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P $(PORT) -b 115200 -U flash:w:lcd.hex

