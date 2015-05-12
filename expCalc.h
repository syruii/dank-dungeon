//Calculates exp, and keeps track of levels/total
// Have to add stat increases to player when they level, perhaps hp refill?
//exp system is going ot increase with each floor, 4*floor
//Need a way to check when an enemy dies, piggy backing of attack function's one atm.
/*void expCalc (entity entityInfo[MAX_ENTITIES], game* gameInfo) {
   if (){
   entityInfo[PLAYER_INDEX].exp += gameInfo->currentFloor;
   entityInfo[PLAYER_INDEX].expNextLVL = gameInfo->currentFloor * gameInfo->currentFloor;
   }
   if (entityInfo[PLAYER_INDEX].expNextLVL - entityInfo[PLAYER_INDEX].exp >= 0) {
   entityInfo[PLAYER_INDEX].entityLVL++;
   printf ("Lvl up! You are now lvl %d \n", entityInfo[PLAYER_INDEX].entityLVL);
   }
}
*/
