#include <ncurses.h>
#include <array.h>

int main() {
  Array ar; // program state
  
  arraySize(&ar); // request the number of characters,
  arrayType(&ar); // request the types of characters to include,
  arrayCases(&ar); // evaluating the request,
  arrayOutput(&ar); // and printing the result.
  
  for(;;) {
    // check if we need to repeat
    ar.choice = getch();
    // repeats according to input from ptr->choice
    if(ar.choice == 's') {
      ar.length = 0;
      ar.type = 0;
      arraySize(&ar);
      arrayType(&ar);
      arrayCases(&ar);
      arrayOutput(&ar);
    }
    else if(ar.choice == 'r') {
      arrayCases(&ar);
      arrayOutput(&ar);
    }
    else break;
  }
  endwin();
  return 0;
}
