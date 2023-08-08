#include <ncurses.h>
#include <array.h>

void arrayCases(Array *ptr) {
  switch(ptr->type) {
    case 1:
      arrayCreation(0, 26, 0, 0, ptr);
      break;

    case 2:
      arrayCreation(26, 52, 0, 0, ptr);
      break;

    case 3:
      arrayCreation(52, 62, 0, 0, ptr);
      break;

    case 4:
      arrayCreation(62, 92, 0, 0, ptr);
      break;

    case 12:
      arrayCreation(0, 52, 0, 0, ptr);
      break;

    case 13:
      arrayCreation(0, 26, 52, 62, ptr);
      break;

    case 14:
      arrayCreation(0, 26, 62, 92, ptr);
      break;

    case 23:
      arrayCreation(26, 62, 0, 0, ptr);
      break;

    case 24:
      arrayCreation(26, 52, 62, 92, ptr);
      break;

    case 34:
      arrayCreation(52, 92, 0, 0, ptr);
      break;

    case 123:
      arrayCreation(0, 62, 0, 0, ptr);
      break;

    case 134:
      arrayCreation(0, 26, 52, 92, ptr);
      break;
    
    case 234:
      arrayCreation(26, 92, 0, 0, ptr);
      break;

    case 1234:
      arrayCreation(0, 92, 0, 0, ptr);
      break;
    
    default:
      printw("Unknown option.\n");
      refresh();
      napms(500);
      arrayType(ptr);
      arrayCases(ptr);
  } 
}