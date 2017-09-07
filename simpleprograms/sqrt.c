#include <stdio.h>
#include <math.h>

main()
{
  int intVal ; /* Variable to take integer */
  float floatVal ; /* Varibale to take floating point val */
  float sqroot ;
  
  printf("Enter the integer value: ");
  scanf("%d", &intVal);


  sqroot = pow(intVal , (0.5));

  printf("Square Root through exponent is : %f \n", sqroot);

  sqroot = sqrt(intVal); 
  
  printf("Square Root through build in lib is %f \n", sqroot);
}

