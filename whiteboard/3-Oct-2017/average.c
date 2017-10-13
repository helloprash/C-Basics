#include <stdio.h>
#include <stdarg.h>

float ComputeAverage(int noOfarguments,...)
{
   va_list argumentList ;
   int i ;
   int value ;
   int total ;
   float fTotal ;
   float fargs ;
   float avg ;

   va_start(argumentList, noOfarguments) ;
   total = 0;
   for(i=0; i<noOfarguments;i++)
   {
      value = va_arg(argumentList,int);
      printf("Value of %d argument is %d \n", i,value);
      total = total + value;
   }
   va_end(argumentList);
   fTotal = (float)  total ;
   fargs  = (float) noOfarguments ;
   printf("Total in float format = %f , arg in float format is %f\n",
            fTotal, fargs);
   avg =    fTotal/fargs ;
   return avg ;

}
main()
{
 float avg ;
 int noOfArgs ;


 printf("---------------------------------------\n");
 noOfArgs = 4 ;
 avg = ComputeAverage(noOfArgs,2,3,4,5);
 printf("Average is %f \n", avg);
 printf("---------------------------------------\n");
 noOfArgs = 6 ;
 avg = ComputeAverage(noOfArgs,2,3,4,5,7,8);
 printf("Average is %f \n", avg);
 printf("---------------------------------------\n");
 noOfArgs = 2 ;
 avg = ComputeAverage(noOfArgs,2,3);
 printf("Average is %f \n", avg);
 printf("---------------------------------------\n");

}
