
#include <stdio.h>
#include <string.h>

   char str[20];
   int i , len;
int Print(int x)
{
   int idx ;
   if (x == 0)
   {
   printf ("%c ", str[x]);
    return 0;
   }
   printf ("%c ", str[x]);
   x = Print(x-1) ;
}
main()
{
   strcpy(str,"Hello123");
   len = strlen(str);
   Print(len);
}
