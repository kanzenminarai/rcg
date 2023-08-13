#ifndef ARRAY_H
#define ARRAY_H

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
void arrayCreation(int array1, int array2, int array3, int array4, Array *ptr);

// sorts the elements of the generated array in arrayCreation()
void arraySort(Array *ptr);

// get the size of the array
void arraySize(Array *ptr);

// get the elements for the array 
void arrayType(Array *ptr);

// switch between the case options
void arrayCases(Array *ptr);

// prints the output of the generated characters
void arrayOutput(Array *ptr);

// get a seed for srand() according to Unix Time in nanoseconds
void arrayGetNano(Array *ptr);

#endif // ARRAY_H
