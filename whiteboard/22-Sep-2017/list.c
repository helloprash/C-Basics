
#include <stdio.h>
#include <malloc.h>
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
main()
{
  int flag ;
  WEATHER *node ;
  WEATHER *ptr1 ;
  WEATHER *start =NULL ;
  WEATHER *ptr3 ;
  WEATHER *ptr4 ;

  char wait[10];

   flag = 1 ;
   while(flag)
   {
     ReadDataFromSensor() ;
     node = (WEATHER*) malloc(sizeof(WEATHER));
     if (start == NULL)
        start = node ; /* Mark the beginning of the list */
        
     ptr1->next = node ; /* Link  the previous node's next pointer to the newly created node */
     
     ptr1 = node ; /* Make ptr1 point to newly creted node */
     node->next = NULL ; /* always set the next to NULL after creation in case this is the last one end is always marked */
     printf("Address of node is %x \n", node);
     node->windSpeed = 10 ;
     node->direction =  'N' ;
     node->temp = 30 ;
     node->humdity = 20 ;
     node->rainFall = 2 ;
     scanf("%s", wait);
   }
}
