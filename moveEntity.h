/* Section of program moves a given entity within a two-dimensional array
   The check for obstruction has yet to be written
   First written 8/04/15.
   Move function requires entity symbol to be already loaded into array
*/
char entityArray [MAP_SIZE][MAP_SIZE];
char mapArray [MAP_SIZE][MAP_SIZE];
int entityx;
int entityy;
int x;
int y;
int entityInfo;
int posx;
int posy;
int entityIndex;
int posx;
int posy;

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

//revision required later so that attempted movement into a monster entity results in attack function being called
int move(char entityArray[MAP_SIZE][MAP_SIZE], char mapArray[MAP_SIZE][MAP_SIZE], int direction, int entityIndex, entity entityInfo[PLAYER_INDEX]) {
//entityx is the x value in the array of the entity, similarly for entityy
   /*int valid;
       valid = entityCheck(x, y, entityArray, entityInfo);

   if (valid == FALSE) {*/
       int posx = entityInfo[PLAYER_INDEX].entityx;
       int posy = entityInfo[PLAYER_INDEX].entityy;
      assert(direction == (UP) || direction == (DOWN) || direction == (LEFT) || direction == (RIGHT));
      if (direction == UP && entityInfo[PLAYER_INDEX].entityy-1 != -1 && entityArray[posx][posy-1] == NO_ENTITY) {
         entityArray[posx][posy-1] = '@';
         entityArray[posx][posy] = NO_ENTITY;
         entityInfo[PLAYER_INDEX].entityy--;
         printf("You move up.\n");
      } else if (direction == DOWN && entityInfo[PLAYER_INDEX].entityy+1 < MAP_SIZE && entityArray[posx][posy+1] == NO_ENTITY) {
         entityArray[posx][posy+1] = '@';
         entityArray[posx][posy] = NO_ENTITY;
         entityInfo[PLAYER_INDEX].entityy++;
         printf("You move down.\n");
      } else if (direction == RIGHT && entityInfo[PLAYER_INDEX].entityx+1 < MAP_SIZE && entityArray[posx+1][posy] == NO_ENTITY) {
         entityArray[posx+1][posy] = '@';
         entityArray[posx][posy] = NO_ENTITY;
         entityInfo[PLAYER_INDEX].entityx++;
         printf("You move right.\n");
      } else if (direction == LEFT && entityInfo[PLAYER_INDEX].entityx-1 != -1 && entityArray[posx-1][posy] == NO_ENTITY) {
         entityArray[posx-1][posy] = '@';
         entityArray[posx][posy] = NO_ENTITY;
         entityInfo[PLAYER_INDEX].entityx--;
         printf("You move left.\n");
       }else {
      printf ("I can't let you do that\n"); //returns to calling function where if it is called from player movement returns an erro
   }
}
/*//Old obstructiocheck, only checked if space was empty, did not return what was in the location
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


Move player info up
             int posx = entityInfo[PLAYER_INDEX].entityx;
             int posy = entityInfo[PLAYER_INDEX].entityy;
                entityArray[posx][posy-1] = '@';
//Set old position to be empty
         entityArray[posx][posy] = NO_ENTITY;
                      entityInfo[PLAYER_INDEX].entityy--;
               printf("You move up.\n");
               printMap(mapArray, entityArray, roomWidth, roomHeight);
               printf ("%d", posy);
//debugging
*/
