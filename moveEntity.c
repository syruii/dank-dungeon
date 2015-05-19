//revision required later so that attempted movement into a monster entity results in attack function being called
int move(int roomWidth, int roomHeight, char entityArray[MAP_SIZE][MAP_SIZE], char mapArray[MAP_SIZE][MAP_SIZE], int direction, int entityIndex, entity entityInfo[MAX_ENTITIES]) {
//entityx is the x value in the array of the entity, similarly for entityy
   /*int valid;
       valid = entityCheck(x, y, entityArray, entityInfo);

   if (valid == FALSE) {*/
      int result;
      int posx = entityInfo[entityIndex].entityx;
      int posy = entityInfo[entityIndex].entityy;
      assert(direction == (UP) || direction == (DOWN) || direction == (LEFT) || direction == (RIGHT));
      if (direction == UP && entityCheck(posx,posy-1,entityArray,entityInfo) == FALSE && posy-1 > -1) {
         entityArray[posx][posy-1] = entityInfo[entityIndex].entitySymbol;
         entityArray[posx][posy] = NO_ENTITY;
         entityInfo[entityIndex].entityy = entityInfo[entityIndex].entityy-1;
         result = TRUE;
      } else if (direction == DOWN && entityCheck(posx,posy+1,entityArray,entityInfo) == FALSE && posy+1 < roomHeight) {
         entityArray[posx][posy+1] = entityInfo[entityIndex].entitySymbol;
         entityArray[posx][posy] = NO_ENTITY;
         entityInfo[entityIndex].entityy = entityInfo[entityIndex].entityy +1;
         result = TRUE;
      } else if (direction == RIGHT && entityCheck(posx+1,posy,entityArray,entityInfo) == FALSE && posx+1 < roomWidth) {
         entityArray[posx+1][posy] = entityInfo[entityIndex].entitySymbol;
         entityArray[posx][posy] = NO_ENTITY;
         entityInfo[entityIndex].entityx = entityInfo[entityIndex].entityx +1;
         result = TRUE;
      } else if (direction == LEFT && entityCheck(posx-1,posy,entityArray,entityInfo) == FALSE && posx-1 > -1) {
         entityArray[posx-1][posy] = entityInfo[entityIndex].entitySymbol;
         entityArray[posx][posy] = NO_ENTITY;
         entityInfo[entityIndex].entityx = entityInfo[entityIndex].entityx -1;
         result = TRUE;
       }else {
         result = FALSE; //returns to calling function where if it is called from player movement returns an error
   }
   return result;
}

/*Old obstructiocheck, only checked if space was empty, did not return what was in the location
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
*/
