/*---------------------------------------------------------------------------
  Lab 3 student file
  10/05/2019    R. Repka    First release
---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main (int argc, char **argv) {
  int rc;

  /*-------------------------------------------------------------------------
    These variables are used to control the getOpt_long_only command line 
    parsing utility.  
  --------------------------------------------------------------------------*/
  /* getopt_long stores the option index here. */
  int option_index;

  /* Flag set by -verbose & -brief, note initialized to -1 to track usage */
  int verbose_flag = -1;
  
  /* This contains the short command line parameters list   In general 
     they SHOULD match the long parameter but DONT HAVE TO  
     e.g:  verbose  AND  g    */
  char *getoptOptions = "abc:d:f:gv";
  
  /* This contains the long command line parameter list, it should mostly 
     match the short list                                                  */
  struct option long_options[] = {
    /* These options set the same flag. */
    {"verbose", no_argument,       &verbose_flag, 1},
    {"brief",   no_argument,       &verbose_flag, 0},
    {"verb", no_argument,       &verbose_flag, 1},
    
    /* These options don’t set a flag.
       We distinguish them by their indices. */
    {"add",     no_argument,       0, 'a'},
    {"del",     required_argument, 0, 'd'},
    {"create",  required_argument, 0, 'c'},
    {"append",   no_argument,      0, 'a'},
    {"delete",  required_argument, 0, 'd'},
    {"file",   required_argument,  0, 'f'},
    {0, 0, 0, 0} /* Terminate */
  };
  
  while ((rc = getopt_long_only(argc, argv, getoptOptions, long_options, &option_index)) != -1)  {
       printf("getopt_long_only() returned ='%c' index = '%d'\n",  rc, option_index);
      switch (rc) {
        case 0: /* long option only */
          /* If this option set a flag, do nothing else now. */
          if (long_options[option_index].flag != 0) {
          break; }
          printf ("option %s", long_options[option_index].name);
          if (optarg) {
          printf (" with arg %s", optarg);}
          printf ("\n");
          break;

        case 'a':
          puts ("option -a\n");
          break;

        case 'b':
          puts ("option -b\n");
          break;

        case 'c':
          printf ("option -c with value `%s'\n", optarg);
          break;

        case 'd':
          printf ("option -d with value `%s'\n", optarg);
          break;

        case 'f':
          printf ("option -f with value `%s'\n", optarg);
          break;
          
        case 'g':
          printf ("option -g\n");
          break;    

        case 'v':
          printf ("option -v\n");
          break;
    
        case '?':
          /* getopt_long already printed an error message.
             because  opterr was NOT set to  0;*/
          break;
	
        default:
          printf ("error: undefined option %0xX\n", rc);
        } } // End switch

  /* Verbose status */
  printf("verbose flag is %d\n", verbose_flag);

  /* Print any remaining command line arguments (not options). */
  if (optind < argc) {
      printf ("non-option ARGV-elements: ");
      while (optind < argc) {
      printf ("'%s'", argv[optind++]);}
      putchar ('\n');
    } // End if

  exit (0);
}
