#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
main(int argc, char *argv[])
{
   FILE *htmlPtr ;
   char fileName[10];
	int Rnumber[1000]; // holds 1000 random numbers
	char in_Filename[10];//input filename
	int retVal;    //holds value returned by scanf() 
	int search_element; //number to be searched
	int flag;
	int idx;  // index to Rnumber array
	int x;    // holds read number from fscanf 
	int index;    // holds value returned by binary search function
	idx=0;
	flag = 1;


   if (argc > 1 )
   {
      strcpy(in_Filename,argv[1]);
   }
   else
   {
      printf("File name not  mentioned in the command line\n");
      exit(1);
   }
   strcpy(fileName, "/var/www/html/index.html");
   htmlPtr = fopen(fileName, "w");
   
   if (htmlPtr == NULL)
   {
      printf("Unable to too open the file %s \n", fileName); 
      exit(1);  
   }

   fprintf(htmlPtr,"<HTML>\n");
   fprintf(htmlPtr,"<meta http-equiv=\"refresh\" content=\"1\">\n");
   fprintf(htmlPtr,"<H1> Result of computation </H1>\n"); 

   retVal = ReadArray(Rnumber,in_Filename,htmlPtr);
   if (retVal == 0)
   {
      fprintf(htmlPtr,"<P> Unable to read data from file %s</P> \n",
                       in_Filename);
      fprintf(htmlPtr,"</HTML>\n");
      fclose(htmlPtr);
      exit(1); 
   }
   PrintArray(Rnumber,htmlPtr,retVal);
   Sort(Rnumber,retVal,htmlPtr);
   PrintArray(Rnumber,htmlPtr,retVal);
   fprintf(htmlPtr,"</HTML>\n");
   fclose(htmlPtr);
}
int PrintArray(int a[] ,FILE *outputhtmlPtr,int length)
{
  int idx ;

  fprintf(outputhtmlPtr, "<P>");

  for(idx = 0 ; idx < length  ; idx++)
  {

      
      fprintf(outputhtmlPtr,
              "|%d",
              a[idx]);
  }
  fprintf(outputhtmlPtr, "</P>");
  return ; 
}

int ReadArray(int a[],char *fileName, FILE *outputhtmlPtr)
{
    int flag;
    int retVal ;
    int idx ;
    int   x;
    FILE  *inptr ;
    flag = 1 ;
 
    inptr = fopen(fileName,"r");

   if(inptr == NULL)
   {
        fprintf(outputhtmlPtr,"<p>the error with file open is %d</p>\n",errno);
        fprintf(outputhtmlPtr,"%s\n",strerror(errno));
        fprintf(outputhtmlPtr,"</HTML>\n");
        fclose(outputhtmlPtr);
        return 0 ; 
    }

    while(flag)
    {
                retVal = fscanf(inptr,"%d",&x);

                if(retVal == EOF)
                {
                        flag = 0;
                }
                else
                {
                  a[idx] = x;
                  idx++;
            }
    }
    fclose(inptr);
    return idx ;
}
int Sort(int a[],int length, FILE *outhtml)
{
    int temp; /* Temporary variable for swapping */
    int i ; /* Indicate my left hand pointer to the array */
    int j ; /* Indicate my right hand pointer to the array */
    
    for (i=0; i < length -1 ; i++)
    {
       for (j=i+1; j < length ; j++)
       {
         if (a[i] > a[j] )
         {
             temp = a[i];
             a[i] = a[j];
             a[j] = temp ;
         }
         PrintArray(a,outhtml,length);
       }
     }
		
}
