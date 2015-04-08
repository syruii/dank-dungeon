/* Section of program moves a given entity within a two-dimensional array
   The check for obstruction has yet to be written
   First written 8/04/15.
   Move function requires entity symbol to be already loaded into array
*/

#define UP 0
#define DOWN   -1
#define RIGHT 1
#define LEFT 2

//revision required later so that attempted movement into a monster entity results in attack function being called
int move(char* entityArray[][15], char* mapArray[][15], int direction, int entityx, int entityy) { 
//entityx is the x value in the array of the entity, similarly for entityy
   int valid;
   valid = obstructionCheck(entityArray[][15], mapArray[][15], direction, entityx, entityy);
   if (valid == TRUE) {
      assert(direction == (UP || DOWN || RIGHT || LEFT));
      if (direction == UP) {
         entityArray[entityx][entityy+1] = entityArray[entityx][entityy];
         entityArray[entityx][entityy] = '0';
      } else if (direction == DOWN) {
         entityArray[entityx][entityy-1] = entityArray[entityx][entityy];
         entityArray[entityx][entityy] = '0';
      } else if (direction == RIGHT) {
         entityArray[entityx+1][entityy] = entityArray[entityx][entityy];
         entityArray[entityx][entityy] = '0';
      } else if (direction == LEFT) {
         entityArray[entity-1][entityy] = entityArray[entityx][entityy];
         entityArray[entityx][entityy] = '0';
      }
      return EXIT_SUCCESS;
   } else {
      return EXIT_FAILURE; //returns to calling function where if it is called from player movement returns an erro
   }
}

int obstructionCheck(char* entityArray[][15], char* mapArray[][15], int direction, int entityx, int entityy) {
   //returns TRUE if move is valid, else returns FALSE if move is obstructed by tile or entity 
}
