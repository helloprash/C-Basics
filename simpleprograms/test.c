#include <stdio.h>
main()
{
  int sensorData ;

  /* We are reading data from key board
     later when we integrate sensors we will
     replace scanf with sensor API
   */

  scanf("%d",&sensorData);

  if (sensorData  >=  100)
  {
     printf("%d \n",sensorData);
  }
  else
  {
     printf("The value %d is below the limit  \n",sensorData);
  }

}


