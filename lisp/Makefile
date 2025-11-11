GXX = gcc
CFLAGS = -Wall
EDIT = -ledit
TARGET = prompt

all: $(TARGET)

$(TARGET): prompt.c 
	$(GXX) $(CFLAGS) prompt.c mpc.c $(EDIT) -o $(TARGET)

clean:
	rm -rf $(TARGET)
