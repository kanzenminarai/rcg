#include <ncurses.h>
#include <array.h>

int main() {
  Array array; // program state
  bool repeat = 0;
  char choice;
  
  initscr();
  for(;;) {
    if(!repeat) {
      arraySize(&array); // request the number of characters
      arrayType(&array); // request the types of characters to include
    }
    arrayCreation(&array); // evaluating the request
    arrayOutput(&array); // printing the result
    
    // check if it needs to repeat
    choice = getch();

    // repeats according to input from ptr->choice
    if(choice == 's') repeat = FALSE;
    else if(choice == 'r') repeat = TRUE;
    else break;
  }
  endwin();
  return 0;
}
