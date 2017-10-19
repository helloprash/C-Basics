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
Computers does not understand what is GPIO or ports or interfaces. All it knows is memory location. If you look at every operation in operation we see two kinds of operation, Data processing operations (Arithmetic operation, Logical operation) and Reading from memory 
Storing back to memory. There are no specific instructions to access GPIO. 

The reason for this is, Computers do not understand GPIO, or there is no need for them  to understand GPIO, because, every GPIO pin or every external interface is mapped to a specific memory location. That means every GPIO pin has memory location and that memory location will have an address. 

So by accessing the corresponding memory location we can control logical state of a GPIO pin simillarly by reading the value of the corresponding memory we can read the logical value of a GPIO PIN.There by we can control the operation of a device connected to the GPIO PIN.

![GPIO](gpio-device.jpg?raw=true "Title")

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
GPIO is also a peripheral. So by adding an offset to this starting address we can find the address of the memory to which GPIO pins
are mapped to. The same document says the starting address of memory to which GPIO pins are mapped starts at the offset 0x200000. That is the first GPIO PIN will have address 0x3F000000 + 0x200000 = 0x3F200000 
