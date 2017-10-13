#include<stdio.h>
#define QUEUESIZE 100
#define SUCCESS 1
#define FAILURE 0
#define EMPTY -999999
int AddQueue(int Queue[], int *head, int *tail,int Data)
{
   if (*tail < QUEUESIZE)
   {
       (*tail)++;
       Queue[*tail] = Data ;
   }

}

int RemoveQueue(int Queue[] , int *head, int *tail ,int *Data)
{
   int i ;
   if (*tail == -1)
   {
      return FAILURE ;
   }

   for (i=0;i<=*tail;i++)
   {
      Queue[i] = Queue[i+1];
   }
   (*tail)-- ;

}
void PrintQueue(int Queue[], int head, int tail)
{
   int i ;
   if (tail == -1)
   {
       printf("Queue is emptyn");
       return ;
   }
   for (i=0; i <= tail;i++)
   {
       printf("%d ",Queue[i]) ;
   }
}

main()
{
    int choice;
    int flag ;
    int queue[QUEUESIZE];
    int head ;
    int tail ;
    int data ;
    int idx ;

    flag = 1 ;
    head = 0 ;
    tail = -1  ;
    for (idx = 0; idx < QUEUESIZE ;idx++)
    {
        queue[idx] = EMPTY;
    }
    do
    {
      printf("Menu\n");
      printf("1. Add Queue\n");
      printf("2. Remove Queue\n");
      printf("3. Exit \n");
      scanf("%d", &choice);
      switch(choice)
      {
         case 1 : {
                    printf("Enter data to be added: ");
                    scanf("%d", &data);
                    AddQueue(queue, &head, &tail,data);
                    PrintQueue(queue, head, tail);
                    break;
                  }
         case 2 : {

                    RemoveQueue(queue, &head, &tail,&data);
                    PrintQueue(queue, head, tail);
                    break ;
                  }
         case 3:  {
                    flag = 0 ;
                    break ;
                  }
         default: {
                  }
      }
      
    } while(flag) ;


}

                 
