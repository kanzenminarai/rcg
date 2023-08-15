#ifndef ARRAY_H
#define ARRAY_H

#define LOWER 1<<0
#define UPPER 1<<1
#define NUMBER 1<<2
#define SYMBOL 1<<3
#define LETTERS 26
#define NUMBERS 10
#define SYMBOLS 30

typedef struct {
  unsigned int length;
  unsigned short int type;
  char *genChar;
  char *genArray;
} Array;

// creates a array and get the selected range of characters 
void arrayCreation(Array *ptr);

// get the size of the array
void arraySize(Array *ptr);

// get the elements for the array 
void arrayType(Array *ptr);

// prints the output of the generated characters
void arrayOutput(Array *ptr);

#endif // ARRAY_H
