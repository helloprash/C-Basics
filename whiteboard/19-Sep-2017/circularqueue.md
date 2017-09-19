# Circular Queue 
## Implement a Circular queue in C by 
## Consider the following conditions
* Addition and deletion happening when queue is empty
* Addition and deletion happening when queue is FULL
* Addition and deletion happening when queue is not FULL
* Addition and deletion happening when tail is pointing to the MAX of array

'''
   /* global variables */
   int queue[100]; 
   int head = 0 ;
   int tail = 0;
   
   int AddQueue(int element)
   {
   }
   
   int DeleteQueue()
   {
   }
   
   main()
   {
       int flag ;
       int choice ; /*menu choice */
       int data ;
       flag = 1 ;
      
       while(flag)
       {
           printf("1.Add \n");
           printf("2.Delete \n");
           printf("3.Print Queue \n");
           printf("4. Exit\n");
           scanf("%d", &choice);
           switch(choice)
           {
              case 1 : {
                          printf("Enter the value to added to queue: ");
                          scanf("%d", &data);
                          AddQueue();
                          break ;
                       }
              case 2 : {
                          DeleteQueue();
                          break;
                        }
             case 3 : {
                         PrintQueue()
                         break ;
                       }
            case 4:    {
                          flag = 1 ;
                       }
            default:   {
                          break ;
                       }
           }
       }
   }
   '''
