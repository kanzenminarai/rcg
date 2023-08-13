#include <stdlib.h>
#include <time.h>
#include <array.h>

void arrayCreation(Array *ptr) {
  size_t i;
  
  // calculate the range and allocate
  ptr->range = 0;
  if (ptr->type & T_LOWER) ptr->range += 26;
  if (ptr->type & T_UPPER) ptr->range += 26;
  if (ptr->type & T_NUMBER) ptr->range += 10;
  if (ptr->type & T_SYMBOL) ptr->range += 30;
  ptr->genArray = malloc(ptr->range + 1);
  
  // copy letters to the array that is used for generating the string
  ptr->count = 0;
  if (ptr->type & T_LOWER) {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    for(i = 0; i < 26; i++){
      ptr->genArray[ptr->count] = letters[i];
      ptr->count++;
    }
  }
  if (ptr->type & T_UPPER) {
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(i = 0; i < 26; i++){
      ptr->genArray[ptr->count] = letters[i];
      ptr->count++;
    }
  }
  if (ptr->type & T_NUMBER) {
    char letters[] = "0123456789";
    for(i = 0; i < 10; i++){
      ptr->genArray[ptr->count] = letters[i];
      ptr->count++;
    }
  }
  if (ptr->type & T_SYMBOL) {
    char letters[] = "'|!@#$%&*()-_=+`{}[]^~<>,./?;:";
    for(i = 0; i < 30; i++){
      ptr->genArray[ptr->count] = letters[i];
      ptr->count++;
    }
  }
  
  // add a null terminator to the last element of the array
  ptr->genArray[ptr->count] = '\0';

  arrayGetNano(ptr);
  arraySort(ptr);
}

void arrayGetNano(Array *ptr) {
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  srand(ts.tv_nsec); // attributing the seed number in nanoseconds
}

void arraySort(Array *ptr) {
  // allocating memory according to the size
  ptr->genChar = malloc(ptr->length); 

  // attributing the positions get in rand() into ptr->size
  for(ptr->count = 0; ptr->count < (ptr->length); ptr->count++) {
    ptr->size = rand() % ptr->range;
    ptr->genChar[ptr->count] = ptr->genArray[ptr->size];
  }

  // adding a null value to the last element of the array
  ptr->genChar[ptr->length] = '\0'; 
  
  // counting the size of the array
  for(ptr->count = 0; ptr->genChar[ptr->count] != '\0'; ptr->count++);
}
