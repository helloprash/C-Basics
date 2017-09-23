# Assignment to be submitted on 25-Sep-2017 Monday
This assignment is quite different from the assignment I had given you earlier. Through this assignment I am introducing you to a new concept called **Incremental Development**  a very **Powerful Concept** in software development. Many complex softwares are developed with this approach. This approach will be very useful  during your interviews and in your professional career too. 
If you do not follow this approch I will reject your submission.

Read the **INSTRUCTIONS CAREFULLY** and do the assigement....
## Instructions
   1. Do this assignment is **steps as I had explained below. IF you do not follow the steps I will REJECT IT** 
   1. Read the problem 1 for the implementation of Single Link list first.
   1. Copy paste the outline code and compile it 
   1. You should get a linker error for the functions
   1. CreateList()
      1. AddNode()
      1. DeleteNode()
      1. DisplayList()
      1. DeleteList()
      1. SearchList()
   1. Do empty implememtation of these functions ie just write outline of function with no code and compile again
   1. All Linker errors should have gone away now
   1. Run the program and see menu is working or not. When you select 7 the program has to quit
      1. If you select the DisplayList option it should say list is empty 
   1. **Upload the file to Github now- This will create a version no 1 for this file**
   1. Implement the function **CreateList()** now
   1. Compile it and run - No output at this stage
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 2 for this file**
   1. Implement the function **DisplayList()**
   1. Compile it and run - You should be able to see the list now
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 3 for this file**
   1. Implement the function **SearchList()**
   1. Compile it and run - The search function should prompt for the data to be searched and you search for it in the list and say 
       it is found or not.
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 4 for this file**
   1. Implement the function **AddNode()**
   1. Compile it and run - You should be able to add new node and display the list correctly
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 5 for this file**
   1. Implement the function **DeleteNode()**
   1. Compile it and run - You should be able to delete a node and display the list correctly
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 6 for this file**
   1. Implement the function **DeleteList()**
   1. Compile it and run - You should be able to delete the list  and now if you try to display it should say list is empty
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 7 for this file**

** When I look at your assignment I need to SEE THE SIX VERSION CORRECTLY in github, otherwise I will reject it. **
** Please note that I will check for eight version and see the difference between them to see whether you had written each function in step by step approach or not. IF not I will reject it **

#### Based on the discussion we had today,you are expected to do the following exercise. Refer to whiteboard what is captured in the github.####

## 1. Implementation of Single Linked List
1.  Operation of Linked list
   1. Create Single Linked list
   1. Display the content of the linked list
   1. Delete an element in the linked list
   1. Add an element into the linked list
   1. Search for an element in the linked list
   1. Use a menu driven approach for creating,  displaying, adding, deleting and searching
   1. Use the following structure for writing the program in this assignment the work o
       you need to do is  implement the functions or write the following function.
       
      1. CreateList()
      1. AddNode()
      1. DeleteNode()
      1. DisplayList()
      1. DeleteList()
      1. SearchList()
      
      ````
         typedef struct node 
          {
             int data ;
             struct node *next ;
          } NODE ;
          
          /* Declare head of the list as a Global Variable */
          NODE  *head ;
          NODE  *scanPtr ;
          
          int main()
          {
              int flag ;
              int choice ;
              flag = 1 ;
              
              while (flag ==1)
              {
                   choice = DisplayMenu() ;
                   switch(choice)
                   {  case 1 :
                      { 
                           CreateList() ;
                           break ;
                      }
                      case 2:
                      {
                           AddNode();
                           break ;
                      }
                      case 3:
                      {
                           DeleteNode();
                           break ;
                      }
                      case 4:
                      {
                          DisplayList() ;
                          break ;
                      }
                      case 5:
                      {
                           DeleteList() ; /* travese through the list and remove each element by element */
                           break ;
                      }
                      case 6:
                      {
                          SearchList();
                          break ;
                      }
                      case 7:
                      {
                          flag = 0 ;
                          break ;
                      }
                      default:
                      {
                         break ;
                      }
                   }
              }
          }
          
    ````
    
    
## 2. Implementation of Double  Linked List 

1. Read the problem 2 for the implementation of Double Link List first.
   1. Copy paste the outline code and compile it 
   1. You should get a linker error for the functions
   1. CreateList()
      1. AddNode()
      1. DeleteNode()
      1. DisplayListForward()
      1. DisplayListReverse()
      1. DeleteList()
      1. SearchList()
   1. Do empty implememtation of these functions ie just write outline of function with no code and compile again
   1. All Linker errors should have gone away now
   1. Run the program and see menu is working or not. When you select 7 the program has to quit
   1. **Upload the file to Github now- This will create a version no 1 for this file**
   1. Implement the function **CreateList()** now
   1. Compile it and run - No output at this stage
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 2 for this file**
   1. Implement the function **DisplayListForward()**
   1. Compile it and run - You should be able to see the list now
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 3 for this file**
   1. Implement the function **DisplayListReverse()**
   1. Compile it and run - You should be able to see the list now
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 4 for this file**
   1. Implement the function **SearchList()**
   1. Compile it and run - The search function should prompt for the data to be searched and you search for it in the list and say 
       it is found or not.
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 5 for this file**
   1. Implement the function **AddNode()**
   1. Compile it and run - You should be able to add new node and display the list correctly
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 6 for this file**
   1. Implement the function **DeleteNode()**
   1. Compile it and run - You should be able to delete a node and display the list correctly
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 7 for this file**
   1. Implement the function **DeleteList()**
   1. Compile it and run - You should be able to delete the list  and now if you try to display it should say list is empty
   1. **Upload the file  to github again same name - Do not delete the first one. This will create version no 8 for this file**
   
   ** Please note that I will check for eight version and see the difference between them to see whether you had written each function in  step by step approach or not. IF not I will reject it **
   
1. Operation on Double  Linked list
   1. Create Double Linked list
   1. Display the content of the linked list
   1. Delete an element in the linked list
   1. Add an element into the linked list
   1. Search for an element in the linked list
   1. Use a menu driven approach for creating,  displaying, adding, deleting and searching
   1. Use the following structure for writing the program in this assignment the work o
       you need to do is  implement the functions or write the following function.
   
       
      1. CreateList()
      1. AddNode()
      1. DeleteNode()
      1. DisplayListForward()
      1. DisplayListReverse()
      1. DeleteList()
      1. SearchList()
      ````
         typedef struct node 
          {
             int data ;
             struct node *left ;
             struct node *right ;
          } NODE ;
          
          /* Declare head of the list as a Global Variable */
          NODE  *head ;
          NODE  *scanPtr ;
          int main()
          {
              int flag ;
              int choice ;
              
              flag = 1 ;
              
              while (flag ==1)
              {
                   choice = DisplayMenu() ;
                   switch(choice)
                   {  case 1 :
                      { 
                           CreateList() ;
                           break ;
                      }
                      case 2:
                      {
                           AddNode();
                           break ;
                      }
                      case 3:
                      {
                           DeleteNode();
                           break ;
                      }
                      case 4:
                      {
                          DisplayForward() ;
                          break ;
                      }
                      case 5:
                      {
                          DisplayForward() ;
                          break ;
                      }
                      case 6:
                      {
                           DeleteList() ; /* travese through the list and remove each element by element */
                           break ;
                      }
                      case 7:
                      {
                          SearchList();
                          break ;
                      }
                      default:
                      {
                         break ;
                      }
                   }
              }
          }
          
    ````
