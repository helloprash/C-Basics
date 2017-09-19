#include <malloc.h>

main()
{
  char *str ;
  int len ;
  int idx ;
  scanf("%d", &len);
  printf("Value strored in str before malloc = %x\n", str);
  printf("Value strored in ampersad str before malloc = %x\n", &str);
  printf("Value strored in ampersad len  = %x\n", &len);
  printf("Value strored in ampersad idx  = %x\n", &idx);
  str = malloc(len);
  //printf("Value strored in str after malloc = %x", *str);
  printf("Enter a string : ");
  scanf("%s", str);
  printf("Value strored in str after malloc = %x\n", str);
  printf("Value strored in *str after malloc = %x\n", *str);
  printf("Value strored in ampersad str before malloc = %x\n", &str);
  printf("\n");
  printf("%s\n", str);

  for (idx = 0 ; idx < len; idx++)
  {
     printf("%c \n", str[idx]);
  }
  free(str);
}
