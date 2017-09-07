#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
void ConvertToUpperCase(char *word)
{
   int len ;
   int idx ;
   len = strlen(word);
   for (idx = 0 ; idx <= len-1 ;idx++)
   {
      if ((word[idx] >= 97) && (word[idx] <= 122))
         word[idx] = word[idx] - 32;
   }

}
main()
{
  FILE *inputFilePtr ; /* File handle to input File */
  FILE *outputFilePtr ; /* File handle to output File */
  char myWord[10];
  char inputFileName[10];
  char outputFileName[10];
  int retVal ;
  int flag ;
  char errorMsg[4];

  printf("Enter the input file name : ");
  retVal = scanf("%s", inputFileName);

  printf("Enter the output file name : ");
  retVal = scanf("%s", outputFileName);


  inputFilePtr = fopen(inputFileName,"r"); /* Opening the file for reading */
    if (inputFilePtr == NULL)
  {
    printf("File open error with %s \n",inputFileName);
    printf("Error number retuned = %d \n", errno);
    printf("%s\n",strerror(errno));
    exit(0);
  }
  printf("Value of file pointer is %x \n", *inputFilePtr);


  outputFilePtr = fopen(outputFileName,"w"); /* Opening the file for reading */
  if (outputFilePtr == NULL)
  {
    printf("File open error with %s \n",outputFileName);
    printf("Error number retuned = %d \n", errno);
    printf("%s\n",strerror(errno));
    exit(0);
  }
  printf("Value of file pointer is %x \n", *outputFilePtr);
  flag = 1 ;
  while(flag == 1)
  {
    retVal = fscanf(inputFilePtr,"%s",myWord) ; /* Reading from the file */

    if (retVal > 0)
    {
      printf("The data read from file is |%s| \n", myWord);
      ConvertToUpperCase(myWord);
      fprintf(outputFilePtr,"%s", myWord);
    }
    else if (retVal == EOF)
          flag = 0;
  }
  
  
  fclose(inputFilePtr); /* closing the file after reading */
  fclose(outputFilePtr); /* closing the file after reading */
}



                                                                  34,1          84%
