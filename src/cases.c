#include <ncurses.h>
#include <array.h>

void arrCases(arrTyp *ptr) {
  switch((ptr->type)) {
    case 1:
      arrCreation(0, 26, 0, 0, ptr);
      break;

    case 2:
      arrCreation(26, 52, 0, 0, ptr);
      break;

    case 3:
      arrCreation(52, 62, 0, 0, ptr);
      break;

    case 4:
      arrCreation(62, 92, 0, 0, ptr);
      break;

    // Combined cases

    case 12:
      arrCreation(0, 52, 0, 0, ptr);
      break;

    case 13:
      arrCreation(0, 26, 52, 62, ptr);
      break;

    case 14:
      arrCreation(0, 26, 62, 92, ptr);
      break;

    case 123:
      arrCreation(0, 62, 0, 0, ptr);
      break;

    case 134:
      arrCreation(0, 26, 52, 92, ptr);
      break;

    case 1234:
      arrCreation(0, 92, 0, 0, ptr);
      break;

    case 23:
      arrCreation(26, 62, 0, 0, ptr);
      break;

    case 234:
      arrCreation(26, 92, 0, 0, ptr);
      break;

    case 24:
      arrCreation(26, 52, 62, 92, ptr);
      break;

    case 34:
      arrCreation(52, 92, 0, 0, ptr);
      break;

    default:
      printw("Unknown option, please use the ascending order.\n");
      refresh();
      napms(2500);
      arrType(ptr);
      arrCases(ptr);
  }
}