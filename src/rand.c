#include <stdlib.h>
#include <limits.h>
#include <sys/random.h>
#include <rand.h>

#define BUFSIZE (1<<8)
#define BUFELEMENTS (BUFSIZE/sizeof(unsigned int))

typedef struct {
  size_t ptr;
  union {
    char c[BUFSIZE];
    unsigned int n[BUFELEMENTS];
  } b;
} RandomBuffer;

static RandomBuffer buf = { .ptr = 0 };

// This uses the getrandom(2) syscall to generate random bytes, and then returns
// them as integers in the desired range.
// getrandom(2) doesn't return any number on its own, but simply fills a buffer with random bytes.
//
// The buffer is 256 bytes as this is the largest value where getrandom(2) is guarenteed to never fail.
unsigned int getNextRandom(unsigned int max) {
  unsigned int n;
  do {
    // only refill the buffer once expended to reduce the number of potentially expensive syscalls made
    if (buf.ptr == 0) getrandom(buf.b.c, BUFSIZE, 0); 

    n = buf.b.n[buf.ptr]; // get next random number from buffer

    // increment the pointer, mod number of elements
    // using AND is the same as modulo *as long as BUFELEMENTS is a power of two*, and much faster
    buf.ptr = (buf.ptr + 1) & (BUFELEMENTS - 1); 

  } while (n >= UINT_MAX - (UINT_MAX % max)); // reject values that would create modulo bias
  return n % max;
}
