#include <stdlib.h>
#include <time.h>
#include <array.h>

void arrayCreation(Array *ptr) {
  size_t i;
  
  // calculate the range and allocate
  ptr->range = 0;
  if(ptr->type & LOWER) ptr->range += 26;
  if(ptr->type & UPPER) ptr->range += 26;
  if(ptr->type & NUMBER) ptr->range += 10;
  if(ptr->type & SYMBOL) ptr->range += 30;
  ptr->genArray = malloc(ptr->range + 1);
  
  // copy letters to the array that is used for generating the string
  ptr->count = 0;
  if(ptr->type & LOWER) {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    for(i = 0; i < 26; i++){
      ptr->genArray[ptr->count] = letters[i];
      ptr->count++;
    }
  }
  if(ptr->type & UPPER) {
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(i = 0; i < 26; i++){
      ptr->genArray[ptr->count] = letters[i];
      ptr->count++;
    }
  }
  if(ptr->type & NUMBER) {
    char letters[] = "0123456789";
    for(i = 0; i < 10; i++){
      ptr->genArray[ptr->count] = letters[i];
      ptr->count++;
    }
  }
  if(ptr->type & SYMBOL) {
    char letters[] = "'|!@#$%&*()-_=+`{}[]^~<>,./?;:";
    for(i = 0; i < 30; i++){
      ptr->genArray[ptr->count] = letters[i];
      ptr->count++;
    }
  }
  
  // add a null terminator to the last element of the array
  ptr->genArray[ptr->count] = '\0';

  // initialize the random number generator with nanoseconds
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  srand(ts.tv_nsec);
  
  // allocate and generate the characters
  ptr->genChar = malloc(ptr->length);
  for(ptr->count = 0; ptr->count < ptr->length; ptr->count++)
    ptr->genChar[ptr->count] = ptr->genArray[rand() % ptr->range];

  // add a null terminator to the last element of the array
  ptr->genChar[ptr->length] = '\0';
  
  // counting the size of the array
  for(ptr->count = 0; ptr->genChar[ptr->count] != '\0'; ptr->count++);
}
