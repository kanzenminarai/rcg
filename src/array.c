#include <stdlib.h>
#include <ncurses.h>
#include <array.h>

void arraySize(Array *ptr) {
  initscr();

  // getting the size of the array
  for(;;) {
    clear();
    printw("- Random Character Generator -\n"
    "Enter the length desired [unsigned integers only]: ");
    refresh();
    scanw("%i", &(ptr->length));

    if(ptr->length > 0) break; // breaks the loop in case of a known value
    printw("Value unknown.\n");
    refresh();
    napms(500);
  }
}

void arrayType(Array *ptr) {
  // getting the type of the characters
  for(;;) {
    clear();
    printw("Select the option specified below to generate [ascending order]:\n"
    "1 - lower [a-z]\n"
    "2 - upper [A-Z]\n"
    "3 - numbers [0-9]\n"
    "4 - symbols ['!@#$...]\n");
    refresh();
    scanw("%hi", &(ptr->type));

    if(ptr->type > 0) break; // breaks the loop in case of a known value
    printw("Option unknown!\n");
    refresh();
    napms(500);
  }
}

void arrayOutput(Array *ptr) {
  // printing the output
  clear();
  printw("Selected characters: %s\n"
  "%i characters has been generated: %s\n"
  "Size in bits: %i\n\n"
  "Press \"s\" to start over\n"
  "Press \"r\" to recreate\n"
  "Press any other key to exit...",
  ptr->genArray, ptr->count, ptr->genChar, ptr->count * 8);
  refresh();

  // freeing the allocated memory
  free(ptr->genArray);
  free(ptr->genChar);
  
  // getting the input
  ptr->choice = getch();
  arrayRepeat(ptr);
  endwin();
}

void arrayRepeat(Array *ptr) {
  // repeats according to input from ptr->choice
  if(ptr->choice == 's') {
    ptr->length = 0;
    ptr->type = 0;
    arraySize(ptr);
    arrayType(ptr);
    arrayCases(ptr);
    arrayOutput(ptr);
  }
  else if(ptr->choice == 'r') {
    arrayCases(ptr);
    arrayOutput(ptr);
  }
}
