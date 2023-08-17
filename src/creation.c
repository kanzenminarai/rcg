#include <stdlib.h>
#include <array.h>
#include <rand.h>

void arrayCreation(Array *ptr) {
  size_t x, y = 0, range = 0;
  char *chars;

  // calculate the range and allocate
  if(ptr->type & LOWER) range += LETTERS;
  if(ptr->type & UPPER) range += LETTERS;
  if(ptr->type & NUMBER) range += NUMBERS;
  if(ptr->type & SYMBOL) range += SYMBOLS;
  ptr->genArray = malloc(range + 1);
  
  // copy chars to the array that is used for generating the string
  if(ptr->type & LOWER) {
    chars = "abcdefghijklmnopqrstuvwxyz";
    for(x = 0; x < LETTERS; x++, y++) ptr->genArray[y] = chars[x];
  }
  if(ptr->type & UPPER) {
    chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(x = 0; x < LETTERS; x++, y++) ptr->genArray[y] = chars[x];
  }
  if(ptr->type & NUMBER) {
    chars = "0123456789";
    for(x = 0; x < NUMBERS; x++, y++) ptr->genArray[y] = chars[x];
  }
  if(ptr->type & SYMBOL) {
    chars = "'|!@#$%&*()-_=+`{}[]^~<>,./?;:";
    for(x = 0; x < SYMBOLS; x++, y++) ptr->genArray[y] = chars[x];
  }
  
  // add a null terminator to the last element of the array
  ptr->genArray[y] = '\0';

  // allocate and generate the characters
  ptr->genChar = malloc(ptr->length + 1);
  for(x = 0; x < ptr->length; x++) ptr->genChar[x] = ptr->genArray[getNextRandom(range)];

  // add a null terminator to the last element of the array
  ptr->genChar[x] = '\0';
}
