#include <stdlib.h>
#include <limits.h>
#include <sys/random.h>
#include <rand.h>

// the buffer size BUF_BYTES must be a power of two in this implementation
// 256 is chosen because it's the largest value where getrandom(2) is guarenteed to never fail
#define BUF_BYTES (1 << 8)
#define BUF_SIZE (BUF_BYTES / sizeof(unsigned int))
#define BUF_MASK (BUF_SIZE - 1)

typedef struct {
  size_t offset;
  unsigned int n[BUF_SIZE];
} RandomBuffer;

static RandomBuffer buf = {.offset = 0};

// maximum value is excluded from range
unsigned int getNextRandom(unsigned int exclusive_max) {
  unsigned int n;
  do {
    if (buf.offset == 0) getrandom(buf.n, BUF_BYTES, 0);
    n = buf.n[buf.offset];
    buf.offset = (buf.offset + 1) & BUF_MASK; 
  } while (n >= UINT_MAX - (UINT_MAX % exclusive_max)); // reject values that could cause modulo bias
  return n % exclusive_max;
}
