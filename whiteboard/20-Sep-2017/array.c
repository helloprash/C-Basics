#include <stdio.h>
main()
{
   char  array[5];
   char *ptr ;
   array[0] = 'x' ;
   array++ ; /* is illegal */
   ptr = array ;
   printf("Value of array = %x\n", array);
   printf("Value of *array = %c\n", *array);
   ptr++ ;
}
