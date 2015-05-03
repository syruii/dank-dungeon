//Includes the function which checks if a space is occupied
//On second thoughts, this is a pretty simple function.
//Returns FALSE if there is nothing, returns the entityIndex if there is something
/*
int entityCheck(int x, int y, char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[]) {
   if (entityArray[x][y] != EMPTY_SPACE && entityArray[x][y] != NO_ENTITY) {
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
}*/
int entityCheck(int x, int y, char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[]) {
   if (entityArray[x][y] != NO_ENTITY && entityInfo[PLAYER_INDEX].entityy > 0) {
      int i=1;
      while (i<8) {
         if ((entityInfo[i].entityx == x) && (entityInfo[i].entityy == y+1)) {
            return i;
         } else {
            i++;
         }
      }
   return FALSE;
   }else {
   return TRUE;
   }
}
