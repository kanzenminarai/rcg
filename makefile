cc = gcc
cf = -Wall -I include/
lib = -l ncurses
rm = rm -rfv

all: rcg

rcg: main.o array.o creation.o cases.o
	$(cc) $(cf) -o $@ $^ $(lib)

main.o: src/main.c
	$(cc) $(cf) -c $<

array.o: src/array.c
	$(cc) $(cf) -c $<

creation.o: src/creation.c
	$(cc) $(cf) -c $<

cases.o: src/cases.c
	$(cc) $(cf) -c $<

run: rcg
	./$<

clean:
	$(rm) rcg *.o