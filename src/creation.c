#include <stdlib.h>
#include <time.h>
#include <array.h>

void arrayCreation(int array1, int array2, int array3, int array4, Array *ptr) {
  ptr->chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'|!@#$%&*()-_=+`{}[]^~<>,./?;:";
  ptr->range = (array2 - array1) + (array4 - array3);
  ptr->genArray = malloc(ptr->range + 1);

  if(array2 != 0)
    for(ptr->count = 0; array1 < array2; array1++, ptr->count++)
      ptr->genArray[ptr->count] = ptr->chars[array1];

  if(array2 != 0 && array4 != 0)
    for(ptr->count = array2; array3 < array4; array3++, ptr->count++)
      ptr->genArray[ptr->count] = ptr->chars[array3];

  ptr->genArray[ptr->count] = '\0';

  arrayRandom(ptr);
  arraySort(ptr);
}

void arrayRandom(Array *ptr) {
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  ptr->size = (ts.tv_nsec * ptr->count) - ptr->count;
  srand(ptr->size);
}

void arraySort(Array *ptr) {
  ptr->genChar = malloc(ptr->length);
  for(ptr->count = 0; ptr->count < (ptr->length); ptr->count++) {
    ptr->size = rand() % ptr->range;
    ptr->genChar[ptr->count] = ptr->genArray[ptr->size];
  }
  ptr->genChar[ptr->length] = '\0';
  for(ptr->count = 0; ptr->genChar[ptr->count] != '\0'; ptr->count++);
}

void arrayFree(Array *ptr) {
  free(ptr->genArray);
  free(ptr->genChar);
}