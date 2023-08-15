# CC =
CFLAGS = -Wall -Wextra -pedantic -Iinclude/
LDFLAGS = -lncurses
OBJS = main.o array.o creation.o rand.o
TARGET = rcg
PREFIX = /usr/local

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)


install: $(TARGET)
	install -Dm755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)
