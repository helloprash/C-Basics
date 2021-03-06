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

#### GPIO is also a peripheral.
This means

1. Since we know the starting address of the memory location of the first GPIO PIN we can write the required data to set the pin 1 to ZERO or ONE
1. By adding a required offset to the starting address (address of GPIO PIN 1) we can get the address of all other GPIO pins. There by can control the function and  logic state of the pins.

GPIO mean **G**eneral **P**urpose **I**nput **O**utput pin. This means before using a GPIO we need configure it as a output pin or as a input.  In addition for being and INPUT or OUTPUT pin GPIO can also work as pin which support Protocols for accessing peripheral devices

Before we start using a GPIO PIN we set it whether it is going to be INPUT PIN or an OUTPUT PIN. A GPIO PIN can be configured to do many thing like OUTPUT PIN, INPUT PIN or work a pin which supports Protocol for accessing peripheral.  For there is small region in the memory called *GPSEL Register* (same RAM itself) The value stored in this register will decide the function of GPIO PIN whether it is INPUT or OUTPUT pin.

In short the functionality of a GPIO is controlled by a memory called  GPSEL Register 

Now lets us see how to set the **functionality**  of each GPIO PIN using the GPSEL Register in memory

The data sheet for BCM2837 says that GPSEL registers are 32 bit memory and it can control the behaviour of 10 pins. 
That means there will be three bit per GPIO in the memory. (LEt us ignore that last 2 two bits for now)

To find the 32 bit memory location where the information of the first (1-st)  GPIO PIN is stored we do the following

````
//gpio.addr can be found out using function call.

*gpio.addr + 1 ;
or for finding the g-th GPIO pin we say
*gpio.addr + g ;
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
The location of these three bits inside the GPFSEL register is given by ((g)%10)*3 (three times the remainder, 
remember the modulo % operator).

For 0-st pin it will (0 % 10) * 3  = 0 * 3 = 0 - This means GPIO 0 is controlled by 0,1,2 bit of the register  
For 1-st pin it will (1 % 10) * 3  = 1 * 3 = 3 - This means GPIO 0 is controlled by 3,4,5 bit of the register  
For 2-st pin it will (2 % 10) * 3  = 2 * 3 = 6 - This means GPIO 0 is controlled by 6,7,8 bit of the register  
For 3-st pin it will (3 % 10) * 3 =  3 * 3 = 9 - This means GPIO 0 is controlled by 9,10,11 bit of the register  
.................
............................
````
The following table show the bits in 32 bit memory and the corresponding to each GPIO pins

|BIT | Description | TYPE
-----|-------------|-----
|31-30| Reserved for other purpose | Read ONLY|
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

The User Manual says how to set the these three **BITS** of this register belonging to each PIN to make it work as INPUT OR OUTPUT OR PROTOCOL PIN. Since there are three bits, we can have eight combinations and hence there can be eight modes in which each GPIO can be configured. That is apart from INPUT and OUPUT modes, there will be six other combination. 

When set three bit of a this register to 000 the pin will be configured as INPUT and 001 it will be configured as OUTPUT and the other six combination 010 to 111 we call them as alternate functions

Let us see how to set the GPSEL Register PINs for PIN 0 to 10
````
The GPSEL address containing the function select bits for gpio 0  is *gpio.addr + 0/10= *gpio.addr + 0
The GPSEL address containing the function select bits for gpio 1  is *gpio.addr + 1/10= *gpio.addr + 0
.....................................................................................................
......................................................................................................
The GPSEL address containing the function select bits for gpio 10  is *gpio.addr + 10/10=*gpio.addr + 1
````
So this mean bit corresponding to GPIO pins 0 to 9 are stored in the same register. There is no way to address 
bits and change them individually. So, if we want to modify any bit we need to access the whole register with
out impacting other bits. So we use a concept called bit-mask for this.

The way we do it is as follows:


````
1. Let us say we want to set the GPIO PIN 2 to INPUT mode. 
2. Find the bit which control GPIO 2 PIN. Those are  8,7,6  bit as per the above table. 
3. We will set these three  bits of the GPSEL register to 000 without impacting other bit of the GPSEL Register
4. For this we create 32 bit variable which we will call as bit mask  and set all it bits to 1 
  that is 0xFFFF FFFF
    in C we say: 
             int bitMask;
             bitMask = 0xFFFFFFFF;
             
