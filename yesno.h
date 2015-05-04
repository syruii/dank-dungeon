//parses yes or no or cancel
//fork of direction.h for yes/no
//program written on 04/05
//capitals were cool once

int getYes(void) {
   char command[10];
   int yn; //yesorno more like TRUE FALSE
   int commandDone = FALSE;
   while (commandDone == FALSE) {
      scanf("%9s",command);
      if (strcmp(command,"yes") == SAME) {
         yn = TRUE;
         commandDone = TRUE;
      } else if (strcmp(command,"no") == SAME) {
         yn = FALSE;
         commandDone = TRUE;
      } else {
         printf("Enter yes or no.\n");
      }
   }
   return yn;
}
      
