# variables

cc = gcc
cf = -Wall -I include/
lib = -l ncurses
rm = rm -rfv
mv = mv -v
su = sudo
soft = rcg
path = /usr/local/bin/$(soft)


# targets

all: $(soft)

$(soft): main.o array.o creation.o cases.o
	$(mv) *.o object/
	$(cc) $(cf) -o $(soft) object/*.o $(lib)
	$(su) $(mv) $(soft) $(path)

main.o: src/main.c
	$(cc) $(cf) -c $<

array.o: src/array.c
	$(cc) $(cf) -c $<

creation.o: src/creation.c
	$(cc) $(cf) -c $<

cases.o: src/cases.c
	$(cc) $(cf) -c $<

run: $(soft)
	$(path)

clean:
	$(su) $(rm) $(path) object/*.o