
# BIT Fields in C
In C, we can specify size (in bits) of structure and union members. The idea is to use memory efficiently when we know that the value of a field or group of fields will never exceed a limit or is withing a small range.

```
#include <stdio.h>
 
// A simple representation of date
struct date
{
   unsigned int d;
   unsigned int m;
   unsigned int y;
};
 
int main()
{
   printf("Size of date is %d bytes\n", sizeof(struct date));
   struct date dt = {31, 12, 2014};
   printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);
}
```

The above representation of ‘date’ takes 12 bytes on a compiler where an unsigned int takes 4 bytes. Since we know that the value of d is always from 1 to 31, value of m is from 1 to 12, we can optimize the space using bit fields.

```
#include <stdio.h>
 
// A space optimized representation of date
struct date
{
   // d has value between 1 and 31, so 5 bits
   // are sufficient
   unsigned int d: 5;
 
   // m has value between 1 and 12, so 4 bits
   // are sufficient
   unsigned int m: 4;
 
   unsigned int y;
};
 
int main()
{
   printf("Size of date is %d bytes\n", sizeof(struct date));
   struct date dt = {31, 12, 2014};
   printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);
   return 0;
}

```

### Rule with Bit Wise Fields
1. We cannot have pointers to bit field members as they may not start at a byte boundary.
1. Array of bit fields is not allowed. For example, the below program fails in compilation.

### Operators in Bit Fields
Operator | Meaning 
---------|------
 &	 | AND 
 ^  | XOR
 ~  | One's Compliment
<<	 | Left shift
>>	 | Right Shift
