# Function Pointers

###Just like we have pointers which can hold address of variables, we can have pointers which holds the address of instructions stored in the memory

### What are fucntions ? Function are set of instruction in the memory packed a block. Now can we imagine a pointer holding the starting address of a function ? 

### Such a pointer is called a function pointer

### Just like we have an array of pointers we can have an array of function pointers.....
Each element in thhe array of function pointer can point to a different funtion.

ZERO-th element point to function which computes the billing for PLAN-1 and takes hours as input
FIRST-st element point to function which computes the billing for PLAN-2 and takes hours as input
SECOND- element point to function which computes the billing for PLAN-3 and takes hours as input
THIRD element point to function which computers the billing for PLAN-4 and takes hours as input
In previous days example let us say in the structure

TO Invoke the correct billing plan what we can do is 

Write Four Function

```
int PlanONE(int usage)
{
}

int PlanTWO(int usage)
{
}

int PlanTHREE(int usage)
{
}

int PlanFOUR(int usage)
{
}

```

** Declare an array of function pointers and assign the address of above functions to it  **
```
int (*arrayfxnpointer[4])(int)
```

Call the corresponding function pointer from the array

```
(*arrayfxnpointer[node->pan_id-1])(node->usage)
```


```
typedef struct usage
{
    char name[10];
    int  age ;
    int usage;
    int planID ;
    int monthlyCharges ;
    struct usage *next ;
} USAGE;
```

We want to do billing based on the plan ID. Plan ID can take values 1,2,3,4 

Plan 1  (Base charges Rs 100)

hours | Charges
------|---------
50 hr | free usage
100   | 50ps
100   | 55ps
more  | 60ps

Plan 2 (Base charges 300)

hours | Charges
------|---------
75 hr | free usage
100   | 45ps
100   | 50ps
more  | 55ps

Plan 3   (Base charges 400)

hours | Charges
------|---------
90 hr | free usage
100   | 45ps
100   | 50ps
more  | 55ps

Plan 4    (Base charges 500)

hours | Charges
------|---------
100 hr | free usage
100   | 40ps
100   | 50ps
more  | 30ps


```
void DoBilling()
{
   /* Read the node */
   /* Read Plan ID */
   
   switch(planID)
   {
   case 1 : {
             //Implement the logic given in Plan-1 Table */
             break ;
          }
  case 2 : {
             //Implement the logic given in Plan-2 Table */
             break ;
          }
  case 3:  {
             //Implement the logic given in Plan-3 Table */
             break ;
          }
 case 4 : {
             //Implement the logic given in Plan-4 Table */
             break ;
          }
   }
}
main()
{
  ReadRecordsIntoLinkedList();
  max = FindMax();
  FindPercentageOfMax(max);
  Classify();
  DoBilling();
}

```
