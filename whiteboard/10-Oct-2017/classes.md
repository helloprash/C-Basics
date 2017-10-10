# C++ Classes

When you define a class, you define a blueprint for a data type. This doesn't actually define any data, but it does define what the class name means, that is, what an object of the class will consist of and what operations can be performed on such an object.

A class definition starts with the keyword class followed by the class name; and the class body, enclosed by a pair of curly braces. A class definition must be followed either by a semicolon or a list of declarations. For example, we defined the Box data type using the keyword class as follows −
````

#include <iostream>

using namespace std;

class Box {
   public:
      double length;   // Length of a box
      double breadth;  // Breadth of a box
      double height;   // Height of a box
};

int main() {
   Box Box1;        // Declare Box1 of type Box
   Box Box2;        // Declare Box2 of type Box
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.height = 5.0; 
   Box1.length = 6.0; 
   Box1.breadth = 7.0;

   // box 2 specification
   Box2.height = 10.0;
   Box2.length = 12.0;
   Box2.breadth = 13.0;
   
   // volume of box 1
   volume = Box1.height * Box1.length * Box1.breadth;
   cout << "Volume of Box1 : " << volume <<endl;

   // volume of box 2
   volume = Box2.height * Box2.length * Box2.breadth;
   cout << "Volume of Box2 : " << volume <<endl;
   return 0;
}
````

## Members of a Class
The various variable we had declared in a class are called members. We do not call them as fields like C struct. This is because members can be variables (holding data) or they can function/routines which does some operation on the memebers/data.
### Public and Private members.
The members in class can be declared as *private*  or *public*. When a  member function of member variable/data is declared as *privite* then it accesseable only the other members of the class. From outside the class, they are not accessbale or visible. Where as when a member is decleared a *public* they can be accessed by everyone. 
*public* members of a class are the prime interface to the classes, private members are hidden for external world. To give you a good analogy, in car the *public* interfaces are the steering wheel, gear, clutch, break  horn etc. No other part of the vehicle is exposed to the user, all the other controls are needed for mechanic is hidden from the driver. Exactly like that a Class has *private* members and *public* members

### Experiment
In the above example try to change the members as privite and see what happens
