#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EAST 'E'
#define WEST 'W'
#define NORTH 'N'
#define SOUTH 'S'
#define SOUTHWEST 'C'
#define SOUTHEAST 'B'

#define NORTHWEST 'D'
#define NORTHEAST 'A'
typedef struct
 {
    char date[10];
    int  windSpeed ;
    char direction ; /* N north, S south, W west, E -East, A NE, B SE C SW, D NW */
    float pressure ;
    float temp ;
    float humdity ;
    float precipitation ;
    float solarRadiation ;
    float rainFall ;
    int   haze ;
 } WEATHER ;
main(int argc, char **argv)
{
  FILE *csvFilePtr ;
  char csvFileName[10];
  int flag ;
  char buffer[200];
  char *record ;
  int parseFlag ;
  int tokenNo ;
  WEATHER weatherData[100];  
  int  weatherDataIdx ;
  int  numberOfRecords ;
  if (argc >1 )
  {
     strcpy(csvFileName,argv[1]);
  }
  else
  {
     printf("Wrong comand line args\n");
     exit(1);
  }

  csvFilePtr = fopen(csvFileName,"r");

   if(csvFilePtr == NULL)
   {
      printf("Unable to open the CSV file \n");
      exit(1);
   }
  flag =1 ;
  weatherDataIdx = 0 ;
  fgets(buffer,200, csvFilePtr);
  while(flag)
  {
     if (fgets(buffer,200, csvFilePtr) == NULL)
     {
       
       flag = 0 ;
       continue ;
     }
     parseFlag = 1;
     tokenNo = 0 ;
     record = strtok(buffer, ","); 
     /* printf(" %d  token = %s \n ",tokenNo, record); */

     strcpy(weatherData[weatherDataIdx].date , record) ; 
     tokenNo++ ;

     while(parseFlag)
     {
        record = strtok(NULL, ","); 
        if (record == NULL)
        {
          parseFlag = 0 ;
          continue ;
        }
        switch(tokenNo)
        {
           case 1 : 
                  { 
                     weatherData[weatherDataIdx].windSpeed =atoi(record) ;
                     break ;
                  }
           case 2 : 
                  { 
                     if (strcmp(record,"N") == 0)
                     {
                         weatherData[weatherDataIdx].direction = NORTH ;
                     }
                     if (strcmp(record,"S") == 0)
                     {
                         weatherData[weatherDataIdx].direction = SOUTH ;
                     }
                     if (strcmp(record,"E") == 0)
                     {
                         weatherData[weatherDataIdx].direction = EAST ;
                     }
                     if (strcmp(record,"W") == 0)
                     {
                         weatherData[weatherDataIdx].direction = WEST ;
                     }
                     if (strcmp(record,"NE") == 0)
                     {
                         weatherData[weatherDataIdx].direction = NORTHEAST ;
                     }
                     if (strcmp(record,"SE") == 0)
                     {
                         weatherData[weatherDataIdx].direction = SOUTHEAST ;
                     }
                     if (strcmp(record,"SW") == 0)
                     {
                         weatherData[weatherDataIdx].direction = SOUTHWEST ;
                     }
                     if (strcmp(record,"NW") == 0)
                     {
                         weatherData[weatherDataIdx].direction = NORTHWEST ;
                     }
                     break ;
                  }
           case 3 : 
                  { 
                     weatherData[weatherDataIdx].temp =atof(record) ;
                     break ;
                  }
           case 4 : 
                  { 
                     weatherData[weatherDataIdx].pressure =atof(record) ;
                     break ;
                  }
           case 5 : 
                  { 
                     weatherData[weatherDataIdx].humdity  =atof(record) ;
                     break ;
                  }
                     
           case 6 : 
                  { 
                     weatherData[weatherDataIdx].precipitation =atof(record) ;
                     break ;
                  }
           case 7 : 
                  { 
                     weatherData[weatherDataIdx].haze =atoi(record) ;
                     break ;
                  }
           case 8 : 
                  { 
                     weatherData[weatherDataIdx].solarRadiation   =atof(record) ;
                     break ;
                  }
           case 9 : 
                  { 
                     weatherData[weatherDataIdx].rainFall  =atof(record) ;
                     break ;
                  }
           default :
                  {
                      printf("Extra valyes found in the line %s \n", record);
                  }
        } 
        /* printf(" %d  token = %s \n ",tokenNo, record); */
        tokenNo++ ; 
     }
     weatherDataIdx++;
   }
   numberOfRecords = weatherDataIdx;
   for (weatherDataIdx=0; weatherDataIdx < numberOfRecords ; weatherDataIdx++)
   {
      printf("date %s\n ",weatherData[weatherDataIdx].date);
      printf("speed %d\n ",weatherData[weatherDataIdx].windSpeed);
      printf("dir: %c\n ",weatherData[weatherDataIdx].direction);
      printf("pressure %f\n ",weatherData[weatherDataIdx].pressure);
      printf("temp :%f\n ",weatherData[weatherDataIdx].temp);
      printf("humidty %f\n ",weatherData[weatherDataIdx].humdity);
      printf("prec: %f\n ",weatherData[weatherDataIdx].precipitation);
      printf("radiation:%f\n ",weatherData[weatherDataIdx].solarRadiation);
      printf("rain %f\n ",weatherData[weatherDataIdx].rainFall );
      printf("haze %d\n ",weatherData[weatherDataIdx].haze );
      printf("------------\n\n ");
   }   
    
}

