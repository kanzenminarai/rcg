#ifndef VAR_H
#define VAR_H

#include <stdint.h>
#include <stdbool.h>

typedef struct Array {
  bool wrongInput;
  uint8_t arrayRange;
  uint16_t characterLength;
  uint16_t characterType;
  char *generatedChararacters;
  char *generatedArray;
  uint8_t argumentCount : 3;
} Array;

#endif // VAR_H
