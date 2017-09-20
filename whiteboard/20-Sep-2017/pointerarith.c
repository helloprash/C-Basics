#include <stdio.h>

main()
{
  char x ;
  char y ;

  char *a ;
  char *b ;

  int p ;
  int q ;
  int *s ;
  int *t ;

  double l ;
  double m ;
  double *n ;
  double *o ;
  a = &x ;
  b = &y ;
  printf("Stack Range = 7e9ff000-7ea20000 \n");
  printf("Size of char is : %d \n", sizeof(char));
  printf("char :Addrss of x = %x, Addr of y = %x, diff = %d \n",
                   a,b, a-b);

  p = 321 ;
  s = &p;
  t = &q ;
  printf("Value strored in p is %d, through ptr *s is %d\n", p,*s);
  printf("Size of int is : %d \n", sizeof(int));
  printf("int :Addrss of p = %d, Addr of q = %d, diff = %d \n",
                   s,t, s-t);

  n = &l;
  o = &m ;
  printf("Size of double is : %d \n", sizeof(double));
  printf("int :Addrss of p = %d, Addr of q = %d, diff = %d \n",
                   n,o, n-o);

}
