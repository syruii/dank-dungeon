//IMPORTANT NOTE : ENCOUNTERED SITUATION WHEN '+' TO LEFT OF PLAYER CHARACTER WAS NOT ABLE TO BE ATTACKED 01/05
#define NO_ENTITY '0'
#define EMPTY_SPACE '.'
#define STAIRS '>'
#define TRUE 1
#define FALSE -1

#define SAME 0
//stupid strcmp

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

// standard libraries
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

//definitions for MAXARRAYSIZE
#define MAP_SIZE 15
#define MAX_ENTITIES 8 //player, 6 normal mobs and a boss sometimes
#define MAX_ENTITY_PROPERTIES 5
#define MAX_DESCRIPT_SIZE 25

#define NOT_DEAD entityInfo[0].dead == FALSE

#define PLAYER_INDEX 0
#define PLAYER_CHAR '@'
#define PASSIVE_REGEN 0.05

#define VERTICAL_WALL "|"
#define HORIZONTAL_WALL "-"
#define MAP_SIZE 15

//definitions for entity/Info struct
typedef struct _entity {
   char entitySymbol;
   char entityDescription[MAX_DESCRIPT_SIZE];
   int entityHP;
   int entityLVL;
   int baseDamage;
   int entityx; //yes i could use unsigned char but whatever
   int entityy;
   int dead;
   int exp;
   int expNextLVL;
   int maxHP;
} entity;

typedef struct _game {
   char playerName[10];
   int score;
   int turn;
   int currentFloor;
   int skills[20];
} game;

//maybe will organise into structs


