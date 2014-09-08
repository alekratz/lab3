CC=gcc
CFLAGS=-g -O1 -Wall

arrayList: main.o

main.o: arrayList.h

arrayList.o: arrayList.h

install:
	touch *.c
	make arrayList
	mv arrayList ../bin

clean:
	rm arrayList *.o -f
