/* Section of program moves a given entity within a two-dimensional array
   The check for obstruction has yet to be written
   First written 8/04/15.
   Move function requires entity symbol to be already loaded into array
*/

#define UP 0
#define DOWN -1
#define RIGHT 1
#define LEFT 2
#define EMPTY_SPACE NULL ???
// Steb pls 2 help what is an empty space
//revision required later so that attempted movement into a monster entity results in attack function being called
int move(char* entityArray[][15], char* mapArray[][15], int direction, int entityx, int entityy, int entityIndex) {
//entityx is the x value in the array of the entity, similarly for entityy
   int valid;
   valid = obstructionCheck(entityArray[][15], mapArray[][15], direction, entityx, entityy);
   if (valid == TRUE) {
      assert(direction == (UP || DOWN || RIGHT || LEFT));
      if (direction == UP) {
         entityInfo[entityIndex,ENTITY_Y]++;
         entityArray[entityx][entityy+1] = entityArray[entityx][entityy];
         entityArray[entityx][entityy] = NO_ENTITY;
      } else if (direction == DOWN) {
         entityInfo[entityIndex,ENTITY_Y]--;
         entityArray[entityx][entityy-1] = entityArray[entityx][entityy];
         entityArray[entityx][entityy] = NO_ENTITY;
      } else if (direction == RIGHT) {
         entityInfo[entityIndex,ENTITY_X]++;
         entityArray[entityx+1][entityy] = entityArray[entityx][entityy];
         entityArray[entityx][entityy] = NO_ENTITY;
      } else if (direction == LEFT) {
         entityInfo[entityIndex,ENTITY_X]--;
         entityArray[entityx-1][entityy] = entityArray[entityx][entityy];
         entityArray[entityx][entityy] = NO_ENTITY;
      }
      return EXIT_SUCCESS;
   } else {
      return EXIT_FAILURE; //returns to calling function where if it is called from player movement returns an erro
   }
}
//checks whether moves are obstructed
int obstructionCheck(char* entityArray[][15], char* mapArray[][15], int direction, int entityx, int entityy) {
   //returns TRUE if move is valid, else returns FALSE if move is obstructed by tile or entity
   if (direction == UP && mapArray[entityx][entityy+1] == EMPTY_SPACE) {
      return TRUE;
   } else if (direction == DOWN && mapArray[entityx][entityy-1] == EMPTY_SPACE){
      return TRUE;
   } else if (direction == RIGHT && mapArray[entityx+1][entityy] == EMPTY_SPACE){
      return TRUE;
   } else if (direction == LEFT && mapArray[entityx-1][entity] == EMPTY_SPACE){
      return TRUE;
   } else {
       return FALSE;
   }
   return EXIT_SUCCESS;
}


