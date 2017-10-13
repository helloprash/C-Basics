#include <stdio.h>

main()
{
  char str[100];
  int i, j, k ;

  i = 10 ;
  j = 13 ;
  k = 15 ;

 sprintf(str, "hello first = %d, second = %d , third = %d \n", i,j,k);
 printf("%s", str);
}

