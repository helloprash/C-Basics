#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> 
#define TRUE 1 
#define FALSE 0
int SearchArray(int array[], int len,int searchNo)
{
  int idx ;
  int found ;
  found = FALSE ;

  for (idx = 0 ; idx<len; idx++)
  {
     if (array[idx] == searchNo)
     {
        found = TRUE ; 
        break ;
     }
  } 

  return found ;
   
}
main()
{
   FILE *inFilePtr ;
   char inFileName[10];

   int flag ;
   int i ;
   int numbers[100];
   int  idxToNum ;
   int  num ;
   int  retVal ;
   int  numToSearch ;

   printf("Enter the file name: ");
   scanf("%s", inFileName);

   printf("Enter the number to be searched: ");
   scanf("%d", &numToSearch);
   inFilePtr = fopen(inFileName, "r");

   if (inFilePtr == NULL)
   {
      printf("File open error with %s \n",inFileName);
      printf("Error number retuned = %d \n", errno);
      printf("%s\n",strerror(errno));
      exit(0);
   }
   flag = 1 ;
   idxToNum = 0;

   while(flag)
   {
     retVal = fscanf(inFilePtr, "%d", &num);
     if (retVal == EOF)
     {
       flag = 0 ;
     }
     else
     {
       numbers[idxToNum] = num ;
       idxToNum++ ;
     }
   }
   fclose(inFilePtr);

   for(i = 0; i<idxToNum;i++)
   {
     printf("|%d",numbers[i] );
   }
   printf("\n");

   if (SearchArray(numbers, idxToNum, numToSearch) == TRUE)
   {
       printf("The number %d is there in the array\n", numToSearch);
   }
   else 
   {
       printf("The number %d is NOT there in the array\n", numToSearch);
   }
   
}
