CC = gcc
CFLAGS = -Wall -Wextra -O2 -I include/
LIB = -l ncurses
RM = rm -f
TARG = rcg
BINDIR = /usr/local/bin
OBJ = src/main.o src/array.o src/creation.o

all: $(TARG)

$(TARG): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

install: $(TARG)
	install $(TARG) $(BINDIR)/$(TARG)

run: $(TARG)
	./$(TARG)

clean:
	$(RM) $(OBJ) $(TARG)

uninstall:
	$(RM) $(BINDIR)/$(TARG)
