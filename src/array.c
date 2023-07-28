#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <array.h>

void arrSize(arrTyp *ptr) {
  initscr();
  srand(time(NULL));
  wrongInput:
  clear();

  printw("- Random Character Generator -\n"
  "Enter the length desired [1, 2, 3- ...]: ");
  refresh();
  scanw("%i", &(ptr->length));

  if((ptr->length) <= 0) {
    printw("Unsigned integers only!\n");
    refresh();
    napms(1000);
    clear();
    goto wrongInput;
  }
}

void arrType(arrTyp *ptr) {
  wrongInput:
  clear();
  printw("Select the option to generate [1, 2... or 1234, 13...]:\n"
  "1 - lower [a-z]\n"
  "2 - upper [A-Z]\n"
  "3 - numbers [0-9]\n"
  "4 - symbols ['!@#$...]\n");
  refresh();
  scanw("%i", &(ptr->type));

  if((ptr->type) <= 0) {
    printw("Unsigned integers only!\n");
    refresh();
    napms(1000);
    clear();
    goto wrongInput;
  }
}

void arrOutput(arrTyp *ptr) {
  clear();
  printw("Selected characters: %s\n"
  "%i characters has been generated: %s\n"
  "Size in bits: %i\n\n"
  "Press \"s\" to start over\n"
  "Press \"r\" to recreate\n"
  "Press any other key to exit...", ptr->genArr, ptr->counter, ptr->genChar, ptr->counter * 8);
  refresh();
  ptr->choice = getch();
  
  free(ptr->genChar);
  free(ptr->genArr);
  arrRepeat(ptr);
  endwin();
}

void arrRepeat(arrTyp *ptr) {
  if(ptr->choice == 's') {
    ptr->length = 0;
    ptr->type = 0;
    arrSize(ptr);
    arrType(ptr);  
    arrCases(ptr);
    arrOutput(ptr);
  }
  if(ptr->choice == 'r') {
    arrCases(ptr);
    arrOutput(ptr);
  }
}