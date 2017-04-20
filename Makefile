#----------------------------------------------------------------
# Auteurs:
# - NIZAR SEMLALI
# - OTHMANE BOUADDI
#----------------------------------------------------------------
EXEDIR = ~/inf3172/bin
OBJDIR = ~/inf3172/obj
all: $(EXEDIR)/tsh $(EXEDIR)/list $(EXEDIR)/new $(EXEDIR)/rmall $(EXEDIR)/newdir $(EXEDIR)/size $(EXEDIR)/fin
CC = gcc
OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c))
EXEC = tsh

$(shell mkdir -p $(EXEDIR))
$(shell mkdir -p $(OBJDIR))

$(EXEDIR)/list: $(OBJDIR)/list.o
	$(CC) -o $(EXEDIR)/list $(OBJDIR)/list.o

$(OBJDIR)/list.o: src/list.c
	$(CC) -Wall -o $(OBJDIR)/list.o -c src/list.c

$(EXEDIR)/new: $(OBJDIR)/new.o
	$(CC) -o $(EXEDIR)/new $(OBJDIR)/new.o

$(OBJDIR)/new.o: src/new.c
	$(CC) -Wall -o $(OBJDIR)/new.o -c src/new.c

$(EXEDIR)/rmall: src/rmall.o
	$(CC) -o $(EXEDIR)/rmall src/rmall.o

$(OBJDIR)/rmall.o: src/rmall.c
	$(CC) -Wall -o $(OBJDIR)/rmall.o -c src/rmall.c

$(EXEDIR)/newdir: $(OBJDIR)/newdir.o
	$(CC) -o $(EXEDIR)/newdir $(OBJDIR)/newdir.o

$(OBJDIR)/newdir.o: src/newdir.c
	$(CC) -Wall -o $(OBJDIR)/newdir.o -c src/newdir.c

$(EXEDIR)/size: $(OBJDIR)/size.o
	$(CC) -o $(EXEDIR)/size $(OBJDIR)/size.o

$(OBJDIR)/size.o: src/size.c
	$(CC) -Wall -o $(OBJDIR)/size.o -c src/size.c

$(EXEDIR)/fin: $(OBJDIR)/fin.o
	$(CC) -o $(EXEDIR)/fin $(OBJDIR)/fin.o

$(OBJDIR)/fin.o: src/fin.c
	$(CC) -Wall -o $(OBJDIR)/fin.o -c src/fin.c

$(EXEDIR)/$(EXEC): $(OBJDIR)/$(OBJECTS)
	$(CC) -o $(EXEDIR)/$(EXEC) $(OBJDIR)/$(OBJECTS)

$(OBJDIR)/%.o: %.c
	$(CC) -Wall -o $@ -c $<


.PHONY: clean

clean:
	rm -f $(EXEDIR)/tsh $(OBJDIR)/$(OBJECTS)
	rm -f $(EXEDIR)/newdir $(OBJDIR)/newdir.o
	rm -f $(EXEDIR)/list $(OBJDIR)/list.o
	rm -f $(EXEDIR)/new $(OBJDIR)/new.o
	rm -f $(EXEDIR)/rmall $(OBJDIR)/rmall.o
	rm -f $(EXEDIR)/size $(OBJDIR)/size.o
	rm -f $(EXEDIR)/fin $(OBJDIR)/fin.o