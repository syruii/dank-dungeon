//cleans up dead bodies
//takes in a entity index
//called from a death check function which will also hand out the exp
#include "death.h"
#include "main.h"

void death(int deadIndex,char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[MAX_ENTITIES]) {
   entityArray[entityInfo[deadIndex].entityx][entityInfo[deadIndex].entityy] = NO_ENTITY;
   entityInfo[deadIndex].dead = TRUE;
}   




      
