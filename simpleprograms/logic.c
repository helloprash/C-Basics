#include <stdio.h>
#define AND &&
#define GT  >
main()
{
   int age, height;

   printf("Enter the age and height\n");
   scanf("%d %d", &age, &height);
  
   if ((age GT 15) AND (height GT 100))
   {
      printf("Candidate is qualified \n");
   }
   
}
