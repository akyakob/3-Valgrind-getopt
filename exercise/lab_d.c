/****************************************************************************
  Lab 3 student file
****************************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
   int aflag = 0;          /* My boolean variables */
   int bflag = 0;          /* My boolean variables */
   char *cvalue = NULL;    /* Pointer to a parameter */
   char *dvalue = NULL;    /* Pointer to a parameter */
   int index;
   int rc;                 /* Result from getopt() */
   opterr = 0;             /* Disable automatic error reporting */
   
   /*------------------------------------------------------------------------
     Print the parameters provided by the OS to our C code
   ------------------------------------------------------------------------*/
   printf("Dumping raw command line parameters\n");
   for (int i = 0; i < argc; i++) {
      printf("Raw parameter %d is '%s'\n", i, argv[i]);
   }
   printf("\n");
   
   /* Parse until all parameters have been processed. “c” has an required parameter */
   while ((rc = getopt (argc, argv, "ac:bd:")) != -1) {
      printf("getopt() returned ='%c'\n",  rc);
      switch (rc)   {
      case 'a':                  /* Boolean variable */
         aflag = 1;
         break;

      case 'c':                  /* Copy the required C parameter */
         cvalue = optarg;        /* Safe to copy just the pointer because it  */ 
         break;                  /* really points to argv[]  */

      case 'b':
	bflag = 1;
	break;
      
      case 'd':
	dvalue = optarg;
	break;

      case '?':         /* Handle the error cases */
         if (optopt == 'c') {
            fprintf (stderr, "Option -%c requires an argument.\n", optopt);}

         else if (isprint (optopt)) {  /* character is printable */
         fprintf (stderr, "Unknown option `-%c'.\n", optopt);}

         else {         /* Character is NOT printable   */
            fprintf (stderr,  "Unknown option character '%x'.\n", optopt); }
         return 1;

      default:       /* oops,  unexpected result */
         fprintf (stderr, "Unexpected result %xX at line %d\n", rc, __LINE__);
         exit(99);
      } // End switch
   } // End while
   
   /* Print out the final results */
   printf ("aflag = %d, cvalue = %s, bflag = %d, dvalue = %s\n", aflag, cvalue, bflag, dvalue);

   /* account for any extra arguments */
   for (index = optind; index < argc; index++) {
      printf ("Non-option argument '%s'\n", argv[index]); }
   printf("\n\n");
   return 0;
}
