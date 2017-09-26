#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct weather
 {
    char date[10];
    int  windSpeed ;
    char direction ; /* N north, S south, W west, E -East, A NE, B SE C SW, D NW */
    float temp ;
    float humdity ;
    float rainFall ;
    struct weather  *next ;
 } WEATHER ;
void ReadDataFromSensor()
{
}



void PrintListBackward(WEATHER *start)
{
    WEATHER *currentPtr ;
    if (start == NULL)
    {
        return  ;
    }
    PrintListBackward(start->next);
    printf("Data wis %s \n", start->date);

}
void PrintListForward( WEATHER *start)
{
    WEATHER *currentPtr ;

    currentPtr = start ;
    while(currentPtr != NULL)
    {
       printf("Data is %s \n", currentPtr->date);
       printf("Data is %d \n", currentPtr->windSpeed);
       currentPtr = currentPtr->next ;
    }
}


void FreeList(WEATHER *start)
{
    WEATHER *currentPtr ;

    currentPtr = start ;
    while(currentPtr != NULL)
    {
       start = start->next ;
       free(currentPtr);
       currentPtr = start ;

    }
}

main()
{
  int flag ;
  WEATHER *node ;
  WEATHER *head =NULL ;
  WEATHER *tail ;

  char ans[10];

   flag = 1 ;
   while(flag)
   {
     ReadDataFromSensor() ;
     node = (WEATHER*) malloc(sizeof(WEATHER));
     if (node == NULL)
     {
       printf("Malloc failed \n");
       flag = 0 ;
       continue ;
     }
     printf("Enter the date:\n");
     scanf("%s", node->date);
     node->windSpeed = 10 ;
     node->direction =  'N' ;
     node->temp = 30 ;
     node->humdity = 20 ;
     node->rainFall = 2 ;
     node->next = NULL ;

     if (head == NULL)
     {
         head = node ;
         tail = node ;
    }
     else
     {
         tail->next = node ;
         tail = node ;
     }
     printf("Do you want to continue : Y/n ");
     scanf("%s",ans);
     if (strcasecmp(ans,"no")== 0)  /* NO, No, nO no */
     {
        flag = 0;
     }

   }
   PrintListForward(head);
   PrintListBackward(head);
   FreeList(head);
}
                          
