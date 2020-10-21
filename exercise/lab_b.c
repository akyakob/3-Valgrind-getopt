/****************************************************************************
  Lab 3 student file
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
   char *p;
   p = (char *) malloc(19); /* Allocation #1 */
   strncpy(p, "word 1", 19);
   printf("%s\n", p);
   
   p = (char *) realloc(p,12); /* Allocation #2 */
   strncpy(p, "word 2", 12);
   printf("%s\n", p);
   
   free(p);
   p = NULL;
   p = (char *) malloc(16); /* Allocation #3 */
   strncpy(p, "word 3", 16);
   printf("%s\n", p);
   free(p);
   p = NULL;
   return 0;
   
}

