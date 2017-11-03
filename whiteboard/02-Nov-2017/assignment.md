# Project due to 7-Nov-2017

Based on the three discussion we had in class on
1. Blinking an LED
1. Creating a process using fork()
1. Two way communication between client server using sockets.

Implement a program to switch ON and OFF a particular LED on the RPi, you connect seven LED to 7 GPIO PINS in RPi and
run the server program in RPi. On a second RPi, runs the client. Client runs in a infinite loop like a command prompt
taking input from users. The user provides a number between 1 and 7 including 1 ad 7. The corresponding LED will glow.
The way to give the number is 
````
$ *ON* <led number> --> this will switch ON the LED once this command return, it will tell us the status of LED after executing the command
in case the LED is already ON, it will say : **LED <number> is already in ON state so no action taken**

$ *OFF* <led number> --> this will switch OFF the LED.
once this command return, it will tell us the status of LED after executing the command
in case the LED is already OFF, it will say : **LED <number> is already in OFF state so no action taken**

$ *STATUS* <led number> --> will return the status of the given LED is ON or OFF
```

Remember it is the server which is talking to GPIO to set and reset its logical state. The same program need to keep track of the status of 
each LED in a array. 

HINT: In the server program the change you need to make is replace the printf() with the corresponding API to switch ON and OFF the LED.

## What is expected
1. The 7 LEDs can be controlled from client
1 No expections, it has to work smoothly with out crashing after a set of muliple ON OFF Sequence. It should return the status correctly.
