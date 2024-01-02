#include <stdlib.h>
#include <ncurses.h>
#include "array.h"
#include "util/rand.h"
#define LOWER 1 << 0
#define UPPER 1 << 1
#define NUMBER 1 << 2
#define SYMBOL 1 << 3
#define LETTERS_RANGE 26
#define NUMBERS_RANGE 10
#define SYMBOLS_RANGE 31
#define NULLCHAR 1
#define EOT '\04'

void characterTypeAttributionCases(char *option, Array *ptr) {
  ptr->wrongInput = false;
  ptr->characterType = 0;
  for(uint8_t counter = 0; option[counter]; counter++) {
    switch(option[counter]) {
      case 'l':
        ptr->characterType |= LOWER;
        break;

      case 'u':
        ptr->characterType |= UPPER;
        break;

      case 'n':
        ptr->characterType |= NUMBER;
        break;

      case 's':
        ptr->characterType |= SYMBOL;
        break;

      default:
        if(option[counter] != EOT) ptr->wrongInput = true;
        break;
    }
  }
}

void charactersRangeAttribution(Array *ptr) {
  ptr->arrayRange = 0;
  if(ptr->characterType & LOWER) ptr->arrayRange += LETTERS_RANGE;
  if(ptr->characterType & UPPER) ptr->arrayRange += LETTERS_RANGE;
  if(ptr->characterType & NUMBER) ptr->arrayRange += NUMBERS_RANGE;
  if(ptr->characterType & SYMBOL) ptr->arrayRange += SYMBOLS_RANGE;
  ptr->generatedArray = malloc(ptr->arrayRange + NULLCHAR);
}

void characterTypeAttribution(Array *ptr) {
  uint16_t charactersSize = 0, arraySize = 0;
  char *characters = NULL;
  if(ptr->characterType & LOWER) {
    characters = "abcdefghijklmnopqrstuvwxyz";
    for(charactersSize = 0; charactersSize < LETTERS_RANGE; arraySize++, charactersSize++)
      ptr->generatedArray[arraySize] = characters[charactersSize];
  }
  if(ptr->characterType & UPPER) {
    characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(charactersSize = 0; charactersSize < LETTERS_RANGE; arraySize++, charactersSize++)
      ptr->generatedArray[arraySize] = characters[charactersSize];
  }
  if(ptr->characterType & NUMBER) {
    characters = "0123456789";
    for(charactersSize = 0; charactersSize < NUMBERS_RANGE; arraySize++, charactersSize++)
      ptr->generatedArray[arraySize] = characters[charactersSize];
  }
  if(ptr->characterType & SYMBOL) {
    characters = "\"'|!@#$%&*()-_=+`{}[]^~<>,./?;:";
    for(charactersSize = 0; charactersSize < SYMBOLS_RANGE; arraySize++, charactersSize++)
      ptr->generatedArray[arraySize] = characters[charactersSize];
  }
  ptr->generatedArray[arraySize] = '\0';
}

void characterGeneration(Array *ptr) {
  uint32_t size = 0;
  ptr->generatedChararacters = malloc(ptr->characterLength + NULLCHAR);
  for(size = 0; size < ptr->characterLength; size++)
    ptr->generatedChararacters[size] = ptr->generatedArray[getNextRandom(ptr->arrayRange)];
  free(ptr->generatedArray);
  ptr->generatedChararacters[size] = '\0';
}

void arrayMain(Array *ptr) {
  charactersRangeAttribution(ptr);
  characterTypeAttribution(ptr);
  characterGeneration(ptr);
}
