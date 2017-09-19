#include <stdio.h>
#include <string.h>
int strTok(char *input, char delimiter,char *token) 
{
   /* if the function has hit the end of string it wil
      return ZERO otherwise 1 */
   static char *buffer ;
   static int  position ;
   int idx ;
   int flag ;
   if (input != NULL)
   {
       buffer = input ;
       position = 0 ;
       flag = 1 ;
       /* Search for the delimiter and return */
       while(flag)
       {
          if buffer[position] == delimiter)
          {
              /* We had found the token */
              for (idx = 0 ; idx < position;idx++)
              {
                 token[idx] = buffer[idx];
              }
              token[idx] = '\0';
              return 1 ;
          }
          if (buffer[position] == NULL)
          {
             return 0;
          }

          position++ ;
       }

   }
   else
   {
      /* Repeated call */
      if (buffer == NULL)
      {
        token = NULL ;
         return 0 ;
      }
      /* Search for the delimiter and return */
   }


}

main()
{
}
