#include "main.h"

//revision required later so that attempted movement into a monster entity results in attack function being called
int move(int roomWidth, int roomHeight, char entityArray[MAP_SIZE][MAP_SIZE], char mapArray[MAP_SIZE][MAP_SIZE], int direction, int entityIndex, entity entityInfo[MAX_ENTITIES]);
//entityx is the x value in the array of the entity, similarly for entityy
