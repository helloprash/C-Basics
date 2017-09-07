#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

main()
{
   FILE *inFilePtr ;
   char inFileName[10];

   int flag ;
   int i ;
   char text[100];
   int  idxToText ;
   char ch ;
   int  retVal ;

   printf("Enter the file name: ");
   scanf("%s", inFileName);

   inFilePtr = fopen(inFileName, "r");

   if (inFilePtr == NULL)
   {
      printf("File open error with %s \n",inFileName);
      printf("Error number retuned = %d \n", errno);
      printf("%s\n",strerror(errno));
      exit(0);
   }
   flag = 1 ;
   idxToText = 0;

   while(flag)
   {
     retVal = fscanf(inFilePtr, "%c", &ch);
     if (retVal == EOF)
     {
       flag = 0 ;
     }
     else
     {
       text[idxToText] = ch ;
     printf("|%c %d|", ch ,ch);
       idxToText++ ;
            }
   }
   text[idxToText] = '\0';
   printf("%s", text);
   fclose(inFilePtr);

   for(i = 0; i<strlen(text);i++)
   {
     printf("|%c %d|", text[i],text[i]);
   }
}

