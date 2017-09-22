# Assignment to be submitted on 25-Sep-2017 Monday

## 1. Implementation of Single Linked List
1. Operation of Linked list
   1. Create Single Linked list
   1. Display the content of the linked list
   1. Delete an element in the linked list
   1. Add an element into the linked list
   1. Search for an element in the linked list
   1. Use a menu driven approach for creating,  displaying, adding, deleting and searching
   1. Use the following structure for creating the node and you are expected to implement the functions
      1. CreateList()
      1. AddNode()
      1. DeleteNode()
      1. DisplayList()
      1. DeleteList()
      ````
         typedef struct node 
          {
             int data ;
             struct node *next ;
          } NODE ;
          
          /* Declare head of the list as a Globals Variable */
          NODE  *head ;
          
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
                      }
                      case 2:
                      {
                           AddNode();
                      }
                      case 3:
                      {
                           DeleteNode();
                      }
                      case 4:
                      {
                          DisplayList() ;
                      }
                      case 5:
                      {
                           DeleteList() ; /* travese through the list and remove each element by element */
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
