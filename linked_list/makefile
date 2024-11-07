CC = cc
CFLAGS = -g -Wall

TARGET = practice

all: $(TARGET)

$(TARGET): link_list.c list_practice.c 
	$(CC) $(CFLAGS) link_list.c list_practice.c -o $(TARGET)

clean:
	rm -f $(TARGET)

