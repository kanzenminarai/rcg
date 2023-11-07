#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <array.h>
#include <cli.h>
#include <tui.h>

int main(int argc, char **argv) {
  // declarations and initialization of the variables
  Array ar; // acess variable for the Array struct 
  bool repeat = 0;
  uint8_t choice = 0;
  ar.scrStart = FALSE; // verifies if initscr() has started

  // if only the software name were typed, skips the other ifs and start the software
  if(strcmp(argv[0], argv[argc - 1]) == OK) {
    initscr();
    ar.scrStart = TRUE;
  }
  else {
    cli(argv, &ar);
    return 0;
  }

  for(;;) {
    if(!repeat) {
      arraySize(&ar); // request the number of characters
      arrayType(&ar); // request the types of characters to include
    }
    arrayCreation(&ar); // evaluating the request
    arrayOutput(&ar); // printing the result
    free(ar.genChar);

    // check if it needs to repeat
    choice = getch();

    if(choice == 's') repeat = FALSE; // starts all over in 's'
    else if(choice == 'r') repeat = TRUE; // 'r' repeats the combination again 
    else break; // exits the if condition
  }
  endwin();
  return 0;
}
