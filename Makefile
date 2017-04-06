#----------------------------------------------------------------
# Auteurs:
# - NIZAR SEMLALI
# - OTHMANE BOUADDI
#----------------------------------------------------------------
all: tsh bin/list bin/new
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

$(EXEC): $(OBJECTS)
	$(CC) -o $(EXEC) $(OBJECTS)

%.o: %.c
	$(CC) -Wall -o $@ -c $<


.PHONY: clean

clean:
	rm -f $(EXEC) $(OBJECTS)
	rm -f bin/list bin/list.o
	rm -f bin/new bin/new.o
