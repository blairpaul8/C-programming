# Define serial port for flashing
PORT = /dev/cu.usbmodem1201

# MCU and frequency
MCU = atmega328p
F_CPU = 16000000UL

# Compiler and flags
CC = avr-gcc
CFLAGS = -Os -Wall -ffunction-sections -fdata-sections -DF_CPU=$(F_CPU) -mmcu=$(MCU)
LDFLAGS = -Wl,--gc-sections

# Source and object files
SRCS = temp_humidity.c lcd.c
OBJS = $(SRCS:.c=.o)

# Output files
TARGET = main

# Default rule to build and flash the program
default: $(TARGET).hex flash

# Compile each .c file to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link all .o files into an .elf binary
$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

# Convert the .elf binary to a .hex file for flashing
%.hex: %.elf
	avr-objcopy -O ihex -R .eeprom $< $@

# Flash the .hex file to the microcontroller
flash: $(TARGET).hex
	sudo avrdude -F -V -c arduino -p $(MCU) -P $(PORT) -b 115200 -U flash:w:$(TARGET).hex

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).hex

