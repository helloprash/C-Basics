#include <stdio.h>

void main()
{
  int i,j;
  printf("Address of variable i in HEX is %x in Decimal %d\n", &i,&i);
  i = 10;
  printf("Address of variable i in HEX is %x in Decimal %d value is %d \n", &i,&i,i);
  printf("Address of variable j in HEX %x in Decimal %d\n", &j,&j);
  return 10;
}
