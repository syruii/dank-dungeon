#ifndef AITURN_H
#define AITURN_H

int abs(int a);
int aiPath(entity entityInfo[MAX_ENTITIES], char entityArray[MAP_SIZE][MAP_SIZE], int monsterIndex); //always returns a valid direction
int playerDistanceSquared (entity entityInfo[MAX_ENTITIES], int monsterIndex);

#endif
