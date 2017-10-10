# What are Unions
A union is a special data type available in C that allows storing different data types in the **same memory** location. You can define a 
union with many members, but only one member can contain a value at any given time. Unions provide an efficient way of using the 
same memory location for multiple purposes.
## Defining a Union
```
union [union name]
    {
       member definition;
       member definition;
       ...
       member definition;
    };
 ```
 
 ## Examples Code with union
 
 ### 1. Simple Example of Union and size of Union
 ```
#include <stdio.h>
#include <string.h>
 
union Data {
   int i;
   float f;
   char str[20];
};
 
int main( ) {

   union Data data;        
   

   printf( "Memory size occupied by data : %d\n", sizeof(data));

   return 0;
}
```


### 2. Accessing members of Union

```
#include <stdio.h>
#include <string.h>
 
union Data {
   int i;
   float f;
   char str[20];
};
 
int main( ) {

   union Data data;        

   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");

   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);

   return 0;
}
```

### 3. Accessing members one at time

```
#include <stdio.h>
#include <string.h>
 
union Data {
   int i;
   float f;
   char str[20];
};
 
int main( )
{

   union Data data;        

   data.i = 10;
   printf( "data.i : %d\n", data.i);
   
   data.f = 220.5;
   printf( "data.f : %f\n", data.f);
   
   strcpy( data.str, "C Programming");
   printf( "data.str : %s\n", data.str);

   return 0;
}

```
Here, all the members are getting printed very well because one member is being used at a time.

###  //  C program to illustrate differences  between struct and union

 ```

// between structure and Union
#include <stdio.h>
#include <string.h>
  
// declaring structure
struct struct_example
{
    int integer;
    float decimal;
    char name[20];
};
  
// declaraing union
  
union union_example
{
    int integer;
    float decimal;
    char name[20];
};
  
void main()
{
    // creating variable for structure 
    // and initializing values difference 
    // six
    struct struct_example s={18,38,"geeksforgeeks"};
  
    // creating variable for union 
    // and initializing values
    union union_example u={18,38,"geeksforgeeks"};
  
          
    printf("structure data:\n integer: %d\n"
                "decimal: %.2f\n name: %s\n",
                s.integer, s.decimal, s.name);
    printf("\nunion data:\n integeer: %d\n"
                 "decimal: %.2f\n name: %s\n", 
                u.integer, u.decimal, u.name);
  
  
    // difference two and three
    printf("\nsizeof structure : %d\n", sizeof(s));
    printf("sizeof union : %d\n", sizeof(u));
      
    // difference five
    printf("\n Accessing all members at a time:"); 
    s.integer = 183;
    s.decimal = 90;
    strcpy(s.name, "geeksforgeeks");
      
    printf("structure data:\n integer: %d\n "
                "decimal: %.2f\n name: %s\n",
            s.integer, s.decimal, s.name);
      
    u.integer = 183;
    u.decimal = 90;
    strcpy(u.name, "geeksforgeeks");
      
    printf("\nunion data:\n integeer: %d\n "
                "decimal: %.2f\n name: %s\n",
            u.integer, u.decimal, u.name);
      
    printf("\n Accessing one member at time:");
      
    printf("\nstructure data:");
    s.integer = 240;
    printf("\ninteger: %d", s.integer);
      
    s.decimal = 120;
    printf("\ndecimal: %f", s.decimal);
      
    strcpy(s.name, "C programming");
    printf("\nname: %s\n", s.name);
      
    printf("\n union data:");
    u.integer = 240;
    printf("\ninteger: %d", u.integer);
      
    u.decimal = 120;
    printf("\ndecimal: %f", u.decimal);
      
    strcpy(u.name, "C programming");
    printf("\nname: %s\n", u.name);
      
    //difference four
    printf("\nAltering a member value:\n");
    s.integer = 1218;
    printf("structure data:\n integer: %d\n "
                " decimal: %.2f\n name: %s\n",
                s.integer, s.decimal, s.name);
      
     
    u.integer = 1218;
    printf("union data:\n integer: %d\n"
           " decimal: %.2f\n name: %s\n",
            u.integer, u.decimal, u.name); 
}
 ```
 
## Differences between Struct and Union
![Union](unionStruct.jpg?raw=true "Optional Title")
