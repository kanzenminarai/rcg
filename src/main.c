#include <ncurses.h>
#include <array.h>

int main() {
  Array ar; // program state
  
  arraySize(&ar); // request the number of characters,
  arrayType(&ar); // request the types of characters to include,
  arrayCreation(&ar); // evaluating the request,
  arrayOutput(&ar); // and printing the result.
  
  for(;;) {
    // check if we need to repeat
    ar.choice = getch();
    // repeats according to input from ptr->choice
    if(ar.choice == 's') {
      arraySize(&ar);
      arrayType(&ar);
      arrayCreation(&ar);
      arrayOutput(&ar);
    }
    else if(ar.choice == 'r') {
      arrayCreation(&ar);
      arrayOutput(&ar);
    }
    else break;
  }
  endwin();
  return 0;
}
