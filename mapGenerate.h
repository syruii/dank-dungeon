#ifndef MAP_H
#define MAP_H

#include <time.h>

#define VERTICAL_WALL "|"
#define HORIZONTAL_WALL "-"
#define MAP_SIZE 15

void printMap(char mapArray[MAP_SIZE][MAP_SIZE], char entityArray[MAP_SIZE][MAP_SIZE], int roomWidth, int roomHeight);  //have to pass second dimension of array
//void generateMap(int* Width, int* Height);
void printHorizontalBound(int roomWidth);
//void placeStairs(char mapArray, int roomWidth, int roomHeight);

#endif
