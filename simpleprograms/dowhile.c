#include <stdio.h>
#define ISSUE 1
#define RETURN 2
#define ADDING 3
#define REMOVE 4
#define LOST 5
#define EXIT 6
main()
{
  int flag ;
  int choice ;
   flag = 0;
   do  
   {
     printf("1. Issue the book\n");
     printf("2. Return the book\n");
     printf("3. Adding a new book\n");
     printf("4. REmoving an old book \n");
     printf("5. Mark a book as lost \n");
     printf("6. Exit \n");  
     scanf("%d", &choice);
     switch(choice)
     {
        case ISSUE: { 
                    printf("Adding a book: ");
                 
                    break ;
                } 
        case RETURN: { 
                    printf("Adding a book: ");
                    break ;
                } 
        case ADDING: { 

                    printf("Adding a book: ");
                    break ;
                } 
        case REMOVE: { 
                    printf("Adding a book: ");
                    break ;
                } 
        case LOST: { 
                    printf("Adding a book: ");
                    break ;
                } 
        case EXIT: { 
                    flag = 0;                    
                    break ;
                } 
        default: {
                    printf("Error\n"); 
                 }
     }
       
   } while(flag == 1); 
   /* End of program */  

}
