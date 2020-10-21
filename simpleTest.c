/******************************************************************************
* simpleTest.c - Test the phase 1 of the darray implementation
*
* Simple program to test basic DynamicArrays module functionality.  
* R. Repka  08/10/2018 - Initial version
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "ClassErrors.h"
#include "DynamicArrays.h"

/* Initial Size of Dynamic Array */
#define INITIAL_SIZE (2)

/******************************************************************************
 Simple program to test basic DynamicArrays module functionality.  
        int main(int argc, char* argv[])
 Where:
    int argc        - The number of command line parameters
    char *argv[]    - An array of pointers to the parameters
    returns: in     - 0 for success, non-zero for error
    errors:         - Error message printed to stderr and exits with an error 
                      code 
******************************************************************************/
int main(int argc, char* argv[]) {
   /* declare local variables */
   int ErrorCode = PGM_SUCCESS;             /* Application error code - 0 is OK */
   DArray TestDynamicArray = { 0, 0, NULL}; /* Dynamic Array for Data */
   Data TempData;                           /* temp variable to hold data   */


   /* Print usage information */
   printf("This program inserts 3 objects into a dynamic array of %d entries\n", INITIAL_SIZE);
   
   /* Initialize the dynamic array */
   CreateDArray(&TestDynamicArray, INITIAL_SIZE);

   /* Push data into the array */
   strncpy(TempData.String, "First line", MAX_STR_LEN);
   PushToDArray(&TestDynamicArray, &TempData);

   strncpy(TempData.String, "Second line", MAX_STR_LEN);
   PushToDArray(&TestDynamicArray, &TempData);
   
   /* This will force the Darray to grow */
   strncpy(TempData.String, "Third line", MAX_STR_LEN);
   PushToDArray(&TestDynamicArray, &TempData);
   
   /* Now use the data*/
   for (int i = 0; i < TestDynamicArray.EntriesUsed; i++) {
      printf("Line %d contains text '%s'\n", i+1, TestDynamicArray.Payload[i].String);
   }

   /* De-allocate the dynamic array */
   DestroyDArray(&TestDynamicArray);

   return ErrorCode;
  } /* main() */
  
  
