#ifndef ENITTY_H
#define ENTITY_H

#define NO_ENTITY '0'
#define BASE_HP 8

void generatePosition (int roomWidth, int roomHeight, int* posx, int* posy);
void placeMonster (char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[], char mapArray[MAP_SIZE][MAP_SIZE], int roomWidth, int roomHeight, int monNumber);
void generateMonster (char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[], int playerLevel, int monNumber);
void placePlayer (char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[], char mapArray[MAP_SIZE][MAP_SIZE], int roomWidth, int roomHeight);


#endif
