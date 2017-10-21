# Low Level programming of Raspberry PI to access GPIO


![GPIO](GPIO_RPI.jpg?raw=true "Title")

## GPIO
General Purpose Input Outout pins are know as GPIO pins in Raspberry PI. These pins are one the most important interfaces
to sensors, acutators and other devices that needs to be controlled from the embedded computer.

In this section we see how to access (Read and Write from the GPIO ports of Raspberry Pi). IF we want to control an external
device from Raspberry Pi what we do is we connect the device to one of the GPIO pins. Now by writing ZERO or ONE to the corresponding
pin we can control the device. For example if we want to control the behaviour of an LED we connect the LED to a GPIO PIN and
control its, logic state.That is we can write a zero or one to GPIO pin like the way write to a memory location

Simillarly if we want to read data from a sensor we connect the sensor to one of the GPIO pins, and read the logic state of the pins into the variable of C program using some functions. 

This section explains how to access the GPIO of Raspberry PI

## How to access GPIO
Computers does not understand what is GPIO or ports or interfaces. All it knows is memory location. If you look at every operation in operation we see two kinds of operation, 

1. Data processing operations (Arithmetic operation, Logical operation) 
1. Reading from memory  and Storing back to memory. 

There are no specific instructions to access GPIO.

The reason for this is, Computers do not understand GPIO, or there is no need for them  to understand GPIO, because, every GPIO pin or every external interface is mapped to a specific memory location. That means every GPIO pin has memory location and that memory location will have an address. 

The memory location and Physical GPIO pins are connected together through digitial circuits (hard wired)

So by accessing the corresponding memory location we can control logical state of a GPIO pin simillarly by reading the value of the corresponding memory we can read the logical value of a GPIO PIN.There by we can control the operation of a device connected to the GPIO PIN.

![GPIO](gpio-device.jpg?raw=true "Title")

The above diagram show the GPIO pins their numbers and locations on Raspberry PI and how external devices are connected to them.

## Logic Probe.
Is a simple devie that is used to know the logic state of a PIN. If the PIN is high the small LED on the probe will be ON and OFF otherwise. A Simple logic probe is something you can make yourself with a LED and a Resistor. Using a Logic probe we can see the logic state of a GPIO PIN any time.

![GPIO](logic-probe.jpg?raw=true "Title")

## To start with let us try how to control the logic state of a LED.
The Voltage levels on GPIO pin is sufficient enough to switch ON an LED and make it glow. Now let us see to how to set the logic state of a GPIO PIN to ONE there by making the LED connected to it Glow

First let is connect LED to the GPIO PIN 7 that is the anode of LED is connected to GPIO PIN 7 and cathode to the GND pin of Raspberry Pi.

When the logic state of GPIO PIN 7 goes to HIGH, the LED will glow and when it goes to ZERO it stop GLOWING.

To do this we need to know the Address of the memory location that is mapped to GPIO PIN 7. Let us find the address of GPIO PINs

To do this we need to understand the Specification of Raspberry Pi like which CPU it uses etc. The CPU chip used in RAspberry PI 3 is 
SoC: Broadcom BCM2837 (The chip CPU, GPU, DSP, SDRAM)

As per the User manual of this Chip BCM2837 published by Broadcom, it says that the based address of all peripheral start at 0x3F000000

####GPIO is also a peripheral.####
This means

1. Since we know the starting address of the memory location of the first GPIO PIN we can write the required data to set the pin 1 to ZERO or ONE
1. By adding a required offset to the starting address (address of GPIO PIN 1) we can get the address of all other GPIO pins. There by can control the logic state of the pins.

Now lets us see how to set the logic state of each GPIO PIN

The data sheet for BCM2837 says that one 32 bit memory can hold information of 10 GPIO pins, That means there will be three bit per GPIO in the memory.

To find the 32 bit memory location where the information of the first GPIO PIN is stored we do the following

````
*gpio.addr + 1 ;
or for finding the g-th GPIO pin we say
*gpio.addr + 1 ;
`````
But this  32 bit memory will have the logic state of 10 pins. Next step is to extract the three bits of within this 32 bit memory
location this is done as follows

Since there are 32 bit location is allocated to 10 GPIO we do

````
*gpio.addr + ((g))/10

````

or in short *gpio.addr + ((g))/10 is the "register" address that contains the three  bits of the GPIO pin "g". These three bit area called as GPFSEL 

We need to set value of three three bits 

````
The location of these three bits inside the GPFSEL register is given by ((g)%10)*3 (three times the remainder, remember the modulo % operator).

````
The following table show the bits in 32 bit memory and the corresponding to each GPIO pins

|BIT | Description | TYPE
-----|-------------|-----
|31-30| This 3 bits belong to GPIO PIN 9 | Read and write|
|29-27| This 3 bits belong to GPIO PIN 9 | Read and write |
|26-24| This 3 bits belong to GPIO PIN 8 | Read and write |
|23-21| This 3 bits belong to GPIO PIN 7 | Read and write |
|20-18| This 3 bits belong to GPIO PIN 6 | Read and write |
|17-15| This 3 bits belong to GPIO PIN 5 | Read and write |
|14-12| This 3 bits belong to GPIO PIN 4 | Read and write |
|11-9|  This 3 bits belong to GPIO PIN 3 | Read and write |
|8-6| This 3 bits belong to GPIO PIN 2 | Read and write |
|5-3| This 3 bits belong to GPIO PIN 1 | Read and write |
|2-0| This 3 bits belong to GPIO PIN 0 | Read and write |
