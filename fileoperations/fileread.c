#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
main()
{
  FILE *ptr ;
  char myWord[10];
  char fileName[10];
  int retVal ;
  int flag ;
  char errorMsg[4];

  printf("Enter the file name : ");
  retVal = scanf("%s", fileName);
  printf("The value returned by scanf is %d \n", retVal);
  
  ptr = fopen(fileName,"r"); /* Opening the file for reading */
  if (ptr == NULL) 
  {
    printf("File open error with %s \n",fileName);
    printf("Error number retuned = %d \n", errno);
    printf("%s\n",strerror(errno));
    exit(0);
  }
  printf("Value of file pointer is %x \n", *ptr);
  flag = 1 ;
  while(flag == 1)
  {
    retVal = fscanf(ptr,"%s",myWord) ; /* Reading from the file */
    if (retVal > 0)
    {
      printf("The data read from file is |%s| \n", myWord); 
    }
    else if (retVal == EOF)
          flag = 0; 
  }


  fclose(ptr); /* closing the file after reading */
} 


