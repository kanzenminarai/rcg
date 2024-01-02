#include <ncurses.h>
#include <stdlib.h>
#include "util/string.h"
#include "array.h"
#define UINT16_MIN 0
#define BYTE_IN_BITS 8
#define START_OVER 's'
#define REPEAT 'r'
#define NEW_LINE_CHARACTER 1
#define UNKNOWN_TYPE 0

void getArrayLength(Array *ptr) {
  ptr->characterLength = 0;
  while(true) {
    clear();
    printw("Random Character Generator\n"
      "Enter the length: ");
    refresh();
    scanw("%hu", &(ptr->characterLength));
    if((ptr->characterLength > UINT16_MIN) && (ptr->characterLength < UINT16_MAX)) break;
    printw("Unknown value!\n");
    refresh();
    napms(500);
  }
}

void checkInputedType(bool wrongInput) {
  if(wrongInput == true) {
    printw("Unknown type!\n");
    refresh();
    napms(500);
  }
}

void getArrayType(Array *ptr) {
  char characterTypeInput[5];
  char *convertedArrayToString = (char *) characterTypeInput;
  while(true) {
    clear();
    printw("Select a type:\n"
      "[l] lower case (a - z)\n"
      "[u] upper case (A - Z)\n"
      "[n] numbers (0 - 9)\n"
      "[s] symbols (# - !)\n");
    refresh();
    getnstr(characterTypeInput, sizeof(characterTypeInput) - NEW_LINE_CHARACTER);
    characterTypeAttributionCases(convertedArrayToString, ptr);
    checkInputedType(ptr->wrongInput);
    if(ptr->characterType != UNKNOWN_TYPE) break;
  }
}

void showGeneratedCharacters(Array *ptr) {
  clear();
  printw("%i characters generated: %s\n"
    "Size in bits: %i\n\n"
    "Start over [s]\n"
    "Recreate [r]\n"
    "Exit [any other key]\n",
    ptr->characterLength, ptr->generatedChararacters, ptr->characterLength * BYTE_IN_BITS);
  refresh();
  free(ptr->generatedChararacters);
}

void repeatInput(Array *ptr) {
  bool repeatCharacters = 0;
  uint8_t choice = 0;
  while(true) {
    if(repeatCharacters == false) {
      getArrayLength(ptr);
      getArrayType(ptr);
    }
    arrayMain(ptr);
    showGeneratedCharacters(ptr);
    choice = getch();
    if(choice == START_OVER) repeatCharacters = false;
    else if(choice == REPEAT) repeatCharacters = true;
    else break;
  }
}

void tuiMain(Array *ptr) {
  initscr();
  repeatInput(ptr);
  endwin();
}
