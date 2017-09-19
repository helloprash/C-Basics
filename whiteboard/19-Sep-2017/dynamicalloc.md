# Need of Dynamic Memory Allocation
`````
main()
{
   int array[100];
}
`````

#### In the above case the size of array if fixed at compile time. But I want something like the following
`````
main()
{
  int arraySize ;
  
  
  printf("Enter Array size : ");
  scanf("%d", &arraySize);
  int array[arraySize];
}  
``````
#### Is the above operation legal or not ? it is not legal
This is why we go for dynamic memory allocation



