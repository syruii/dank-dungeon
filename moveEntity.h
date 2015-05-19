#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

int move(int roomWidth, int roomHeight, char entityArray[MAP_SIZE][MAP_SIZE], char mapArray[MAP_SIZE][MAP_SIZE], int direction, int entityIndex, entity entityInfo[MAX_ENTITIES]);
