//Contains calling functions for the monster AI within the game
//All monster are hostile to player, friendly to other monsters
//ALL MONSTERS ARE EQUAL.
//Program written on 04/05


int abs(int a);
int aiPath(entity entityInfo[MAX_ENTITIES], char entityArray[MAP_SIZE][MAP_SIZE], int monsterIndex); //always returns a valid direction
int playerDistanceSquared (entity entityInfo[MAX_ENTITIES], int monsterIndex);

void aiTurn(entity entityInfo[MAX_ENTITIES], char entityArray[MAP_SIZE][MAP_SIZE], char mapArray[MAP_SIZE][MAP_SIZE], int roomWidth, int roomHeight, game* gameInfo, int monNumberOnFloor) {
   int monsterIndex = 1; //skips player entity
   int direction;
   int distanceSquared = 0;
   while (monsterIndex <= monNumberOnFloor) {
      if (entityInfo[monsterIndex].dead == FALSE) {
         distanceSquared = playerDistanceSquared(entityInfo,monsterIndex);
         if (distanceSquared == 1) { //"right behind you"
            direction = aiPath(entityInfo,entityArray,monsterIndex);
            attack(monsterIndex,direction,entityArray,entityInfo,gameInfo);
         } else if (distanceSquared < 26) {
            direction = aiPath(entityInfo,entityArray,monsterIndex);
            if (direction > -1) {
               move(roomWidth,roomHeight,entityArray,mapArray,direction,monsterIndex,entityInfo);
            }
         } else {
            direction = randint(5)-1;
            while(direction > -1 && move(roomWidth,roomHeight,entityArray,mapArray,direction,monsterIndex,entityInfo) == FALSE) {
               direction = randint(5)-1;
            }
         }
         if (randint(10) == 0) {
            if (randint(2) == 0) {
               printf("A growl from %s echoes through the room.\n",entityInfo[monsterIndex].entityDescription);
            } else {
               printf("You hear scratching sounds on the wall, probably from %s.\n", entityInfo[monsterIndex].entityDescription);
            }
         }
      }
      monsterIndex++;
   }
}

int playerDistanceSquared (entity entityInfo[MAX_ENTITIES], int monsterIndex) {
   int x = entityInfo[monsterIndex].entityx - entityInfo[PLAYER_INDEX].entityx;
   int y = entityInfo[monsterIndex].entityy - entityInfo[PLAYER_INDEX].entityy;
   int distance  = x*x + y*y;
   return distance;
} //returns distance squared not distance (don't want to include math.h if possible

int aiPath(entity entityInfo[MAX_ENTITIES], char entityArray[MAP_SIZE][MAP_SIZE], int monsterIndex) { //always returns a valid direction
//will be direction of player if right next to them
   int direction;
   int moveBlocked = TRUE; //makes sure monster moves, is not boolean
   int xDiff = entityInfo[monsterIndex].entityx - entityInfo[PLAYER_INDEX].entityx;
   int yDiff = entityInfo[monsterIndex].entityy - entityInfo[PLAYER_INDEX].entityy;
   if (abs(xDiff) <= abs(yDiff)) { //moving in y direction brings entity closer
      if (yDiff < 0) { //entity is above player
         direction = DOWN;
         moveBlocked = entityCheck(entityInfo[monsterIndex].entityx,entityInfo[monsterIndex].entityy+1,entityArray,entityInfo);
      } else if (yDiff > 0) {
         direction = UP;
         moveBlocked = entityCheck(entityInfo[monsterIndex].entityx,entityInfo[monsterIndex].entityy-1,entityArray,entityInfo);
      }
   }
   if (abs(xDiff) >= abs(yDiff) && moveBlocked != FALSE && moveBlocked != PLAYER_INDEX) { //if move is blocked by playerIndex, then should still
   //return direction to attack the player
      if (xDiff <= 0) { //entity to the left of player
         direction = RIGHT;
         moveBlocked = entityCheck(entityInfo[monsterIndex].entityx+1,entityInfo[monsterIndex].entityy,entityArray,entityInfo);
      }
      if (xDiff >= 0 && moveBlocked!= FALSE && moveBlocked != PLAYER_INDEX) {
         direction = LEFT;
         moveBlocked = entityCheck(entityInfo[monsterIndex].entityx-1,entityInfo[monsterIndex].entityy,entityArray,entityInfo);
      }
   }
   if (moveBlocked != FALSE && moveBlocked != PLAYER_INDEX) {
      //entity is landlocked
      direction = -1; //stay still, wait for traffic to clear
   }
   return direction;
   //no need to check for walls, because a wall can't be between the player and entity;
}


int abs(int a) {
   int b;
   if (a < 0) {
      b = -a;
   } else {
      b =a;
   }
   return b;
}
