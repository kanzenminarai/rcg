CC = gcc
CFLAGS = -Wall -I include/
LIB = -l ncurses
RM = rm -f
TARG = rcg
BINDIR = /usr/local/bin
OBJ = main.o array.o creation.o cases.o

all: $(TARG)

$(TARG): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

main.o: src/main.c
	$(CC) $(CFLAGS) -c $<

array.o: src/array.c
	$(CC) $(CFLAGS) -c $<

creation.o: src/creation.c
	$(CC) $(CFLAGS) -c $<

cases.o: src/cases.c
	$(CC) $(CFLAGS) -c $<

install: $(TARG)
	install $(TARG) $(BINDIR)/$(TARG)

run: $(TARG)
	./$(TARG)

clean:
	$(RM) $(OBJ) $(TARG)

uninstall:
	$(RM) $(BINDIR)/$(TARG)
