CC = cc
CFLAGS = -g -Wall

TARGET = test_heap 

all: $(TARGET)

$(TARGET): heap_test.c vector.c heap.c
	$(CC) $(CFLAGS) heap_test.c vector.c heap.c -o $(TARGET)

clean:
	rm -f $(TARGET)
