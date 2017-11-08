# Implementation of File Transfer Program

In this project you are expected to develop a client server program   using sockets for transfering files between two machines

TCP/IP sockets are the very basic level of interface exposed by Operating System for communicating with another machine on network
Through sockets we can send any kind of data. 

## How to go about with Phase-1

Let us says we two machine A and B. (Both are raspberry pi). We have a server runnign on the  machine A and client running on machine B

1. Assume the client has a list which has all the files in the server. 
2. User can type the "list" Command at the client side  and can see this list
3. Next user types get <filename> Eg: get letter.txt 
4. Client send the file name to server through socket and server receives it
5. Server opens this file in readonly mode, read byte by byte from the file and send it client through the socket.
6. At the same time client opens a new file in Write Mode
7. As the server sends each byte,  client receives the bytes and write it into file which is opened
8. This process goes on till client get EOF character ( or something equivalent). That time the client closes the files and closes the socket connection.
9. Once the server get EOF (That means file reading is over) it will exit the child process.
10. In the same way client should be able to do a send a file to server 
11. User types put <filename>
12. Client will send the file name to server, server opens a new file in write only mode with the same name
13. Client will open the file in read only mode and read bytes and send them to server.
14. Server recieives the bytes and write it into a the file. Till it get EOF or something equivalent
15. Server exits the child process
16. Client closes the socket connection.
 

### Test the above functions using  the following test cases
1. A normal text file is transfered from server to client. (Get)
2. A normal text file is transfered from client to server  (Put)
3. Simillary do a file transfer from Client to server and server to client of executable program
4. The executable has to work on the other machine after file transfer.

## How to go about with Phase-2
In phase -1 we assumed client has a list of files in the server.
1. In this phase we are not making this assumption. Instead when the user types the command list. The client send the list command to server and server send the list of files in the current directory to client. Client displays this list to user. When the list command is send to server, the server do something similar to ls command and get the list of files in the current directory and send the list to client. You can refer to this link https://stackoverflow.com/questions/4204666/how-to-list-files-in-a-directory-in-a-c-program to understand how to get the list of files in the current folder

2. When the user types cd <folder name> command the prompt the server should change the current folder. Just like the above case you need to do some research and find the API for changing the directory at server side. Please not only the child has to change the directory and not the parent.
  
  
### Test the above functions using  the following test cases
1. Get the list of files in the current directory
2. Transfer a file from server to client
3. Transfer a file from server to client. When a similar file exists on the client
4. Transfer a file from client to server. When a similar file exists on the server
5. change the folder and do all the above operations.