5. Let say if we do a bit wise AND operation of  this bit mask with GPSEL REGISTER and assign to 
   to GPSEL what happenes ?
          in C we say
          GPSEL = GPSEL & bitMask ;
          
6. Result is : All the bit of GPSEL will remain unchanged.

7. Now what we will do set the 8,7 and 6 bits of this mask to 0s rest of the bits will remain unchanged.
   So our new bit mask will have value 11111111111111111111111000111111 or ‭0xFFFFFE3F‬
   That is bitMask = 0xFFFFFE3F ;
   
8. Now do a bit wise AND operation of this bit mask with GPSEL REGISTER and assign it to back to GPSEL. 
   What will happen now ?
        in C we say:
        GPSEL = GPSEL & bitMask ;
        
9. Result is : Bits 8,7,6 has set to ZERO where as all the remaining bits remains unchanged in GPSEL.

````

So for all the GPIO pins we first find the address of GPSEL register where the information is stored, then find the bits 
corresponding to the pin of our interest. Create bit mask to set the corresponding bit and do a Bit wise AND of the mask 
with GPSEL and assign  the result back to GPSEL itself.

### Let us write a small C function to configure a given GPIO as OUTPUT

````
int *gpio.addr  // This is set intially.

void OUT_GPIO(in g)
{
    int bitMask;
    int *GPSEL ;
    // Depending on which pin to set as ouput we need to set the corresponding bits to 001
    // ((g)%10)*3 will tell us the first bit that need to modified. Then the next two bits also need to be modified
    bitMask = 0x1 ;   //0000 0000 0000 0000 0000 0000 0000 0001
    bitMask = bitMask << ((g)%10)*3 ; 
    
    // eg for pin 1  the bits 5,4,3 will be set to 001    0000 0000 0000 0000 0000 0000 0000 1000
    //    for pin 2  the bits 8,7,6 will be set to 001    0000 0000 0000 0000 0000 0000 0100 0000
    //    for pin 3  the bits 11,10,9 will be set to 001  0000 0000 0000 0000 0000 0010 0000 0000    
    // NOW do BIT WISE OR  with the value of GPSEL REGISTER and assign the results back toGPSEL itself
    // WHEN we OR GPSEL WITH bitMask orginal values of GPSEL will remain same where ever bitMask as zero w
    // and in places where is the ONE the GPSEL bit will be changed to ONE.
    
    // xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx  OR
    // 0000 0000 0000 0000 0000 0010 0000 0000
    ---------------------------------------------
    // xxxx xxxx xxxx xxxx xxxx 001x xxxx xxxx In case bit 10 and 11 is  0 they will remain same 
    // otherwise if they 1 we will have a problem.
    // Hence We need to call IN_GPIO(g) before calling OUT_GPIO() always.
    //*gpio.addr  has the base address
    // Add base address to pin/10 to get the GPSEL register address
    GPSEL = *gpio.addr + g/10 ; /* For pins 0 to 9 this will be same */
    GPSEL = GPSEL | bitMask ;
}
````

### Let us write a small C function to configure a given GPIO as INPUT

