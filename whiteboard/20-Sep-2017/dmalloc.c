#include <stdio.h>
#include <malloc.h>
main()
{
  double *list ;
  double *ptr ;
  int count ;
  list  = (double*) malloc(sizeof(double)* 10);
  /* the above statement is equivalent to double list[10] created
     on stack, here the same is created on heap */

  ptr = list ; /* Pointer to the first location to list */

  *ptr = 100000.12345 ;
  ptr++ ;
  *ptr = 10001.12345 ;
  ptr++ ;
  *ptr = 10002.12345 ;
  ptr = list;
  for(count=0; count < 3;count++)
  {
    printf("%f ", *ptr);
    ptr++ ;
  }
}
