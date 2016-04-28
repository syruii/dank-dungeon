//contains a function which gets a direction for non-movement commands which require a direction
//returns the direction else returns -1
#include <string.h>
#include "direction.h"

int getDirection(void) {
   char command[10];
   int direction;
   int commandDone = FALSE;
   while (commandDone == FALSE) {
      scanf("%9s",command);
      printf("\n");
      if (strcmp(command, "down") == SAME) {
         direction = DOWN;
         commandDone = TRUE;
      } else if (strcmp(command, "up") == SAME) {
         direction = UP;
         commandDone = TRUE;
      } else if (strcmp(command, "right") == SAME) {
         direction = RIGHT;
         commandDone = TRUE;
      } else if (strcmp(command, "left") == SAME) {
         direction = LEFT;
         commandDone = TRUE;
      } else if (strcmp(command, "cancel") == SAME) {
         direction = -1;
         commandDone = TRUE;
      } else {
         printf("Enter a valid direction or cancel.\n");
      }
   }
   return direction;
}
