#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "cli.h"
#include "util/string.h"
#define ALL_ARGS 4
#define NO_SIZE_ARG -2
#define NO_TYPE_ARG -1
#define SIZE_VERIFIED 1
#define TYPE_VERIFIED 2
#define SECOND_ARG 2
#define THIRD_ARG 3

void cliOptionHelp() {
  printf("usages: rcg, rcg help, rcg char [size] [type]\n\n"
    "commands:\n"
    "help  prints informations about rcg\n"
    "char  generates characters using the size and type specified\n\n"
    "char options:\n"
    "l  generates ASCII lower case letters\n"
    "u  generates ASCII upper case letters\n"
    "n  generates ASCII decimal base numbers\n"
    "s  generates ASCII symbols\n");
}

void cliArrayGeneration(char **argv, Array *ptr) {
    ptr->characterLength = asciiToInteger((char *) argv[2]);
    char *charactersType = (char *) argv[3];
    characterTypeAttributionCases(charactersType, ptr);
    arrayMain(ptr);
}

int checkArgument(char **argv, Array *ptr) {
  int check = 0, validInput0 = 0, validInput1 = 0, counter = 0;
  char *checkArgumentThree = (char *) argv[2];
  char *checkArgumentFour = (char *) argv[3];
  if(ptr->argumentCount == SECOND_ARG) check = NO_SIZE_ARG;
  if(ptr->argumentCount == THIRD_ARG) check = NO_TYPE_ARG;
  if(ptr->argumentCount == ALL_ARGS) {
    while(checkArgumentThree[counter] != '\0') {
      if(checkArgumentThree[counter] >= '0' && checkArgumentThree[counter] <= '9') validInput0++;
      counter++;
    }
    if(validInput0 == counter) check = SIZE_VERIFIED;
    counter = 0;
    while(checkArgumentFour[counter] != '\0') {
      if(checkArgumentFour[counter] == 'l' || checkArgumentFour[counter] == 'u') validInput1++;
      if(checkArgumentFour[counter] == 'n' || checkArgumentFour[counter] == 's') validInput1++;
      counter++;
    }
    if(validInput1 == counter) check = check + TYPE_VERIFIED;
  }
  return check;
}

void checkArgumentReturnValue(char **argv, int value, Array *ptr) {
  if(value == 3) {
    cliArrayGeneration(argv, ptr);
    printf("%s\n", ptr->generatedChararacters);
    free(ptr->generatedChararacters);
  }
  if(value == 2) printf("Unknown size selected\n");
  if(value == 1) printf("Unknown type selected\n");
  if(value == 0) printf("Unknown options selected\n");
  if(value == -1) printf("No type selected\n");
  if(value == -2) printf("No size selected\n");
}

void cliOptionChar(char **argv, Array *ptr) {
  int value = 0;
  value = checkArgument(argv, ptr);
  checkArgumentReturnValue(argv, value, ptr);
}

void compareStringToArgument(char **argv, Array *ptr) {
  if(stringCompare("help", argv[1]) == 0) cliOptionHelp();
  if(stringCompare("char", argv[1]) == 0) cliOptionChar(argv, ptr);
  if((stringCompare("help", argv[1]) != 0) && (stringCompare("char", argv[1]) != 0))
    printf("Unknown option, use [%s help] argument\n", argv[0]);
}

void cliMain(char **argv, Array *ptr) {
  compareStringToArgument(argv, ptr);
}
