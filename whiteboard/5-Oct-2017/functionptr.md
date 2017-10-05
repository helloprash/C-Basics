# Function Pointers

In previous days example let us say in the structure
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
