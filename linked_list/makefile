C= cc
CFLAGS= -g 

all: link_list

link_list: link_list.o
	$(C) $(CFLAGS) link_list.o -o list

link_list.o: link_list.c
	$(C) $(CFLAGS) -c link_list.c

clean:
	rm -f *.o link_list


