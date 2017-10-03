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


