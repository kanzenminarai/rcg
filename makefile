CC = gcc
CFLAGS = -Wall -I include/
LIB = -l ncurses
RM = rm -rfv
MV = mv -v
SU = sudo
SOFT = rcg
BIN = /usr/local/bin/$(SOFT)

all: $(SOFT)

$(SOFT): main.o array.o creation.o cases.o
	$(MV) *.o obj/
	$(CC) $(CFLAGS) -o $(SOFT) obj/*.o $(LIB)
	$(SU) $(MV) $(SOFT) $(BIN)

main.o: src/main.c
	$(CC) $(CFLAGS) -c $<

array.o: src/array.c
	$(CC) $(CFLAGS) -c $<

creation.o: src/creation.c
	$(CC) $(CFLAGS) -c $<

cases.o: src/cases.c
	$(CC) $(CFLAGS) -c $<

run: $(SOFT)
	$(BIN)

clean:
	$(SU) $(RM) $(BIN) obj/*.o