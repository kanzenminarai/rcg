#ifndef ARRAY_H
#define ARRAY_H

typedef struct arrTyp{
  int length;
  int size;
  int type;
  int counter;
  int range;
  char *genChar;
  char *genArr;
  char *chars;
  char choice;
} arrTyp;

// creates an array using *chars and selects a range according to arrType() input 
void arrCreation(int arrStrt, int arrEnd, int arrStrt1, int arrEnd1, arrTyp *ptr);

// sorts the elements of the generated array in arrCreation() and inserts in this function array 
void arrAttr(arrTyp *ptr);

// inserts the size of the array according to the input
void arrSize(arrTyp *ptr);

// insert which elements the array should have according to the input
void arrType(arrTyp *ptr);

// switch between the options according to the input on arrType(arrTyp *ptr)
void arrCases(arrTyp *ptr);

// prints the output of the generated characters
void arrOutput(arrTyp *ptr);

// repeat all or some process of rcg
void arrRepeat(arrTyp *ptr);


#endif // ARRAY_H