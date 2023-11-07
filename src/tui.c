#include <ncurses.h>
#include <stdlib.h>
#include <array.h>

// get the size of the characters that will be generated
void arraySize(Array *ptr) {
  ptr->length = 0;
  
  // here will get the size of the array
  for(;;) {
    clear();
    printw("Random Character Generator\n"
      "Enter the length: ");
    refresh();
    scanw("%u", &(ptr->length));

    if(ptr->length > 0 && ptr->length < 32767) break; // breaks the loop in case of a known value
    printw("Unknown value!\n");
    refresh();
    napms(500);
  }
}

// get the type inserted through the input
void arrayType(Array *ptr) {
  // initializing the variables
  char input[4];
  char *str = input;
  uint8_t count = 0;
  
  // selection of the type of the characters
  for(;;) {
    clear();
    printw("Select a option:\n"
      "[1] lower (a - z)\n"
      "[2] upper (A - Z)\n"
      "[3] numbers (0 - 9)\n"
      "[4] symbols (# - !)\n");
    refresh();
    getnstr(input, sizeof(input));

    // passing values from the array of chars to a pointer of chars
    for(count = 0; count < 5; count++) str[count] = input[count];    
    charOptions(str, ptr);
    if(ptr->type > 0) break;
  }
}

// show the outputed characters generated earlier by the inputs
void arrayOutput(Array *ptr) {
  clear();
  // printing the output and the size in bits (length * size of a byte in bits)
  printw("%i characters generated: %s\n"
    "Size in bits: %i\n\n"
    "Start over [s]\n"
    "Recreate [r]\n"
    "Exit [any other key]\n",
    ptr->length, ptr->genChar, ptr->length * 8);
  refresh();
}