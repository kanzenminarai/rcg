#include <ncurses.h>
#include <array.h>

int main() {
  Array ar; // program state
  int repeat = 0;
  
  for(;;) {
    if (!repeat) {
      arraySize(&ar); // request the number of characters,
      arrayType(&ar); // request the types of characters to include,
    }
    arrayCreation(&ar); // evaluating the request,
    arrayOutput(&ar); // and printing the result.
    
    // check if we need to repeat
    ar.choice = getch();
    // repeats according to input from ptr->choice
    if(ar.choice == 's') repeat = 0;
    else if(ar.choice == 'r') repeat = 1;
    else break;
  }
  endwin();
  return 0;
}
