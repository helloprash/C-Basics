#include <stdio.h>
main()
{
  int menuChoice;
  int flag ;
  printf(" ******* Menu *********\n");
  printf(" 1.Billing\n");
  printf(" 2.Customer Order\n");
  printf(" 3.Checking the stock\n");
  printf(" 4.Updating the stock\n");
  printf(" 5.Exit\n");
  printf(" ******* Make a choice *********\n");
 
  flag = 1 ; 
  while(flag == 1)
  {
  scanf("%d", &menuChoice);

      switch(menuChoice)
      {
         case 1: 
                {
                   printf(" Billing Module\n");
                   break;
                }
         case 2: 
                {
                   printf(" Customer Order Module\n");
                   break ;
                }
         case 3: {
                    printf(" Checking the stock\n");
                    break ;
                 }
         case 4: {
                    printf(" Updating the stock\n");
                    break ;
                 }
         case 5: 
               {  
                 printf(" Exiting\n");
                 flag = 0; 
                 break ;
               }
         default: printf("Error \n");
      } 
  }
}
