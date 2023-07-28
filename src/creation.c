#include <stdlib.h>
#include <array.h>

void arrCreation(int arrStrt, int arrEnd, int arrStrt1, int arrEnd1, arrTyp *ptr) {
  ptr->chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'|!@#$%&*()-_=+`{}[]^~<>,./?;:";
  ptr->range = (arrEnd - arrStrt) + (arrEnd1 - arrStrt1);

  ptr->genArr = malloc(ptr->range);
  
  if(arrEnd != 0) {
    for(ptr->counter = 0; arrStrt < arrEnd; arrStrt++, ptr->counter++)
      ptr->genArr[ptr->counter] = ptr->chars[arrStrt];
  }

  if(arrEnd != 0 && arrEnd1 != 0) { 
    for(ptr->counter = arrEnd; arrStrt1 < arrEnd1; arrStrt1++, ptr->counter++) 
      ptr->genArr[ptr->counter] = ptr->chars[arrStrt1];
  }
  ptr->genArr[ptr->counter] = '\0';

  arrAttr(ptr);
}

void arrAttr(arrTyp *ptr) {
  ptr->genChar = malloc(ptr->length);
  for(ptr->counter = 0; ptr->counter < (ptr->length); ptr->counter++) {
    ptr->size = rand() % ptr->range;
    ptr->genChar[ptr->counter] = ptr->genArr[ptr->size];
  }
  ptr->genChar[ptr->length] = '\0';
  for(ptr->counter = 0; ptr->genChar[ptr->counter] != '\0'; ptr->counter++);
}