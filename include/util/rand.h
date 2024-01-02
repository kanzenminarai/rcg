#ifndef RAND_H
#define RAND_H

// get random bytes from /dev/urandom through getrandom();
unsigned int getNextRandom(unsigned int max);

#endif // RAND_H
