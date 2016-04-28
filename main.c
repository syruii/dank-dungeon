/* Main line of execution from the program is here.
   Logic has not been fully worked out, and everything is subject to change.
*/

#include "main.h"
// function headers
#include "randint.h"
#include "death.h"
#include "yesno.h"
#include "mapGenerate.h"
#include "entityCheck.h"
#include "moveEntity.h"
#include "entityPopulate.h"
#include "direction.h"
#include "clearLevel.h"
#include "attack.h"
#include "aiTurn.h"
#include "printStatus.h"

int main (int argc, char* argv[]) {
   game gameInfo;
   entity entityInfo[MAX_ENTITIES];
   //printTitle()
   printf("Welcome to Dank Dungeon!\nPlease enter your name (maximum 10 characters): ");
   scanf("%10s",gameInfo.playerName);
   //int playerName;
   //read in playername
   int roomWidth;
   int roomHeight;
   int direction = 0; //not actually a direction

   char mapArray[MAP_SIZE][MAP_SIZE];
   char entityArray[MAP_SIZE][MAP_SIZE];
   clearLevel(mapArray,entityArray,entityInfo);
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
   entityInfo[PLAYER_INDEX].entityHP = randint(10) + 20; //ezy mode
   entityInfo[PLAYER_INDEX].maxHP = entityInfo[PLAYER_INDEX].entityHP;
   entityInfo[PLAYER_INDEX].exp = 0;
   entityInfo[PLAYER_INDEX].expNextLVL = (entityInfo[PLAYER_INDEX].entityLVL * entityInfo[PLAYER_INDEX].entityLVL);
   strncpy(entityInfo[PLAYER_INDEX].entityDescription, "your player", MAX_DESCRIPT_SIZE);
   gameInfo.turn = 1;
   gameInfo.score = 0;
   gameInfo.currentFloor = 1;
   //also change struct to abstract

   while (NOT_DEAD) { //infinite loop for game unless you die or quit (which will assign your death flag to true)
      generateMap(&roomWidth, &roomHeight); //returns to beginning of loop when you complete floor
      placeStairs(mapArray,roomWidth,roomHeight);
      monNumberOnFloor = entityPopulate (entityArray, entityInfo, mapArray, entityInfo[0].entityLVL, roomWidth, roomHeight);
//MOVE THIS LATER, HERE FOR FUNCTIONALITY
//      printStatus(); should be included into printMap
      while ((levelComplete != TRUE) && (NOT_DEAD)) {
         printMap(mapArray, entityArray, roomWidth, roomHeight);
         entityInfo[PLAYER_INDEX].expNextLVL = (entityInfo[PLAYER_INDEX].entityLVL * entityInfo[PLAYER_INDEX].entityLVL);
         printStatus(gameInfo,entityInfo);
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
               death(PLAYER_INDEX,entityArray,entityInfo);
               
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
            } else if (strcmp(command,"wait") == SAME) {
               turnPassed = TRUE;
            } else if (strcmp(command,"descend") == SAME) {
               if (mapArray[entityInfo[PLAYER_INDEX].entityx][entityInfo[PLAYER_INDEX].entityy] == STAIRS) {
                  printf("Are you sure you want to descend? [yes/no]\n");
                  if (getYes() == TRUE) {
                     levelComplete = TRUE;
                     clearLevel(mapArray,entityArray,entityInfo);
                     turnPassed = TRUE;
                     gameInfo.currentFloor++;
                  }
               } else {
                  printf("You aren't standing on the stairs.\n");
               }
            } else {
               printf("Invalid command.\n");
            }
         }
         if (levelComplete == FALSE) { //stops you being attacked when going descending
            aiTurn(entityInfo,entityArray,mapArray,roomWidth,roomHeight,&gameInfo,monNumberOnFloor);
         }
         turnPassed = FALSE;
         gameInfo.turn++;
         entityInfo[PLAYER_INDEX].entityHP += (entityInfo[PLAYER_INDEX].maxHP*PASSIVE_REGEN);
//Prints the hp after each turn end, to see it's not exceeding maxHP, and it's regening
//         printf("hp is now %d",entityInfo[PLAYER_INDEX].entityHP);
         if(entityInfo[PLAYER_INDEX].entityHP > entityInfo[PLAYER_INDEX].maxHP){
            entityInfo[PLAYER_INDEX].entityHP = entityInfo[PLAYER_INDEX].maxHP;
         }
         printf("\n"); //might not be necessary, prints new line after any event to print what will you do?
      }
      levelComplete = FALSE;
   }
   printMap(mapArray, entityArray, roomWidth, roomHeight);
   printf("You have died!\n");
   printf("Your score is %d.\n",gameInfo.score);
      //death checks will occur during monster or player movements
      //monster movements will be a separate function which will walk through the entityInfo array


   return EXIT_SUCCESS;
}
