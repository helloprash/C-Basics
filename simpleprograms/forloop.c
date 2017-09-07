#include <stdio.h>

main()
{
  int i ;
  int N ;

  printf("No of values to be captured: ");
  scanf("%d", &N);

  for(i=1;i <N;i=i+2)
  {
     printf("Value of i = %d \n",i);
  }
}
