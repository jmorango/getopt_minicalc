/* programmer Jose Moran  Panther ID : 590-9968  .
   CERTIFICATION: I certify that this work is my own and that
                  none of it is the work of any other person.


    This program functions as a calculator receiving the values from the command line
    ()   
*/ 

#include <stdio.h>
#include <stdlib.h>

main(int argc, char **argv){
   int c, error = 0;
   int index = 0;
   double  result = 0;
   int aflag = 0, dflag = 0, mflag =0, sflag = 0, xflag = 0;
   int a = 0, d = 0, m = 0, s = 0, x = 0;
   extern int optind;
   extern char *optarg;
   static char usage[] = "usage: minicalc [-a num] [-d num] [-m num] [-s num] [-x] value\n"; 
   static char error1[] = "The program need a value to calculate a result. "; 
   static char error2[] = "The input value has to be between 1 and 99 inclusive.\n"; 
   static char error3[] = "The num value has to be between 1 and 20 inclusive.\n";

   while ((c = getopt(argc, argv, "a:d:m:s:x")) != -1) //read the arguments
      switch(c){
         case 'a':  aflag = 1;
                    a = atoi(optarg);
                    if (a < 1 || a > 20) {
                       fprintf(stderr, error3, argv[0]);
                       fprintf(stderr, usage, argv[0]);
                       exit(1);
                    }
                    break;
         case 'd':  dflag = 1;
                    d = atoi(optarg);
                    if (d < 1 || d > 20){
                       fprintf(stderr, error3, argv[0]);
                       fprintf(stderr, usage, argv[0]);
                       exit(1);
                    }
                    break;
         case 'm':  mflag = 1;
                    m = atoi(optarg);   
                    if (m < 1 || m > 20){
                       fprintf(stderr, error3, argv[0]);
                       fprintf(stderr, usage, argv[0]);
                       exit(1);
                    }
                    break;
         case 's':  sflag = 1;
                    s = atoi(optarg);
                    if(s < 1 || s > 20){
                       fprintf(stderr, error3, argv[0]);
                       fprintf(stderr, usage, argv[0]);
                       exit(1);
                    }
                    break;
         case 'x':  xflag = 1;
                    break;
         case '?':  error = 1;
                    break;
      }
   if (optind + 1 >= argc){
      result += atoi(argv[optind]); // store the value in result.
   }
   else {
      // value is needed to calculate result 
      fprintf(stderr, error1, argv[0]);
      fprintf(stderr, usage, argv[0]);
      exit(1); 
   }
   if (error) {
      //invalid argument
      fprintf(stderr, usage, argv[0]);
      exit(1);
   }
   if(result < 1 || result > 99){
      fprintf(stderr, error2, argv[0]); // value has to be between 1 and 99
      fprintf(stderr,usage, argv[0]);
      exit(1);
   } 
   // perform the calculations
   if(xflag){
      result = result * result;
   }
   if(mflag){
      result*= m;
   }
   if(dflag){
      result /= d;
   }
   if(aflag){
      result += a;
   }
   if(sflag){
      result -= s;
   }
    //output the result
   printf("Result: %.2f\n ", result);
}
