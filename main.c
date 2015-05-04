/* Main line of execution from the program is here.
   Logic has not been fully worked out, and everything is subject to change.
*/

//IMPORTANT NOTE : ENCOUNTERED SITUATION WHEN '+' TO LEFT OF PLAYER CHARACTER WAS NOT ABLE TO BE ATTACKED 01/05

#define NO_ENTITY '0'
#define EMPTY_SPACE '.'
#define TRUE 1
#define FALSE -1

#define SAME 0
//stupid strcmp

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

// standard libraries
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

//definitions for MAXARRAYSIZE
#define MAP_SIZE 15
#define MAX_ENTITIES 8 //player, 6 normal mobs and a boss sometimes
#define MAX_ENTITY_PROPERTIES 5
#define MAX_DESCRIPT_SIZE 25

#define NOT_DEAD entityInfo[0].dead == FALSE

#define PLAYER_INDEX 0
#define PLAYER_CHAR '@'

//definitions for entity/Info struct
typedef struct _entity {
   char entitySymbol;
   char entityDescription[MAX_DESCRIPT_SIZE];
   int entityHP;
   int entityLVL;
   int baseDamage;
   int entityx; //yes i could use unsigned char but whatever
   int entityy;
   int dead;
} entity;

typedef struct _game {
   char playerName[10];
   int score;
   int turn;
   int currentFloor;
   int skills[20];
} game;

//maybe will organise into structs

// function headers
#include "randint.h"
#include "death.h"
#include "mapGenerate.h"
#include "entityCheck.h"
#include "moveEntity.h"
#include "entityPopulate.h"
#include "direction.h"
#include "attack.h"
#include "aiTurn.h"

