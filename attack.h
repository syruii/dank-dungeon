//Includes the functions which deal damage to a space in a direction
//May be appended later to include ranged weaponry, or a separate function created
//Attack returns TRUE if the attack went through, FALSE if it does not
#define SUCCESS 1
void damageCalc(entity entityInfo[MAX_ENTITIES],char entityArray[MAP_SIZE][MAP_SIZE], int attackerIndex, int defenderIndex, game* gameInfo);

int attack(int attackerIndex,int direction, char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[MAX_ENTITIES], game* gameInfo) {
   int defenderIndex = 0;
   int result = FALSE;

   if (direction == UP) {
      if (entityInfo[attackerIndex].entityy-1 > -1) {//could probably be reworked to be better, check against attacking a wall
            if ((defenderIndex = entityCheck(entityInfo[attackerIndex].entityx,entityInfo[attackerIndex].entityy-1,entityArray,entityInfo)) != FALSE) {
               damageCalc(entityInfo,entityArray,attackerIndex,defenderIndex,gameInfo);
               result = SUCCESS;
            }
      }
   } else if (direction == DOWN) {
      if (entityInfo[attackerIndex].entityy+1 < MAP_SIZE) {
         if ((defenderIndex = entityCheck(entityInfo[attackerIndex].entityx,entityInfo[attackerIndex].entityy+1,entityArray,entityInfo)) != FALSE) {
            damageCalc(entityInfo,entityArray,attackerIndex,defenderIndex,gameInfo);
            result = SUCCESS;
         }
      }
   } else if (direction == RIGHT) {
      if (entityInfo[attackerIndex].entityx+1 < MAP_SIZE) {
         if ((defenderIndex = entityCheck(entityInfo[attackerIndex].entityx+1,entityInfo[attackerIndex].entityy,entityArray,entityInfo)) != FALSE) {
            damageCalc(entityInfo,entityArray,attackerIndex,defenderIndex,gameInfo);
            result = SUCCESS;
         }
      }
   } else if (direction == LEFT) {
      if (entityInfo[attackerIndex].entityx-1 > -1) {
         if ((defenderIndex = entityCheck(entityInfo[attackerIndex].entityx-1,entityInfo[attackerIndex].entityy,entityArray,entityInfo)) != FALSE) {
            damageCalc(entityInfo,entityArray,attackerIndex,defenderIndex,gameInfo);
            result = SUCCESS;
         }
      }
   }
   return result;
}

void damageCalc(entity entityInfo[MAX_ENTITIES],char entityArray[MAP_SIZE][MAP_SIZE], int attackerIndex, int defenderIndex, game* gameInfo) {
   int damage = 0; //no miss chance because that's anti fun, you gotta know when you are dead, RNG is for losers
   //maybe edited later to include armor class
   damage = randint((int)entityInfo[attackerIndex].baseDamage/3) + entityInfo[attackerIndex].baseDamage;
   if (randint(10) == 0) {
      //critical hit
      printf("Critical hit!\n");
      damage *= 1.5;
   }
   entityInfo[defenderIndex].entityHP -= damage;
   if (attackerIndex == PLAYER_INDEX) {
      gameInfo->score += damage;
      printf("You deal %d damage to %s!\n",damage,entityInfo[defenderIndex].entityDescription);
   } else {
      printf("You take %d damage from %s!\n",damage,entityInfo[attackerIndex].entityDescription);
   }
   if (entityInfo[defenderIndex].entityHP < 1) {
      death(defenderIndex, entityArray, entityInfo);
      char rand = randint(2);
      if (rand == 0) {
         printf("A thud is heard as %s collapses to the ground.\n",entityInfo[defenderIndex].entityDescription);
      } else if (rand == 1) {
         printf("The blow rends %s in half, blood soaking into the damp ground.\n",entityInfo[defenderIndex].entityDescription);
      } else {
         printf("The body of %s rips into hundreds of ribbons which float softly away.\n",entityInfo[defenderIndex].entityDescription);
      }
      if (attackerIndex == PLAYER_INDEX) {
         gameInfo->score += entityInfo[defenderIndex].entityLVL*100;
         entityInfo[PLAYER_INDEX].exp += gameInfo->currentFloor;
         entityInfo[PLAYER_INDEX].expNextLVL = gameInfo->currentFloor * gameInfo->currentFloor;
            if (entityInfo[PLAYER_INDEX].expNextLVL - entityInfo[PLAYER_INDEX].exp >= 0) {
            entityInfo[PLAYER_INDEX].entityLVL++;
            printf ("Lvl up! You are now lvl %d \n", entityInfo[PLAYER_INDEX].entityLVL);
            }
         }
      }
}



