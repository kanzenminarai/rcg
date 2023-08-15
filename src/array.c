#include <stdlib.h>
#include <ncurses.h>
#include <array.h>

void arraySize(Array *ptr) {
  ptr->length = 0;
  
  // get the size of the array
  for(;;) {
    clear();
    printw("- Random Character Generator -\n"
      "Enter the length desired [unsigned integers only]: ");
    refresh();
    scanw("%u", &(ptr->length));

    if(ptr->length > 0) break; // breaks the loop in case of a known value
    printw("Value unknown!\n");
    refresh();
    napms(500);
  }
}

void arrayType(Array *ptr) {
  char input[4];
  size_t i;
  ptr->type = 0;
  
  // get the type of the characters
  for(;;) { 
    clear();
    printw("Select the option specified below to generate [any order]:\n"
      "1 - lower [a-z]\n"
      "2 - upper [A-Z]\n"
      "3 - numbers [0-9]\n"
      "4 - symbols ['!@#$...]\n");
    refresh();
    getnstr(input, sizeof(input));
    for(i = 0; input[i]; i++) {
      switch(input[i]){
        case '1':
          ptr->type |= LOWER;
          break;
          
        case '2':
          ptr->type |= UPPER;
          break;
          
        case '3':
          ptr->type |= NUMBER;
          break;
          
        case '4':
          ptr->type |= SYMBOL;
          break;
        
        default:
          if(input[i] != EOT) {
            printw("Unknown option [%c]!\n", input[i]);
            refresh();
            napms(800);
          }
          break;
      }
    }  
    if(ptr->type > 0) break; // breaks the for loop
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
    ptr->genArray, ptr->length, ptr->genChar, ptr->length * 8);
  refresh();

  // freeing the allocated memory
  free(ptr->genArray);
  free(ptr->genChar);
}
