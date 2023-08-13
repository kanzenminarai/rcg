#include <stdlib.h>
#include <time.h>
#include <array.h>

void arrayCreation(Array *ptr) {
  size_t i;
  size_t count;
  
  // calculate the range and allocate
  ptr->range = 0;
  if(ptr->type & LOWER) ptr->range += 26;
  if(ptr->type & UPPER) ptr->range += 26;
  if(ptr->type & NUMBER) ptr->range += 10;
  if(ptr->type & SYMBOL) ptr->range += 30;
  ptr->genArray = malloc(ptr->range + 1);
  
  // copy letters to the array that is used for generating the string
  count = 0;
  if(ptr->type & LOWER) {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    for(i = 0; i < 26; i++){
      ptr->genArray[count] = letters[i];
      count++;
    }
  }
  if(ptr->type & UPPER) {
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(i = 0; i < 26; i++){
      ptr->genArray[count] = letters[i];
      count++;
    }
  }
  if(ptr->type & NUMBER) {
    char letters[] = "0123456789";
    for(i = 0; i < 10; i++){
      ptr->genArray[count] = letters[i];
      count++;
    }
  }
  if(ptr->type & SYMBOL) {
    char letters[] = "'|!@#$%&*()-_=+`{}[]^~<>,./?;:";
    for(i = 0; i < 30; i++){
      ptr->genArray[count] = letters[i];
      count++;
    }
  }
  
  // add a null terminator to the last element of the array
  ptr->genArray[count] = '\0';

  // initialize the random number generator with nanoseconds
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  srand(ts.tv_nsec);
  
  // allocate and generate the characters
  ptr->genChar = malloc(ptr->length);
  for(i = 0; i < ptr->length; i++)
    ptr->genChar[i] = ptr->genArray[rand() % ptr->range];

  // add a null terminator to the last element of the array
  ptr->genChar[i] = '\0';
}
