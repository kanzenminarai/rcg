#include <stdlib.h>
#include <limits.h>
#include <sys/random.h>
#include <stdint.h>
#include "util/rand.h"

// the buffer size BUF_BYTES must be a power of two in this implementation
#define BUFFER_BYTES (1 << 8) // 256 is chosen as the largest value for getrandom(2) which is guarenteed to never fail
#define BUFFER_SIZE (BUFFER_BYTES / sizeof(uint32_t))
#define BUFFER_MASK (BUFFER_SIZE - 1)

typedef struct {
  uint64_t offset;
  uint32_t n[BUFFER_SIZE];
} RandomBuffer;

static RandomBuffer buffer = {.offset = 0};

// maximum value is excluded from range
unsigned int getNextRandom(unsigned int exclusiveMax) {
  uint32_t counter = 0;
  do {
    if(buffer.offset == 0) getrandom(buffer.n, BUFFER_BYTES, 0);
    counter = buffer.n[buffer.offset];
    buffer.offset = (buffer.offset + 1) & BUFFER_MASK;
  } while(counter >= UINT_MAX - (UINT_MAX % exclusiveMax)); // reject values that could cause modulo bias
  return counter % exclusiveMax;
}
