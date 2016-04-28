//removes all traces of previous level
#include "clearLevel.h"

void clearLevel(char mapArray[MAP_SIZE][MAP_SIZE], char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[MAX_ENTITIES]) {
//for loops for all three arrays
//make sure to wash behind your ears
   int i=0,j=0;
   for (i=0; i < MAP_SIZE; i++) {
      for (j=0; j < MAP_SIZE; j++) {
         mapArray[i][j] = EMPTY_SPACE;
      }
   }
   for (i=0; i < MAP_SIZE; i++) {
      for (j=0; j < MAP_SIZE; j++) {
         entityArray[i][j] = NO_ENTITY;
      }
   }
   for (i=1; i < MAX_ENTITIES; i++) {
      entityInfo[i].dead = TRUE;
   }
}
