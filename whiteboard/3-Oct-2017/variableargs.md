# Variable Arguments

char myname[10];
int x = 10 ;
int y = 20 ;
int z = 30;

printf("Hello how are you I am %s\n", myname);

printf("The values are %d %d %d", x,y,z);

printf("The first two values are %d %d %d", x,y);  //Error number of %d does not match with variables

printf("The first value is %d  %d\n", x, name); //Error number of %d does not match with variables

## This means the number of variable has to match with the format specfier in the control string of a printf()
##  However the format specifier and the variable match we can pass any number of parameter to the printf() or scanf()
##  fscanf() , fprintf().

## Example of a subroutine which make use of variable arguments.

Problem Statement: 
You are asked to write a Subroutine/function in C which will take more than one integer as parameter/arguments
and compute the average of all the integers that was provided.

Eg :

    ComputeAverage(x,y,z);
    ComputeAverage(x,y,z,z,a,b);
    
### Solution
````
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


