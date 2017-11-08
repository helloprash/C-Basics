# Two way Chat program

We all use Whatsapp and similar chat programs daily. Interesting fact is these chat programs are build using the same sockets we had discussed so far. Only difference the socket API are slightly different on Windows, Android etc. However the format by which they exchange data between machine is same (This is called as TCP/IP packet).

In this project we are making a small chat program with which you can chat with your friend on another machine. The basis of this the text messages we exchange are nothing by bytes. These bytes can be exchanged between two machines using sockets.

## How to go about
As we discussed all socket based applications need a client and server to communicate. Here are also we will use the same approach.
