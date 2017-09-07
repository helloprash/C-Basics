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

  if (menuChoice == 1)
  {
      printf(" Billing Module\n");
  }
  else if (menuChoice == 2)
  {
      printf(" Customer Order Module\n");
  }
  else if (menuChoice == 3)
  {
      
      printf(" Checking the stock\n");
  } 
  else if (menuChoice == 4)
  {
     printf(" Updating the stock\n");
  }
  else if (menuChoice == 5)
  {
     printf(" Exiting\n");
     flag = 0; 
  }
  else 
  { 
     printf("Error");
  }
 }
}
