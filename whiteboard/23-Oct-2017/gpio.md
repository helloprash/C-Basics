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

The reason for this is, Computers do not understand GPIO, or they do not have to understand GPIO, because, every GPIO pin, every interface is mapped to a specific memory location. That means every GPIO pin has memory location and that memory location will have an address. So
by accessing the corresponding memory location we can control logical state of a GPIO pin simillarly by reading the value of the corresponding memory we can read the logical value of a GPIO PIN.
