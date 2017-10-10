# INHERTIENCE IN C++

Inheritance allows us to define a class in terms of another class, which makes it easier to create and maintain an application. THis helps in reusablity of classes

A very good example of inheritence is let us assume we have class called vehicle a vehicle is used for transportation, and it will have four wheels, seating capacity, modeOfOperation, weight etc. This can be written as a class as follows
````
#include <iostream>
#include <string.h>
using namespace std;

class Vehicle
{
	public:
    int noOfWheels ;
    int seatingCapcity ;
    int weight ;
    char modeOfOperation[6] ;
};

// We can derive many other classes out of this class as follows

class car : public Vehicle {

   public :
   char fuel[10];
   char manufacture[10];
   char maxSpeed ;
   
};

class bullokCart : public Vehicle
{
   public:
   int  noOfBulloks;
   char nameOfPerson[10];
   int  wheelDiameter ;
   int  maxSpeed ;
};
class Truck : public Vehicle
{
   char fuel[10];
   char manufacture[10];
   char maxLoad ;
   int length ;
   int breath ;   
};


main()
{
    class car    car1, car2 ;
    class Truck  truck1, truck2 ;
    class bullokCart cart ;
    car1.noOfWheels = 4 ;
    strcpy(car1.modeOfOperation, "Engine");
    car1.maxSpeed = 140;
    
    cart.noOfBulloks = 2 ;
    cart.noOfWheels =2 ;
    cart.wheelDiameter = 10 ;
    
    
}
````

## Rules of inheritance

1. A base class's private members are never accessible directly from a derived class, but can be accessed through calls to the public and protected members of the base class.

1. When deriving a class from a public base class, public members of the base class become public members of the derived class and protected members of the base class become protected members of the derived class.

1. Protected Inheritance − When deriving from a protected base class, public and protected members of the base class become protected members of the derived class.

1. Private Inheritance − When deriving from a private base class, public and protected members of the base class become private members of the derived class.

### Another Example of Inheritance

````
#include <iostream>
#include <string.h>
using namespace std;

class Polygon
{
    public :
	  int noofSides ;
	  float area ;
};

class Rectangle : public Polygon 
{
   public:
   int length;
   int breath ;
   float ComputeArea()
   {
   	   return length * breath ;
   }
};

class Square : public Polygon
{
	public:
	int side ;
	float ComputeArea()
	{
		return side * side ;
	}
};
class RightTriangle : public Polygon
{
	int base ;
	int height ;
	public:
	float ComputeArea()
	{
		return (base * height)/2 ;
	}
	void SetBase(int measurement)
	{
		base = measurement ;
	}
	void SetHeight(int measurment)
	{
		height = measurment; ;
	}
};

main()
{
   class RightTriangle RT1 , RT2 ;
   class Square SQ1, SQ2 ;
   class Rectangle RA1, RA2 ;
   
   RT1.noofSides = 2 ;
    
}
`````

