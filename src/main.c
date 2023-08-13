#include <array.h>

int main() {
  // setting ar as a variable from "Array" type
  Array ar;
  
  arraySize(&ar); // request the number of characters,
  arrayType(&ar); // request the types of characters to include,
  arrayCases(&ar); // evaluating the request,
  arrayOutput(&ar); // and printing the result.
  return 0;
}
