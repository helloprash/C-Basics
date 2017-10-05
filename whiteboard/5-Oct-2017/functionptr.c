# Function Pointers

In previous days example let us say in the structure
```
typedef struct usage
{
    char name[10];
    int  age ;
    int usage;
    int planID ;
    struct usage *next ;
} USAGE;
```

We want to do billing based on the plan ID. Plan ID can take values 1,2,3,4 

Plan 1   
hours | Charges
------|---------
50 hr | free usage
100   | 50ps
100   | 55ps
more  | 60ps

Plan 2   
hours | Charges
------|---------
75 hr | free usage
100   | 45ps
100   | 50ps
more  | 55ps

Plan 3   
hours | Charges
------|---------
90 hr | free usage
100   | 45ps
100   | 50ps
more  | 55ps

Plan 4   
hours | Charges
------|---------
100 hr | free usage
100   | 40ps
100   | 50ps
more  | 30ps

```
#include <stdio.h>
// A normal function with an int parameter
// and void return type
void fun(int a)
{
    printf("Value of a is %d\n", a);
}
 
int main()
{
    // fun_ptr is a pointer to function fun() 
    void (*fun_ptr)(int) = &fun;
 
    /* The above line is equivalent of following two
       void (*fun_ptr)(int);
       fun_ptr = &fun; 
    */
 
    // Invoking fun() using fun_ptr
    (*fun_ptr)(10);
 
    return 0;
}
