CC = gcc
CFLAGS = -Wall -I include/
LIB = -l ncurses
RM = rm -rfv
MV = mv -v
SU = sudo
SOFT = rcg
BIN = /usr/local/bin/$(SOFT)
OBJ = main.o array.o creation.o cases.o

all: $(SOFT)

$(SOFT): $(OBJ)
	$(CC) $(CFLAGS) -o $(SOFT) $^ $(LIB)

main.o: src/main.c
	$(CC) $(CFLAGS) -c $<

array.o: src/array.c
	$(CC) $(CFLAGS) -c $<

creation.o: src/creation.c
	$(CC) $(CFLAGS) -c $<

cases.o: src/cases.c
	$(CC) $(CFLAGS) -c $<

install: $(SOFT)
	$(SU) $(MV) $(SOFT) $(BIN)
	$(SU) chmod +x $(BIN)

run: $(SOFT)
	$(BIN)

clean:
	$(RM) $(OBJ)

uninstall: clean
	$(SU) $(RM) $(BIN)