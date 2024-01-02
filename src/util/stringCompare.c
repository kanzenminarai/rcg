#include <stdint.h>
#include "util/string.h"

int stringCompare(char *target, char *source) {
  uint32_t counter = 0, comparedStrings = 0;
  while(target[counter] == source[counter] && target[counter]) counter++;
  comparedStrings = target[counter] - source[counter];
  return comparedStrings;
}
