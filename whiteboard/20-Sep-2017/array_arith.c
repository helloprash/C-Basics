#include <stdio.h>

main()
{
  char myname[10];
  char *cptr1;
  char *cptr2 ;

  int list[10];
  int *iptr1 ;
  int *iptr2 ;

  double longArray[10];
  double *dptr1 ;
  double *dptr2 ;

  cptr1 = &myname[2] ;
  cptr2 = &myname[3] ;
  printf("cptr1 = %d, cptr2 = %d, diff = %d \n",
                  cptr1, cptr2,cptr1-cptr2);
  cptr1 = &myname[2] ;
  cptr2 = &myname[5] ;
  printf("cptr1 = %d, cptr2 = %d, diff = %d \n",
                  cptr1, cptr2,cptr1-cptr2);


  iptr1 = &list[4];
  iptr2 = &list[6];
  printf("iptr1 = %d, iptr2 = %d, diff = %d \n",
                  iptr1, iptr2,iptr1-iptr2);
  dptr1 = &longArray[4];
  dptr2 = &longArray[6];
  printf("dptr1 = %d, dptr2 = %d, diff = %d \n",
                  dptr1, dptr2,dptr1-dptr2);


  printf("Addition of two char pointers = %d\n", (cptr1 + 2130175542)) ;
  //printf("Addition of two char pointers = %d\n", cptr1 + cptr2) ;
}
