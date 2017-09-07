#include <stdio.h>
bmain()
{
  char key1,key2 ;
  int  num;

  printf("print enter two numbers without spaces\n");

  scanf("%c%c", &key1,&key2);


  printf("print enter a number \n");
  scanf("%d", &num);


  printf("The ASCII value of  number %d is %c\n",num,num);
  printf("The key entered is %c %c \n", key1, key2);

  printf("The key entered is %d \n", key1);

  if ( (key1 >= 65) && (key1 <= 90) )
  {
     printf("The value is upper case ");

  }
