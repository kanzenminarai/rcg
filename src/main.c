#include "cli.h"
#include "tui.h"

int checkCommandLineArgument(int argc, char **argv) {
  Array ar;
  if(argc > 1) {
    ar.argumentCount = argc;
    cliMain(argv, &ar);
    return 0;
  }
  tuiMain(&ar);
  return 0;
}

int main(int argc, char **argv) {
  checkCommandLineArgument(argc, argv);
  return 0;
}
