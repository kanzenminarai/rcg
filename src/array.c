#include <ncurses.h>
#include <array.h>

void arraySize(Array *ptr) {
  initscr();
  do {
    clear();
    printw("- Random Character Generator -\n"
    "Enter the length desired [unsigned integers only]: ");
    refresh();
    scanw("%i", &(ptr->length));

    if(ptr->length > 0) break;
    printw("Value unknown.\n");
    refresh();
    napms(500);
  } while(ptr->length < 1);
}

void arrayType(Array *ptr) {
  do {
    clear();
    printw("Select the option specified below to generate [ascending order]:\n"
    "1 - lower [a-z]\n"
    "2 - upper [A-Z]\n"
    "3 - numbers [0-9]\n"
    "4 - symbols ['!@#$...]\n");
    refresh();
    scanw("%hi", &(ptr->type));

    if(ptr->type > 0) break;
    printw("Option unknown!\n");
    refresh();
    napms(500);
  } while(ptr->type < 1);
}

void arrayOutput(Array *ptr) {
  clear();
  printw("Selected characters: %s\n"
  "%i characters has been generated: %s\n"
  "Size in bits: %i\n\n"
  "Press \"s\" to start over\n"
  "Press \"r\" to recreate\n"
  "Press any other key to exit...",
  ptr->genArray, ptr->count, ptr->genChar, ptr->count * 8);
  refresh();
  arrayFree(ptr);
  ptr->choice = getch();
  arrayRepeat(ptr);
  endwin();
}

void arrayRepeat(Array *ptr) {
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