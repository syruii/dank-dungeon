//Prints status below map to show everything relevant.

void printStatus (game gameInfo, entity entityInfo[MAX_ENTITIES]) {
   printf("%s ",gameInfo.playerName);
   if (entityInfo[PLAYER_INDEX].entityHP - entityInfo[PLAYER_INDEX].maxHP/3 > 0) {
      printf("the Adventurer");
   } else {
      printf("the Weak");
   }
   printf("\t");
   printf("Level %d", entityInfo[PLAYER_INDEX].entityLVL);
   printf("\n");
   printf("HP: %d/%d",entityInfo[PLAYER_INDEX].entityHP, entityInfo[PLAYER_INDEX].maxHP);
   printf("\t");
//exp per level needs to change 
   printf("EXP to next level: %d", (entityInfo[PLAYER_INDEX].expNextLVL - entityInfo[PLAYER_INDEX].exp));
   printf("\n");
   printf("Floor %d",gameInfo.currentFloor);
   printf("\t");
   printf("\t");
   printf("Turn %d",gameInfo.turn);
   printf("\t");
   printf("\t");
   printf("Score: %d",gameInfo.score);
   printf("\n");
}   

