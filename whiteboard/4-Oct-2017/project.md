# 4-October-2017



## Problem for class project
### A mobile service provider company like Vodaphone has a huge database of usage by various customer they want to study the pattern on usage and come out with a new scheme (charing plans) for various user. For this you are expect to develop a software.

### Objective of this exercise is to develop a software which read data from a csv file and generate the output that can be visualized in the form graphs.  As the first step you will be read data from .csv file classify the data according to the requirements and store the results into a array. Then the data stored in the array is written to .csv file

1. Read Data from .csv file and store it into a linked list
1. Classify the data based on the requirements given in the next section and store results into a array
1. Write the contents on the results array into a .csv file


####Usage data of the users is stored in a .csv file as per the following format
```
Name, age, usage, planID
Anil,   20,   300,    3
Sudhir, 35,   100     2
Vipin   18,   50,      2
.........................
..........................
........................
........................
Hema   40,  291,   1
````

The above  has to be read from .csv file and stored in a **linked list** based on the following structure

```
struct usage
{
    char name[10];
    int  age ;
    int usage;
    int planID ;
}
```

### Requirments for classification

Once the linked list is created, you need to read/scan through the list and find the customer who had the max or highest usage. Take that value as the max. Now find the 90% , 80% 70%, 60%, 50% 40% of the max value. as example is shown below. Let say the among all the customer the max usage was for two customer who made calls for 400 hours in that month. Now take 400 as 100% calculate 90 % of 400, 80% of 400 ....... as shown below.

Percent | Usage
----    | ----
 100%  |  400 hours
 90%   |  360
 80%   |  320
 70%   |  280
 60%   |  240
 50%   |  200
 40%   |  160
 30%   |  120
 20%   |  80
 10%   |  40

You need find out how many usesrs are there in the 100% bracket how many are there in 90% bracket and so on in the 10% bracket
For example of the a users usage is 350 hours which greater than 90% but less than 100% that user will fall into 100% bracket
Another user whos usage in 240 will fall into 60% bracket, another user who used 281 hours will fall into 80% bracket.

You can create an array to struct as follows to store this classified data

```
struct classifed
{
   int bracket
   int numberOfUsers
}
```
Finally you need to write the classified data into a .csv file

## After which I will explain the new concepts of (based on this project)
1. Data Visulization 
1. Union
1. Enums