````
void IN_GPIO(in g)
{
    int bitMask;
    int *GPSEL ;
    // Depending on which pin to set as input  we need to set the corresponding bits to 000
    // ((g)%10)*3 will tell us the first bit that need to modified. Then the next two bits also need to be modified
    bitMask = 0x7 ;   //0000 0000 0000 0000 0000 0000 0000 0111
    bitMask = bitMask << ((g)%10)*3 ; 
    
    // eg for pin 1  the bits 5,4,3 will be set to 000    0000 0000 0000 0000 0000 0000 0011 1000
    //    for pin 2  the bits 8,7,6 will be set to 000    0000 0000 0000 0000 0000 0001 1100 0000
    //    for pin 3  the bits 11,10,9 will be set to 000  0000 0000 0000 0000 0000 1110 0000 0000    

    // NOW WE WIll do bit wise compliment of all bits in the bitMask
    bitMask = ~bitMask
    // eg for pin 1  the bits 5,4,3 will be set to 000    1111 1111 1111 1111 1111 1111 1100 0111
    //    for pin 2  the bits 8,7,6 will be set to 000    1111 1111 1111 1111 1111 1110 0011 1111
    //    for pin 3  the bits 11,10,9 will be set to 000  1111 1111 1111 1111 1111 0001 1111 1111
    
    
    // NOW do BIT WISE AND with the value of GPSEL REGISTER and assign the results back to GPSEL itself
    // WHEN we do AND  GPSEL WITH bitMask orginal values of GPSEL will remain same where ever bitMask has ones w
    // and in places where is the ZERO the GPSEL bit will be changed to ZERO
    
    // xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx  AND
    // 1111 1111 1111 1111 1111 0001 1111 1111
    ---------------------------------------------
       xxxx xxxx xxxx xxxx xxxx 000x xxxx xxxx
    //*gpio.addr  has the base address 
    GPSEL = *gpio.addr + g/10 ;  // Add base address to pin/10 to get the GPSEL register address
    //GPSEL is pointing to the memory which has the configuraiton information of the pin 
    GPSEL = GPSEL & bitMask ;
}


````

Here is the main program

````
#include <stdio.h>
 
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
 
#include <unistd.h>
 
#define BCM2708_PERI_BASE       0x20000000
#define GPIO_BASE               (BCM2708_PERI_BASE + 0x200000)	// GPIO controller 
 
#define BLOCK_SIZE 		(4*1024)
 
// IO Acces
struct bcm2835_peripheral {
    unsigned long addr_p;
    int mem_fd;
    void *map;
    volatile unsigned int *addr;
};
 
 
struct bcm2835_peripheral gpio = {GPIO_BASE};
 
// Exposes the physical address defined in the passed structure using mmap on /dev/mem
int map_peripheral(struct bcm2835_peripheral *p)
{
   // Open /dev/mem
   if ((p->mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
      printf("Failed to open /dev/mem, try checking permissions.\n");
      return -1;
   }
 
   p->map = mmap(
      NULL,
      BLOCK_SIZE,
      PROT_READ|PROT_WRITE,
      MAP_SHARED,
      p->mem_fd,      // File descriptor to physical memory virtual file '/dev/mem'
      p->addr_p       // Address in physical map that we want this memory block to expose
   );
 
   if (p->map == MAP_FAILED) {
        perror("mmap");
        return -1;
   }
 
   p->addr = (volatile unsigned int *)p->map;
 
   return 0;
}

int main(
{
  if(map_peripheral(&gpio) == -1) 
  {
    printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
    return -1;
  }
 
  // Define pin 7 as output
  INP_GPIO(4);
  OUT_GPIO(4);
 
  while(1)
  {
    // Toggle pin 7 (blink a led!)
    GPIO_SET = 1 << 4;
    sleep(1);
 
    GPIO_CLR = 1 << 4;
    sleep(1);
  }
 
  return 0; 
}
````
This way we can set the GPSEL  and configure the functionality of a GPIO PIN
***
## How to set Logic levels of GPIO.

Just like we had configured the functionality of GPIO as INPUT or OUTPUT, we can set the logic state of PIN just like we set flip-flop
As each GPIO is mapped to a memory just by setting the bit in corresponding location we can change the logic state of each PIN

We know the starting address of memory location where GPIO are mapped to this is gpio.addr 
gpio.addr  +  0 mean the GPSEL register for GPIO 0 to 9   

The user manual says at the address, gpio.addr + 7 (that is gpio.addr + 7x 8 bytes away) there is a  32 bit memory location
which can be used to set the values of the 26 GPIP pins on Rpi each of these 26 pins are mapped to bit in the above memory location.
Hence by setting the bits of this memory location we can set the logic values of the pins

To set GPIO PIN 5 we say  
   *(gpio.addr+7) = 1 << 5

A  C function will be like this

````
void SetGPIO(int gpio)
{
   *(gpio.addr+7) = 1 << gpio ;
}
````

The Reset the GPIO we need another address. The same address once Set will set the logic state of GPIO for every
To reset we have differnt location which is base address + 10 location (10 X 32 bytes)

````
void ClearGPIO(int gpio)
{
  *(gpio.addr + 10)  = 1 << gpio ;
}
````



