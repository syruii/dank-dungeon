//Includes the functions which deal damage to a space in a direction
//May be appended later to include ranged weaponry, or a separate function created
//Attack returns TRUE if the attack went through, FALSE if it does not
#define FAIL 0
#define SUCCESS 1

int damageCalc(entity entityInfo[MAX_ENTITIES], int attackerIndex, int defenderIndex);

int attack(int attackerIndex,int direction, char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[MAX_ENTITIES]) {
   int defenderIndex = 0;
   int result = FAIL;
   if (direction == UP) {
      if (entityInfo[attackerIndex].entityy-1 > -1) {//could probably be reworked to be better, check against attacking a wall
            if ((defenderIndex = entityCheck(entityInfo[attackerIndex].entityx,entityInfo[attackerIndex].entityy-1,entityArray,entityInfo)) != FALSE) {
               damageCalc(entityInfo,attackerIndex,defenderIndex);
               result = SUCCESS;
            }
      }
   } else if (direction == DOWN) {
      if (entityInfo[attackerIndex].entityy+1 < MAP_SIZE) { 
         if ((defenderIndex = entityCheck(entityInfo[attackerIndex].entityx,entityInfo[attackerIndex].entityy+1,entityArray,entityInfo)) != FALSE) {
            damageCalc(entityInfo,attackerIndex,defenderIndex);
            result = SUCCESS;
         }
      }
   } else if (direction == RIGHT) {
      if (entityInfo[attackerIndex].entityx+1 < MAP_SIZE) { 
         if ((defenderIndex = entityCheck(entityInfo[attackerIndex].entityx+1,entityInfo[attackerIndex].entityy,entityArray,entityInfo)) != FALSE) {
            damageCalc(entityInfo,attackerIndex,defenderIndex);
            result = SUCCESS;
         }
      } 
   } else if (direction == LEFT) {
      if (entityInfo[attackerIndex].entityx-1 > -1) {
         if ((defenderIndex = entityCheck(entityInfo[attackerIndex].entityx-1,entityInfo[attackerIndex].entityy-1,entityArray,entityInfo)) != FALSE) {
            damageCalc(entityInfo,attackerIndex,defenderIndex);
            result = SUCCESS;
         }
      }
   }
   return result;
}

int damageCalc(entity entityInfo[MAX_ENTITIES], int attackerIndex, int defenderIndex) {
   int damage = 0; //no miss chance because that's anti fun, you gotta know when you are dead, RNG is for losers
   //maybe edited later to include armor class
   damage = randint(entityInfo[attackerIndex].baseDamage/3) + entityInfo[attackerIndex].baseDamage;
   if (randint(10) == 0) {
      //critical hit
      printf("Critical hit!\n");
      damage *= 1.5;
   }
   printf("You deal %d damage to %s!\n",damage,entityInfo[defenderIndex].entityDescription);
   entityInfo[defenderIndex].entityHP -= damage;
   return damage;
}
           


