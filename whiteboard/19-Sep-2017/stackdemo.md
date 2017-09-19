# How System stack is used for executing functions


## Let look at the following code

```
void ComputeData()
{
   int l,m,n ;
   .
   .
    /* Create all local variables of ProcessValues() 
      on top of the stack ie create value l,m,n 
      top of current stack a stack
      */
   FindData()
   /* OS will pop the top most bundle from stack and restore
      the values of l.m,n and continue the execution */
   .
   .
   return ;
}
void ProcessValues()
{
   int p,q,r ;
   char x, y, z ;
   .
   .
    /* Create all local variables of ProcessValues() 
      on top of the stack ie create value  p,q,r,x,y,z
      top of current stack a stack
      */
   ComputeData()
   /* OS will pop the top most bundle from stack and restore
      the values of p,q,r,x,y,z and continue the execution */
   .
   .
   return ;
}
main()
{
   int a,b ;
   float value1, value2 ;
   .
   
   /* all the local variables of main()
      are created on the  stack ie pack the value  a,b,value1, value2 
      into  bundle and created on  top of the stack on to a stack
      */
   ProcessValues() /* Increment the stack pointer */
   /* OS will pop the top most bundle from stack and restore
      the values of a,b,value1, value2 and continue the execution */  
   .
   return ;
}
