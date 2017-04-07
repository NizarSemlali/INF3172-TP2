#----------------------------------------------------------------
# Auteurs:
# - NIZAR SEMLALI
# - OTHMANE BOUADDI
#----------------------------------------------------------------
all: tsh bin/list bin/new bin/rmall bin/newdir
CC = gcc
OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c))
EXEC = tsh

bin/list: bin/list.o
	$(CC) -o bin/list bin/list.o

bin/list.o: bin/list.c
	$(CC) -Wall -o bin/list.o -c bin/list.c

bin/new: bin/new.o
	$(CC) -o bin/new bin/new.o

bin/new.o: bin/new.c
	$(CC) -Wall -o bin/new.o -c bin/new.c

bin/rmall: bin/rmall.o
	$(CC) -o bin/rmall bin/rmall.o

bin/rmall.o: bin/rmall.c
	$(CC) -Wall -o bin/rmall.o -c bin/rmall.c

bin/newdir: bin/newdir.o
	$(CC) -o bin/newdir bin/newdir.o

bin/newdir.o: bin/newdir.c
	$(CC) -Wall -o bin/newdir.o -c bin/newdir.c

$(EXEC): $(OBJECTS)
	$(CC) -o $(EXEC) $(OBJECTS)

%.o: %.c
	$(CC) -Wall -o $@ -c $<


.PHONY: clean

clean:
	rm -f $(EXEC) $(OBJECTS)
	rm -f bin/list bin/list.o
	rm -f bin/new bin/new.o
	rm -f bin/rmall bin/rmall.o
	rm -f bin/newdir bin/newdir.o
