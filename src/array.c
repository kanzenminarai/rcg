#include <stdlib.h>
#include <ncurses.h>
#include <array.h>
#include <rand.h>
#define LOWER 1 << 0 // 1 in decimal
#define UPPER 1 << 1 // 2 in decimal
#define NUMBER 1 << 2 // 4 in decimal
#define SYMBOL 1 << 3 // 8 in decimal
#define LETTERS 26 // range of upper and lower letters
#define NUMBERS 10 // range of numbers
#define SYMBOLS 30 // range of symbols

void charOptions(const char *option, Array *ptr) {
  ptr->type = 0;

  // processing the input
  for(uint8_t i = 0; option[i]; i++) {
    switch(option[i]) {
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
        // '\04' == EOT (ASCII)
        if(option[i] != '\04') {
          // terminal user inteface
          if((ptr->scrStart) == TRUE) {
            printw("Unknown option %c!\n", option[i]);
            refresh();
            napms(800);
          }
          // command line
          else printf("Unknown option %c!\n", option[i]);
        }
        break;
    }
  }
}

// creates the array according to the inserted size and type
void arrayCreation(Array *ptr) {
  // "x" and "y" are used to count the for loop repetition
  uint16_t x = 0, y = 0; // 32767 characters is the limit 
  uint8_t range = 0;
  char *chars = 0;

  /* the if statements checks the inserted type matches the values, and store the 
  range, in case of multiple selection, it stores a sum of the anterior value */
  if(ptr->type & LOWER) range += LETTERS;
  if(ptr->type & UPPER) range += LETTERS;
  if(ptr->type & NUMBER) range += NUMBERS;
  if(ptr->type & SYMBOL) range += SYMBOLS;

  ptr->genArray = malloc(range + 1); // the + 1 is because of a null char
  
  // attributes the chars to the array that is going to be used for generating the random characters
  if(ptr->type & LOWER) {
    chars = "abcdefghijklmnopqrstuvwxyz";
    for(x = 0; x < LETTERS; y++, x++) ptr->genArray[y] = chars[x];
  }
  if(ptr->type & UPPER) {
    chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(x = 0; x < LETTERS; y++, x++) ptr->genArray[y] = chars[x];
  }
  if(ptr->type & NUMBER) {
    chars = "0123456789";
    for(x = 0; x < NUMBERS; y++, x++) ptr->genArray[y] = chars[x];
  }
  if(ptr->type & SYMBOL) {
    chars = "'|!@#$%&*()-_=+`{}[]^~<>,./?;:";
    for(x = 0; x < SYMBOLS; y++, x++) ptr->genArray[y] = chars[x];
  }
  
  ptr->genArray[y] = '\0';// null terminator is set in the last element
  ptr->genChar = malloc(ptr->length + 1); // the + 1 is the addition of a null char

  for(x = 0; x < ptr->length; x++) ptr->genChar[x] = ptr->genArray[getNextRandom(range)];
  free(ptr->genArray);

  ptr->genChar[x] = '\0'; // null terminator is nset in the last element
}
