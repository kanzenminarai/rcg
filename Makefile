COMPILER = gcc
COMPILER_FLAGS = -Wall -Wextra -pedantic
INCLUDE_PATH = -I include/
LINKER_FLAG = -l ncurses
OBJECT_FILES = ./*.o
TARGET = rcg
INSTALL_PATH = /usr/local

all: $(TARGET)

$(TARGET): object
	$(COMPILER) -o $@ $(OBJECT_FILES) $(LINKER_FLAG)

object:
	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATH) -c src/*.c src/util/*.c

clean:
	rm -f $(OBJECT_FILES) $(TARGET)

install: $(TARGET)
	install -Dm755 $(TARGET) $(INSTALL_PATH)/bin/$(TARGET)

uninstall:
	rm -f $(INSTALL_PATH)/bin/$(TARGET)
