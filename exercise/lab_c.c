/****************************************************************************
  Lab 3 student file
****************************************************************************/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
   int *arr = malloc(100*sizeof(int)); //array for 100 integers
   if (NULL == arr) { 
      fprintf(stderr, "Malloc error\n");
      exit(99);
   }
   
   for (int i = 0; i < 100; i++) {
      /* random int between 0 and 99 */
      int r = rand() % 100;
      arr[i] = r;
   }
  printf("Last two random numbers are %d %d\n", arr[98], arr[99]);
  free(arr);
  arr = NULL;
  return(0);
}
