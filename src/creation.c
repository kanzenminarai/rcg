#include <stdlib.h>
#include <time.h>
#include <array.h>

void arrayCreation(int array1, int array2, int array3, int array4, Array *ptr) {
  ptr->chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'|!@#$%&*()-_=+`{}[]^~<>,./?;:";
  
  // getting the range and allocating to the memory
  ptr->range = (array2 - array1) + (array4 - array3);
  ptr->genArray = malloc(ptr->range + 1);

  // attributes if the value is !=0
  if(array2 != 0)
    for(ptr->count = 0; array1 < array2; array1++, ptr->count++) // counts if array1 is lower than array2
      ptr->genArray[ptr->count] = ptr->chars[array1];

  // attributes if both values are != 0
  if(array2 != 0 && array4 != 0)
    for(ptr->count = array2; array3 < array4; array3++, ptr->count++)
      ptr->genArray[ptr->count] = ptr->chars[array3];
  
  // adding a null value to the last element of the array
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
