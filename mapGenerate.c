/* This includes the functions for printing the map and generating the map
   Program written on 8/04/15
   revised on 04/05 with addition of stair placement
*/

#include "mapGenerate.h"
#include <stdio.h>
#include "main.h"

/*
int main () {
   int i=0,j=0;
   char mapArray[15][15];
   for (i = 0; i < MAP_SIZE; i++) {            //populates array with empty tiles
      for (j = 0; j < MAP_SIZE; j++) {
         mapArray[i][j] = '.'; 
      }
   }
   int roomWidth;
   int roomHeight;
   generateMap(&roomWidth, &roomHeight);
   printMap(mapArray,roomWidth,roomHeight);
   return EXIT_SUCCESS;
}
*/
//This main function is for testing purposes only.

void printMap(char mapArray[MAP_SIZE][MAP_SIZE], char entityArray[MAP_SIZE][MAP_SIZE], int roomWidth, int roomHeight) {
   int widthcount = 0;
   int heightcount = 0;
   printHorizontalBound(roomWidth);
   printf("\n");

   while (heightcount < roomHeight) {
      printf(VERTICAL_WALL);
      while (widthcount < roomWidth) {
         if (entityArray[widthcount][heightcount] == NO_ENTITY) {
            printf("%c",mapArray[widthcount][heightcount]);
         } else {
            printf("%c",entityArray[widthcount][heightcount]);
         }
         widthcount++;
      }
      printf(VERTICAL_WALL);
      printf("\n");
      widthcount = 0;
      heightcount++;
   }

   printHorizontalBound(roomWidth);
   printf("\n");

   return;
}

void generateMap(int* width, int* height) { //generates random dimensions of room
   srand(time(NULL));
   *width = randint(12) + 3;
   *height = randint(12) +3;
//   printf("%d, %d", *width, *height);
   return;
}


void printHorizontalBound(int roomWidth) {
   int widthcount = 0;
   printf(" ");
   while (widthcount < roomWidth) {
      printf(HORIZONTAL_WALL);
      widthcount++;
   }
   return;
}

void placeStairs(char mapArray[MAP_SIZE][MAP_SIZE], int roomWidth, int roomHeight) {
   mapArray[randint(roomWidth)][randint(roomHeight)] = STAIRS;
}
