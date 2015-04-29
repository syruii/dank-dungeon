//Includes the function which checks if a space is occupied
//On second thoughts, this is a pretty simple function.
//Returns FALSE if there is nothing, returns the entityIndex if there is something

int entityCheck(int x, int y, char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[]) {
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
