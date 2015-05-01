/* Section of program moves a given entity within a two-dimensional array
   The check for obstruction has yet to be written
   First written 8/04/15.
   Move function requires entity symbol to be already loaded into array
*/
int obstructionCheck(char entityArray, char mapArray, int direction, int entityx, int entityy);

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3


//revision required later so that attempted movement into a monster entity results in attack function being called
int move(char entityArray, char mapArray, int direction, int entityx, int entityy, int entityIndex, entity entityInfo[]) {
//entityx is the x value in the array of the entity, similarly for entityy
   int valid;
   valid = obstructionCheck(entityArray, mapArray, direction, entityx, entityy);
   if (valid == TRUE) {
      assert(direction == (UP));
      assert(direction == (DOWN));
      assert(direction == (LEFT));
      assert(direction == (RIGHT));
      if (direction == UP) {
         entityIndex--;
         entityy++;
         entityArray[&entityx][&entityy+1] = entityx, entityy;
         entityArray[&entityx][&entityy] = NO_ENTITY;
      } else if (direction == DOWN) {
         entityIndex++;
         entityy--;
         entityArray[&entityx][&entityy-1] = entityx, entityy;
         entityArray[&entityx][&entityy] = NO_ENTITY;
      } else if (direction == RIGHT) {
         entityIndex++;
         entityx++;
         entityArray[&entityx+1][&entityy] = entityx, entityy;
         entityArray[&entityx][&entityy] = NO_ENTITY;
      } else if (direction == LEFT) {
         entityIndex--;
         entityx--;
         entityArray[&entityx-1][&entityy] = entityx, entityy;
         entityArray[&entityx][&entityy] = NO_ENTITY;
      }
      return EXIT_SUCCESS;
   } else {
      return EXIT_FAILURE; //returns to calling function where if it is called from player movement returns an erro
   }
}
//Old obstructiocheck, only checked if space was empty, did not return what was in the location
int obstructionCheck(char entityArray, char mapArray, int direction, int entityx, int entityy) {
   //returns TRUE if move is valid, else returns FALSE if move is obstructed by tile or entity
   if (direction == UP && mapArray[&entityx][&entityy+1] == EMPTY_SPACE) {
      return TRUE;
   } else if (direction == DOWN && mapArray[&entityx][&entityy-1] == EMPTY_SPACE){
      return TRUE;
   } else if (direction == RIGHT && mapArray[&entityx+1][&entityy] == EMPTY_SPACE){
      return TRUE;
   } else if (direction == LEFT && mapArray[&entityx-1][&entityy] == EMPTY_SPACE){
      return TRUE;
   } else {
       return FALSE;
   }
   return EXIT_SUCCESS;
}


//Includes the function which checks if a space is occupied
//On second thoughts, this is a pretty simple function.
//Returns FALSE if there is nothing, returns the entityIndex if there is something
/*
int entityCheck(int x, int y, char entityArray, entity entityInfo[]) {
   if (entityArray[x][y] != NO_ENTITY) {
      int i=1;
      while (i<8) {
         if ((entityInfo[i].entityx == x) && (entityInfo[i].entityy == y)) {
            return i;
         } else {
            i++;
         }
      }
   }
   return FALSE;
}
*/
