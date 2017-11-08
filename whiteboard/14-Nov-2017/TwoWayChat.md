# Two way Chat program
We all use Whatsapp and similar chat programs daily. Interesting fact is these chat programs are build using the same sockets we had discussed so far. Only difference the socket API are slightly different on Windows, Android etc. However the format by which they exchange data between machine is same (This is called as TCP/IP packet).

In this project we are making a small chat program with which you can chat with your friend on another machine. The basis of this the text messages we exchange are nothing by bytes. These bytes can be exchanged between two machines using sockets.

## How to go about
As we discussed all socket based applications need a client and server to communicate. Here are also we will use the same approach.

However this model is different from the client server model we had discussed previously, we had client running on one machine and server running on other and they communicate each other through sockets.

For a simple chat like program to work we need client and server programs on both sides. That is User A should have the client and server  simillarly User B too need both client server.

This is becuase we  user A send a message there has to a be server to receive it on the other side which is B and display the message. Simillary when User B send a message there has to be server always waiting to recive the message from other side.

AS soon as chat application is started by user A it creates  server and wait for incomming connection from otherside. The moment server of A get connect request from client on , A will start its and client connects to the server on B. This is the part you need to think and do it carefully. 


So to make thing easier what you should do is start by implementing a single side chat program User A just send message and user B can recieve it and display it using printf() Now modify this program so that User B can send message to A and A can display it using printf()
![GitHub Logo](/images/chat.jpg)

