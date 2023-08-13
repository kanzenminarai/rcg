#include <ncurses.h>
#include <array.h>

int main() {
  Array ar; // program state
  int repeat = 0;
  char choice;
  
  for(;;) {
    if(!repeat) {
      arraySize(&ar); // request the number of characters,
      arrayType(&ar); // request the types of characters to include,
    }
    arrayCreation(&ar); // evaluating the request,
    arrayOutput(&ar); // and printing the result.
    
    // check if we need to repeat
    choice = getch();
    // repeats according to input from ptr->choice
    if(choice == 's') repeat = 0;
    else if(choice == 'r') repeat = 1;
    else break;
  }
  endwin();
  return 0;
}
