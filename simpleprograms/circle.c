#include <stdio.h>
#define PI 3.1432
main()
{ 
  float radius = 10 ;
  float area ;
  float circum ;
  area = PI * radius * radius  ;
  circum = 2 * PI * radius;

  printf("Area = %f , cirumference = %f \n", area, circum);

  
}
