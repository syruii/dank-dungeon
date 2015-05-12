/* Function populates the entityInfo and then places them correspondingly into entityArray
   Program written on 12/04/15
   revised 04/05
*/

#define NO_ENTITY '0'

#define BASE_HP 8

void generatePosition (int roomWidth, int roomHeight, int* posx, int* posy);
void placeMonster (char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[], char mapArray[MAP_SIZE][MAP_SIZE], int roomWidth, int roomHeight, int monNumber);
void generateMonster (char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[], int playerLevel, int monNumber);
void placePlayer (char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[], char mapArray[MAP_SIZE][MAP_SIZE], int roomWidth, int roomHeight);

int entityPopulate (char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[], char mapArray[MAP_SIZE][MAP_SIZE], int playerLevel, int roomWidth, int roomHeight) {
   placePlayer(entityArray, entityInfo, mapArray, roomWidth, roomHeight);
   int monNumber = 1;
   int monMax = randint(5)+1; //has to be at least one monster
   while (monNumber <= monMax) {
      generateMonster(entityArray, entityInfo, playerLevel, monNumber);
      placeMonster (entityArray, entityInfo, mapArray, roomWidth, roomHeight, monNumber);
      monNumber++;
   } 
   return monMax;
}

void placePlayer (char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[], char mapArray[MAP_SIZE][MAP_SIZE], int roomWidth, int roomHeight) {
   int posx,posy;
   generatePosition(roomWidth, roomHeight, &posx, &posy);
   while ((mapArray[posx][posy])!= EMPTY_SPACE) {
      generatePosition(roomWidth, roomHeight, &posx, &posy);
      printf("%c\n",mapArray[posx][posy]);
   }
   entityArray[posx][posy] = PLAYER_CHAR;
// the player character will always be designated with @
   entityInfo[0].entityx = posx;
   entityInfo[0].entityy = posy;
   return;
} 

void generateMonster (char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[], int playerLevel, int monNumber) {
   entityInfo[monNumber].entityLVL = randint(3) + playerLevel; //random level, game will be hard
   entityInfo[monNumber].entityHP = randint(10) + 2*entityInfo[monNumber].entityLVL + BASE_HP; //random HP @ LVL1 10-20 HP
   entityInfo[monNumber].dead = FALSE; 
   int descriptNumber = randint(9);
   if (descriptNumber == 0) {//randonmly generate a descrption (all monsters are created equal)
      strncpy(entityInfo[monNumber].entityDescription, "a loud bat", MAX_DESCRIPT_SIZE);
   } else if (descriptNumber == 1) {
      strncpy(entityInfo[monNumber].entityDescription, "a hungry skeleton", MAX_DESCRIPT_SIZE);
   } else if (descriptNumber == 2) {
      strncpy(entityInfo[monNumber].entityDescription, "an echoing ooze", MAX_DESCRIPT_SIZE);
   } else if (descriptNumber == 3) {
      strncpy(entityInfo[monNumber].entityDescription, "a stampeding unicorn", MAX_DESCRIPT_SIZE);
   } else if (descriptNumber == 4) {
      strncpy(entityInfo[monNumber].entityDescription, "the lich king", MAX_DESCRIPT_SIZE);
   } else if (descriptNumber == 5) {
      strncpy(entityInfo[monNumber].entityDescription, "a gigantic spider", MAX_DESCRIPT_SIZE);
   } else if (descriptNumber == 6) {
      strncpy(entityInfo[monNumber].entityDescription, "a dire wolf", MAX_DESCRIPT_SIZE);
   } else if (descriptNumber == 7) {
      strncpy(entityInfo[monNumber].entityDescription, "a scavenging hyena", MAX_DESCRIPT_SIZE);
   } else if (descriptNumber == 8) {
      strncpy(entityInfo[monNumber].entityDescription, "an explosive boombot", MAX_DESCRIPT_SIZE);
   }
   entityInfo[monNumber].baseDamage = randint(5) + entityInfo[monNumber].entityLVL; //random baseDamage @ LVL 1 1-6
   return;
}

void placeMonster (char entityArray[MAP_SIZE][MAP_SIZE], entity entityInfo[], char mapArray[MAP_SIZE][MAP_SIZE], int roomWidth, int roomHeight, int monNumber) {
   int posx,posy;
   generatePosition(roomWidth, roomHeight, &posx, &posy);
   while ((mapArray[posx][posy]!= EMPTY_SPACE) || (entityArray[posx][posy] != NO_ENTITY)) {
      generatePosition(roomWidth, roomHeight, &posx, &posy);
   }
   char symbolChoose = randint(4); //char to save space
   char monSymbol;
   if (symbolChoose == 0) { //choose a non-unique symbol for the monster
// you wanted a unique identifier? maybe next time
      monSymbol = '#';
   } else if (symbolChoose == 1) {
      monSymbol = '&';
   } else if (symbolChoose == 2) {
      monSymbol = '$';
   } else if (symbolChoose == 3) {
      monSymbol = '+';
   } else if (symbolChoose == 4) {
      monSymbol = '*';
   }
   entityArray[posx][posy] = monSymbol; //dump all the map specific info on the entity
   entityInfo[monNumber].entityx = posx;
   entityInfo[monNumber].entityy = posy;
   entityInfo[monNumber].entitySymbol = monSymbol;
   return;
}

void generatePosition (int roomWidth, int roomHeight, int* posx, int* posy) {
   *posx = randint(roomWidth); //0th row/column is a thing
   *posy = randint(roomHeight);
   return;
}
 
