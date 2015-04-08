/* Main line of execution from the program is here.
   Logic has not been fully worked out, and everything is subject to change.
*/

#define NO_ENTITY '0'
#define EMPTY_SPACE '.'
#define TRUE 1
#define FALSE 0

// #include <subroutines.c>
#include <mapGenerate.c>
#include <moveEntity.c>

// standard libraries
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

//definitions for MAXARRAYSIZE
#define MAP_SIZE 15
#define MAX_ENTITIES 8
#define MAX_ENTITY_PROPERTIES 5

//definitions for entityInfo array
#define ENTITY_SYMBOL 0
#define ENTITY_X 1
#define ENTITY_Y 2
#define ENTITY_LVL 3
#define ENTITY_HP 4

int main (int argc, char* argv[]) {
   //printTitle()
   int playerName;
   //read in playername
   int roomWidth;
   int roomHeight;
   
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
         mapArray[i][j] = NO_ENTITY;
      }
   }

   char entityInfo[MAX_ENTITY_PROPERTIES][MAX_ENTITIES];  
   for (i = 0; i < MAX_ENTITY_PROPERTIES; i++) {            //populates entityInfo with no entities
      for (j = 0; j < MAX_ENTITIES; j++) {
         mapArray[i][j] = NO_ENTITY;
      }
   }
   // ENTITY SYMBOL | ENTITY X | ENTITY Y | ENTITY LVL | ENTITY HP
   // possibly other stuff, row 0 will always be player character
   // consider it a database with the primary key being entity symbol
   
   char command [10]; //string store for the command, set to maximum character of 9 now
   
   int levelComplete = FALSE;
   int deathFlag = FALSE; //you aren't dead when the game begins
   
   while (deathFlag == FALSE) { //infinite loop for game unless you die or quit (which will assign your death flag to true)
      generateMap(&roomWidth, &roomHeight); //returns to beginning of loop when you complete floor
      //seed level and entityInfo with some monster entities and player and throw them in another 2 dimensional array entityInfo
      printMap(mapArray, roomWidth, roomHeight);
      //printStatus() should be included into printMap
      
      while (levelComplete != TRUE) {
         // get command (look at wiki for commands) from keyboard
         // stacked else ifs for all commands that lead to their own function
         // else print "Invalid command"
         //e.g
         printf("What will you do?\n"); //awaiting response
         scanf("%9s",command);
         if (command == ("up" || "k")) {
            //move(entityArray[][15], mapArray[][15], UP, entityInfo[0,ENTITY_X], entityInfo[0,ENTITY_Y]);
         //} else if { etc.
         //inventory system will print out another screen and have a similar infinite loop
         //right now I think that at the end of the resolutions of all the legal commands, then the map and status screen
         //should be reprinted 
         } else {
            printf("Invalid command.\n");
         }
      }
      //death checks will occur during monster or player movements
      //monster movements will be a separate function which will walk through the entityInfo array          
   }


}
