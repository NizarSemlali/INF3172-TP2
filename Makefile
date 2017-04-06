#----------------------------------------------------------------
# Auteurs:
# - NIZAR SEMLALI
# - OTHMANE BOUADDI
#----------------------------------------------------------------
all: tsh bin/list
CC = gcc
OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c))
EXEC = tsh

bin/list: bin/list.o
	$(CC) -o bin/list bin/list.o

bin/list.o: bin/list.c
	$(CC) -Wall -o bin/list.o -c bin/list.c

$(EXEC): $(OBJECTS)
	$(CC) -o $(EXEC) $(OBJECTS)

%.o: %.c
	$(CC) -Wall -o $@ -c $<


.PHONY: clean

clean:
	rm -f $(EXEC) $(OBJECTS)
	rm -f bin/list bin/list.o
