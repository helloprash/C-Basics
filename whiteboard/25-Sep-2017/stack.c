#include<stdio.h>
#define STACKSIZE 100
#define SUCCESS 1
#define FAILURE 0
int push(int Stack[], int *topPtr,int Data)
{

   if (*topPtr < STACKSIZE)
   {
     (*topPtr)++ ;
     Stack[*topPtr] = Data ;
     return SUCCESS;
   }
   else
       return FAILURE;
}

int pop(int Stack[] , int *ptr,int *Data)
{
    if (*ptr > -1)
    {
         *Data = Stack[*ptr];
          (*ptr)-- ;
          return SUCCESS ;
    }
    else
    {
       return FAILURE ;
    }
}
void PrintStack(int Stack[], int ptr)
{
    int i ;
    printf("Stack : %d  elements: ", ptr);
    for (i=0;i <= ptr ; i++)
    {
        printf("%d ", Stack[i]);
    }
    printf("\n");
}

main()
{
    int choice;
    int flag ;
    int stack[STACKSIZE];
    int stackTopPtr ;
    int data ;

    stackTopPtr = -1;
    flag = 1 ;
    do
    {
      printf("Menu\n");
      printf("1. Push\n");
      printf("2. Pop \n");
      printf("3. Exit \n");
      scanf("%d", &choice);
      switch(choice)
      {
         case 1 : {
                    printf("Enter data to be pushed: ");
                    scanf("%d", &data);
                    if (push(stack,&stackTopPtr,data) == FAILURE)
                        printf("Push not allowed :Stack FULL\n");
                    PrintStack(stack,stackTopPtr);
                    break ;
                  }
         case 2 : {
                    if (pop(stack,&stackTopPtr, &data) == FAILURE)
                    {
                       printf("Pop no allowed: Stack is empty \n");
                    }
                    PrintStack(stack,stackTopPtr);
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
