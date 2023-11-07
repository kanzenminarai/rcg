#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array.h>
#include <cli.h>

// simple implementation of the atoi(), it "converts" ascii number range to integer
int anti(char *string) {
  uint8_t count = 0, result = 0;
  char sign = 1; // 1 == positive

  if(string[0] == '-') count++, sign = -1; // skips the signal if exists and sign gets -1 which equals negative
  for(; (string[count] >= '0') && (string[count] <= '9'); count++) result = (result * 10) + (string[count] - '0');
  return result * sign;
}

// command line interface for rcg
void cli(char **argv, Array *ptr) {
  char *str = argv[3];

  // compares if "help" is the same as the argument 1 on argv
  if(strcmp("help", argv[1]) == 0) {
    printf("Usages: rcg, rcg help, rcg generate [size] [type]\n\n"
      "Command:\n"
      "help      prints informations about rcg\n"
      "generate  generates characters using the size and type\n\n"
      "Instructions:\n"
      "Size must be a positive number from 1 up to 32767\n"
      "Type must be one or more options from 1 up to 4, any order\n");
  }
  
  if(strcmp("generate", argv[1]) == 0) {
    // get the size
    ptr->length = anti(argv[2]);
    
    /* copies the argv[3] string to *str to make a convertion,
    after that it is passed as argument to charOptions() */
    strcpy(str, argv[3]);
    charOptions(str, ptr);
    arrayCreation(ptr);

    // print the characters
    printf("%s\n", ptr->genChar);
    
    // free the memory after usage
    free(ptr->genChar);
  }
  // if it is a unknown input, shows a error message
  else if(strcmp("help", argv[1]) != 0) printf("Unknown usage, use \"help\" argument\n");
}