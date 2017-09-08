

# Date of submission 11-Sep by 4:00 PM 
## Submission has to be made through github only 



1. Read an array of 1000  numbers from a file
1. Implement Binary search in C to check whether the given number is there or not. **Algorithm for Binary search is given towards the end of this page** 
1. **How to generate 1000 nums**
    1. *Write a program in C to generate 1000 random numbers and write the numbers into a file as discussed
    1. Copy paste that to excel Use MS excel as a col
    1. Sort it using Excel function and copy paste it back into your input file*

1. Implement Linear search as discussed in class
1. Compare the difference in terms of number of comparisons made by  Linear and Binary search Also find the time difference of execution to between Binary search and linear search. Draw a table and write down the difference in performance between two when the item you searched was
      1. Was there in the array
      1. Was not there in the array
      1. Was there toward the beginning of the array
      1. Was there towards the end of array

1. Learn HTML basics from  W3 Tutorials and  write the output of the above program into HTML file properly formatted


## Algorithm for Binary Search
```javascript

Procedure binary_search
   A ← sorted array
   n ← size of array
   x ← value to be searched

   Set lowerBound = 1
   Set upperBound = n 

   while x not found
      if upperBound < lowerBound 
         EXIT: x does not exists.
   
      set midPoint = lowerBound + ( upperBound - lowerBound ) / 2
      
      if A[midPoint] < x
         set lowerBound = midPoint + 1
         
      if A[midPoint] > x
         set upperBound = midPoint - 1 

      if A[midPoint] = x 
         EXIT: x found at location midPoint

   end while
   
end procedure

```
