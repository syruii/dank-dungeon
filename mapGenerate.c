/* This includes the functions for printing the map and generating the map
   Program written on 8/04/15
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

#define VERTICAL_WALL "|"
#define HORIZONTAL_WALL "-"
#define MAP_SIZE 15

void printMap(char mapArray[][MAP_SIZE], int roomWidth, int roomHeight);  //have to pass second dimension of array
void generateMap(int* Width, int* Height);
int randint(int n);
void printHorizontalBound(int roomWidth);

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

void printMap(char mapArray[][MAP_SIZE], int roomWidth, int roomHeight) {
   int widthcount = 0;
   int heightcount = 0;
   printHorizontalBound(roomWidth);
   printf("\n");

   while (heightcount < roomHeight) {
      printf(VERTICAL_WALL);
      while (widthcount < roomWidth) {
         printf("%c",mapArray[heightcount][widthcount]);
         widthcount++;
      }
      printf(VERTICAL_WALL);
      printf("\n");
      widthcount = 0;
      heightcount++;
   }

   printHorizontalBound(roomWidth);
   printf("\n")

   return;
}

void generateMap(int* width, int* height) { //generates random dimensions of room
   srand(time(NULL));
   *width = randint(12) + 3;
   *height = randint(12) +3;
//   printf("%d, %d", *width, *height);
   return;
}


int randint(int n) { //does this random function even work - it does
   if ((n-1) == RAND_MAX) {
      return rand();
   } else {
      long end = RAND_MAX / n;
      assert (end > 0L);
      end *=n;
      int r;
      while ((r = rand()) >= end);

      return r % n;
   }
}

void printHorizontalBound(int roomWidth) {
   int widthcount = 0;
   while (widthcount < roomWidth) {
      printf(HORIZONTAL_WALL);
      widthcount++;
   }
   return;
}/
