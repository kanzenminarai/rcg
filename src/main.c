#include <ncurses.h>
#include <array.h>

int main() {
  Array ar; // program state
  bool repeat = 0;
  char choice;
  
  initscr();
  for(;;) {
    if(!repeat) {
      arraySize(&ar); // request the number of characters
      arrayType(&ar); // request the types of characters to include
    }
    arrayCreation(&ar); // evaluating the request
    arrayOutput(&ar); // printing the result
    
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
