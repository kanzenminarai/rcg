#include <stdlib.h>
#include <limits.h>
#include <sys/random.h>
#include <stdint.h>
#include <rand.h>

// the buffer size BUF_BYTES must be a power of two in this implementation
#define BUF_BYTES (1 << 8) // 256 is chosen as the largest value for getrandom(2) which is guarenteed to never fail
#define BUF_SIZE (BUF_BYTES / sizeof(unsigned int))
#define BUF_MASK (BUF_SIZE - 1)

typedef struct {
  uint64_t offset;
  uint32_t n[BUF_SIZE];
} RandomBuffer;

// initializing buf and offset, buf is a acess variable for the RandomBuffer struct
static RandomBuffer buf = {.offset = 0};

// maximum value is excluded from range
unsigned int getNextRandom(unsigned int exclusiveMax) { 
  uint32_t n = 0;
  
  do {
    if(buf.offset == 0) getrandom(buf.n, BUF_BYTES, 0);
    n = buf.n[buf.offset];
    buf.offset = (buf.offset + 1) & BUF_MASK; 
  } while(n >= UINT_MAX - (UINT_MAX % exclusiveMax)); // reject values that could cause modulo bias
  return n % exclusiveMax;
}
