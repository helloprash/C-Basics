````
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int findDelimiter(char *str)
{

}
int myPrintf(char *str,...)
{
  va_list argumentList ;
  int value ;
  int  noOfArgs =0;
  int  flag ;
  char *ptr ;
  char  token[4];
  char  formatString[50];
  int len ;
  int tokenLocation[100];
  int valueArray[100];

  int tokenPtr = 0;
  int i ;
  char ch ;
  char valStr[2];
  printf("%s",str);

  strcpy(formatString, str);
  len = strlen(str);
  tokenPtr = 0;
  for (i = 0 ; i< len ; i++)
  {
     if (formatString[i] == '%')
     {
        tokenLocation[tokenPtr] = i;
        tokenPtr++;
        noOfArgs++ ;
     }
  }

  va_start(argumentList, noOfArgs) ;

  tokenPtr = 0 ;
 for (i = 0 ; i < noOfArgs ; i++)
  {
     value = va_arg(argumentList,int);
     valueArray[tokenPtr] = value ;
     tokenPtr++ ;
  }
  tokenPtr = 0;

  for (i = 0 ; i < noOfArgs; i++)
  {
    printf("%d ", tokenLocation[i]);
    printf("%d \n", valueArray[i]);
  }

  for (i = 0 ; i < noOfArgs ; i++)
  {
    sprintf(valStr,"%d",  valueArray[i]);
    formatString[tokenLocation[i]] = valStr[0] ;
    formatString[tokenLocation[i]+1] = ' ' ;
    tokenPtr++;

  }
  printf("%s", formatString);
  return noOfArgs ;
}
main()
{
   int x =  7 ;
   int y =  9 ;
   int z =  4 ;
   int args = 0;

   args = myPrintf("The values are 1-st=  %d  2-nd=  %d 3rd=  %d  \n", x,y,z);
   printf("No of arguments passed = %d \n", args);
}

````

