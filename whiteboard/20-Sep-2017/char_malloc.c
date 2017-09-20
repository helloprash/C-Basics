
#include <stdio.h>
#include <malloc.h>
#include <string.h>
main()
{
  char *str ;
  int len ;
  int idx ;
  scanf("%d", &len);
  printf("Heap address range is 01a7d000-01bc8000 \n");
  printf("The locatio pointed by str before malloc is %x \n", str);
  str =  malloc(len*sizeof(char));
  printf("The locatio pointed by str after malloc is %x \n", str);
  strcpy(str, "Hello");
  printf("%s\n\n", str);
  free(str);
}
