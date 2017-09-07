#include <stdio.h>

main()
{
  enum week {Mon=1000,Tue,Wed,Thurs,Fri,Sat};

  enum week day ;

  day = Tue ;

  printf("Value of day = %d \n", day);
}
