#ifndef ATTACK_H
#define ATTACK_H

#include "main.h"

#define SUCCESS 1

void damageCalc(entity entityInfo[MAX_ENTITIES],char entityArray[MAP_SIZE][MAP_SIZE], int attackerIndex, int defenderIndex, game* gameInfo);

#endif
