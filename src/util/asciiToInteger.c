#include <stdint.h>
#include "util/string.h"
#define POSITIVE 1
#define NEGATIVE -1
#define BASE_TEN 10

int asciiToInteger(char *string) {
  uint32_t convertedString = 0;
  uint16_t counter = 0;
  char signal = POSITIVE;
  if(string[0] == '-') counter++, signal = NEGATIVE;
  while(string[counter] != '\0') {
    if(string[counter] >= '0' && string[counter] <= '9')
      convertedString = (convertedString * BASE_TEN) + (string[counter] - '0');
    counter++;
  }
  return convertedString * signal;
}
