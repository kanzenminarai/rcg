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

main.o: source/main.c
	$(cc) $(cf) -c $<

array.o: source/array.c
	$(cc) $(cf) -c $<

creation.o: source/creation.c
	$(cc) $(cf) -c $<

cases.o: source/cases.c
	$(cc) $(cf) -c $<

run: $(soft)
	$(path)

clean:
	$(su) $(rm) $(path) object/*.o