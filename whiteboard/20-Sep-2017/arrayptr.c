#include <stdio.h>

main()
{
   int array[4];

   int idx ;

   for (idx = 0 ; idx < 4 ; idx++)
   {
      printf("Address of array[%d] is %x\n", idx,&array[idx]);
   }
   printf("array = %x\n", array);
}
