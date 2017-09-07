#include <stdio.h>
#include <string.h>
main()
{ 
  int idx ;
  char name[3]; 
  char name1[3]; 
  char ch ,empty;
  int len ;

  scanf("%s", name);

  printf("%s \n",name);
  len = strlen(name);
  printf("Length of string=%d  \n",len);
  printf("%s \n",name1);
  printf("%x, %x\n", name, name1) ;
}
