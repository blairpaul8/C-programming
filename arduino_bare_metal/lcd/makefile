PORT = /dev/cu.usbmodem1201

default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o lcd.o lcd.c 
	avr-gcc -o lcd.bin lcd.o
	avr-objcopy -O ihex -R .eeprom lcd.bin lcd.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P $(PORT) -b 115200 -U flash:w:lcd.hex