int main (int argc, char* argv[]) {
   game gameInfo;
   entity entityInfo[MAX_ENTITIES];
   //printTitle()
   //int playerName; 
   //read in playername
   int roomWidth;
   int roomHeight;
   int direction = 0; //not actually a direction
   
   int i=0,j=0;
   char mapArray[MAP_SIZE][MAP_SIZE];
   for (i = 0; i < MAP_SIZE; i++) {            //populates mapArray with empty tiles
      for (j = 0; j < MAP_SIZE; j++) {
         mapArray[i][j] = EMPTY_SPACE;
      }
   }
   
   char entityArray[MAP_SIZE][MAP_SIZE];
   for (i = 0; i < MAP_SIZE; i++) {            //populates entityArray with no entities on the map
      for (j = 0; j < MAP_SIZE; j++) {
         entityArray[i][j] = NO_ENTITY;
      }
   }

/* ~~~~~
  test for entityPopulate
   ~~~~~ */
/* TEST WAS PASSED 
   generateMap (&roomWidth, &roomHeight);
   printf("Height of room should be %d, Width should be %d\n", roomHeight, roomWidth);
   entityPopulate (entityArray, entityInfo, mapArray, playerLevel, roomWidth, roomHeight);
   printMap (mapArray, entityArray, roomWidth, roomHeight);
   // ENTITY SYMBOL | ENTITY X | ENTITY Y | ENTITY LVL | ENTITY HP
   // possibly other stuff, row 0 will always be player unsigned character
   // consider it a database with the primary key being entity symbol

*/
   int turnPassed = FALSE; 
   char command [10]; //string store for the command, set to maximum character of 9 now, can hold any command since no need to remember
   int levelComplete = FALSE;
   int monNumberOnFloor = 0;
   //initialise player, lvl, damage and HP will change during LVLup, change struct into abstract
   entityInfo[PLAYER_INDEX].dead = FALSE;
   entityInfo[PLAYER_INDEX].entityLVL = 1;
   entityInfo[PLAYER_INDEX].entitySymbol = PLAYER_CHAR;
   entityInfo[PLAYER_INDEX].baseDamage = 4 + randint(2);
   entityInfo[PLAYER_INDEX].entityHP = randint(10) + 18; //ezy mode
   strncpy(entityInfo[PLAYER_INDEX].entityDescription, "your player", MAX_DESCRIPT_SIZE);
   gameInfo.turn = 0;
   gameInfo.score = 0;
   //also change struct to abstract
   
   while (NOT_DEAD) { //infinite loop for game unless you die or quit (which will assign your death flag to true)
      generateMap(&roomWidth, &roomHeight); //returns to beginning of loop when you complete floor
      monNumberOnFloor = entityPopulate (entityArray, entityInfo, mapArray, entityInfo[0].entityLVL, roomWidth, roomHeight);
      //printStatus() should be included into printMap      
      while ((levelComplete != TRUE) && (NOT_DEAD)) {
         printMap(mapArray, entityArray, roomWidth, roomHeight);
         // get command (look at wiki for commands) from keyboard
         // stacked else ifs for all commands that lead to their own function
         // else print "Invalid command"
         //e.g
         
         //while turnPassed == FALSE
         while ((turnPassed == FALSE) && (NOT_DEAD)) {
            printf("What will you do?\n"); //awaiting response
            scanf("%9s",command);
            printf("\n");
            if (strcmp(command,"up") == SAME) {
               if (move(roomWidth,roomHeight,entityArray,mapArray,UP,PLAYER_INDEX,entityInfo) == TRUE) {
                  printf("You move up.\n");
                  turnPassed = TRUE;
               } else {
                  printf("You can't move there!\n");
               }
         //inventory system will print out another screen and have a similar infinite loop
         //right now I think that at the end of the resolutions of all the legal commands, then the map and status screen
         //should be reprinted 
            } else if (strcmp(command, "down") == SAME) {
               if (move(roomWidth,roomHeight,entityArray,mapArray,DOWN,PLAYER_INDEX,entityInfo) == TRUE) {
                  printf("You move down.\n");
                  turnPassed = TRUE;
               } else {
                  printf("You can't move there!\n");
               }
            } else if(strcmp(command, "right") == SAME) {
               if (move(roomWidth,roomHeight,entityArray,mapArray,RIGHT,PLAYER_INDEX,entityInfo) == TRUE) {
                  printf("You move right.\n");
                  turnPassed = TRUE;
               } else {
                  printf("You can't move there!\n");
               }
            } else if(strcmp(command, "left") == SAME) {
               if (move(roomWidth,roomHeight,entityArray,mapArray,LEFT,PLAYER_INDEX,entityInfo )== TRUE) {
                  printf("You move left.\n");
                  turnPassed = TRUE;
               } else {
                  printf("You can't move there!\n");
               }
         //} else if(strcmp(comand, "attack") == SAME) {
         //   prinf("Attack in which direction?\n");
         //   scanf("%9s"
            } else if (strcmp(command, "kill") == SAME) {
               printf("You commit sudoku :(\n");
               entityInfo[PLAYER_INDEX].dead = TRUE;
            } else if (strcmp(command,"attack") == SAME) {
                  printf("Attack in which direction?\n");
                  direction = getDirection();
                  if (direction != -1) {
                     if (attack(PLAYER_INDEX,direction,entityArray,entityInfo,&gameInfo) == FALSE) {
                        printf("There is nothing to attack!\n");
                     } else {
                        turnPassed = TRUE;
                     }
                  }
               
            } else {
               printf("Invalid command.\n");
            }
            printf("\n"); //might not be necessary, prints new line after any event to print what will you do?
         }
         aiTurn(entityInfo,entityArray,mapArray,roomWidth,roomHeight,&gameInfo,monNumberOnFloor);
         turnPassed = FALSE;
         gameInfo.turn++;
      }
   }
   printf("You have died!\n");
   printf("Your score is %d.\n",gameInfo.score);
      //death checks will occur during monster or player movements
      //monster movements will be a separate function which will walk through the entityInfo array          


   return EXIT_SUCCESS;
}
