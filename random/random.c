#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int j, r, nloops;
    unsigned int seed;
    int defaultTemp = 30 ;
    int actualTemp ;

    if (argc != 3) 
    {
       fprintf(stderr, "Usage: %s <seed> <nloops>\n", argv[0]);
       exit(EXIT_FAILURE);
    }
               printf("NO of arguments = %d \n", argc);
               printf("First argument = %s \n", argv[0]);
               printf("second argument = %s \n", argv[1]);
               printf("Third argument = %s \n", argv[2]);
               seed = atoi(argv[1]);
               nloops = atoi(argv[2]);

               srand(seed);
               for (j = 0; j < nloops; j++) 
               {
                   r =  rand();
                   r = r/100000000 ;
                   printf("%d\n", r);
                   if (((r/10) % 2)) 
                      r = r * -1 ;

                   actualTemp = defaultTemp + r;
                   printf("%d\n", actualTemp);
               }

               exit(EXIT_SUCCESS);
}
