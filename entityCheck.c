//Includes the function which checks if a space is occupied
//On second thoughts, this is a pretty simple function.
//Returns FALSE if there is nothing, returns the entityIndex if there is something
//Written sometime in April
//Adapted for use by the AI on 04/05

#include "main.h"
#include "entityCheck.h"

int entityCheck(int x, int y, char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[]) {
   if (entityArray[x][y] != NO_ENTITY) {
      int i=0;
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
