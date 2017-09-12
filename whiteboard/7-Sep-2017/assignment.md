

# Date of submission 11-Sep by 4:00 PM 
## Submission has to be made through github only 


1. The basic performance parameters of a search algorithm we are interested are:
   1. No of comparisons made before the program arrived at a conclusion (whether the item is there in array or no)
   1. Time taken to arrive at conclusion whether the item is there in array or not.
1. Read an array of 1000  numbers from a file
1. Implement Binary search in C to check whether the given number is there or not in the array. **Algorithm for Binary search is given towards the end of this page** Measure the performance parameters of the Binary search algorithm. 
1. **How to generate 1000 numbers to do the search  and sort it**
    1. *Write a program in C to generate 1000 random numbers and write the numbers into a file as discussed*
    1. *Copy paste that to excel Use MS excel as a col*
    1. *Sort it using Excel function and copy paste it back into your input file*
1. Implement Linear search as discussed in class run linear search **on the unsorted array** sorted array is only fp and measure the basic performance parmeters mentioned in the top. 
1. Compare the performance parameters for   Linear and Binary search Draw a table and write down the difference in performance between two when the item you searched 
      1. Was there in the array  (unsorted array)
      1. Was not there in the array (unsorted array)
      1. Was there toward the beginning of the array (unsorted array)
      1. Was there towards the end of array (unsorted array)

1. Learn HTML basics from  https://www.austincc.edu/hr/profdev/eworkshops/docs/HTML_Basics.pdf and  write the output of the above program into HTML file properly formatted
   


## Algorithm for Binary Search
```javascript

int BinarySearch(int A[], int n , int x)
{
   A ← sorted array
   n ← size of array
   x ← value to be searched

   Set lowerBound = 1
   Set upperBound = n 

   while x not found
   {
      if upperBound < lowerBound 
         EXIT: x does not exists.
   
      set midPoint = lowerBound + ( upperBound - lowerBound ) / 2
      
      if A[midPoint] < x
         set lowerBound = midPoint + 1
         
      if A[midPoint] > x
         set upperBound = midPoint - 1 

      if A[midPoint] = x 
         EXIT: x found at location midPoint

    }
   
  }

```
