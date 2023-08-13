#ifndef ARRAY_H
#define ARRAY_H

#define T_LOWER 1<<0
#define T_UPPER 1<<1
#define T_NUMBER 1<<2
#define T_SYMBOL 1<<3

typedef struct {
  int size;
  int range;
  int count;
  unsigned int length;
  unsigned short int type;
  char *genChar;
  char *genArray;
  char *chars;
  char choice;
} Array;

// creates a array and get the selected range of characters 
void arrayCreation(Array *ptr);

// sorts the elements of the generated array in arrayCreation()
void arraySort(Array *ptr);

// get the size of the array
void arraySize(Array *ptr);

// get the elements for the array 
void arrayType(Array *ptr);

// prints the output of the generated characters
void arrayOutput(Array *ptr);

// get a seed for srand() according to Unix Time in nanoseconds
void arrayGetNano(Array *ptr);

#endif // ARRAY_H
