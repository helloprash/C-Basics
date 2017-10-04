# 4-October-2017


## No Lectures
## Instead we are doing a small project in class today 
## -----------------------------------------------------------------------------------------------
##
## Problem
### A mobile service provider company like Vodaphone has a huge database of usage by various customer they want to study
### the pattern on usage and come out with a new scheme (charing plans) for various user. For this you are expect to
### develop a software.

### Objective of this exercise is to develop a software which read data from a csv file and generate the output that
### can be visualized in the form graphs.

## Statement
Usage data of the users is stored in a .csv file as following
NAme, age, usage, plan

THis is has to read from .csv file and stored in a structure
```
struct usage
{
    char name[10];
    int  age ;
    int usage;
    int planID ;
}
```

You need to create a linked list of strucutre using the above data.

Once the linked list is created, you need to read/scan through the list and find the customer who had the max usage. Take that value as the max. Now find the 90% , 80% 70%, 60%, 50% 40% of the max value. and example is shown below

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
