#ifndef ATTACK_H
#define ATTACK_H

#define SUCCESS 1
#include "main.h"

void damageCalc(entity entityInfo[MAX_ENTITIES],char entityArray[MAP_SIZE][MAP_SIZE], int attackerIndex, int defenderIndex, game* gameInfo);

#endif
