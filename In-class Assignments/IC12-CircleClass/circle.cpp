// This program demonstrates a simple class.
#include <iostream>
using namespace std;

#define PI 3.14
// Circle class declaration.
class Circle
{
   private:
      double radius;

   public:
      void setRadius(double);
      double getRadius() const;
      double getDiameter() const;
      double getArea() const;
};


// setRadius assigns a value to the radius member.
 void Circle::setRadius(double radius2)
   {
      radius = radius2;
   }
   

// getRadius assigns a value to the radius member.

double Circle::getRadius() const{ 
          return radius; 
       
       }


// getDiameter 

double Circle::getDiameter() const{ 
          return radius*2; 
       
       }

// getArea


double Circle::getArea() const{ 
          return PI*radius*radius; 
       
       }





int main()
{
   Circle c1;     // Define an instance of the Circle class
   double rad, rad1;  // Local variable for radius


   // Get the radius from the user.
   cout << "This program will calculate the area of a circle.\n";
   cout << "What is the radius? ";
   cin >> rad;
   
   //input validation for radius amt
   if(rad < 0)
   {
      
   cout << "Radius must be a positive value";
   
    cout << "This program will calculate the area of a circle.\n";
   cout << "What is the radius? ";
   cin >> rad;
   }
   
   cout << "What is the radius of the object pointed by c2? ";
   cin >> rad1;

  
   
   // Store the radius of the circle in the c1 object.
   c1.setRadius(rad);
 

   // Display the circle's data.
   cout << "\nHere is the circle's data:\n";
   cout << "Radius: " << c1.getRadius() << endl;
   cout << "Diameter: " << c1.getDiameter() << endl;
   cout << "Area: " << c1.getArea() << endl;

    Circle *c2 = new Circle;
    
    
     //input validation for radius1 amt
   if(rad1 < 0)
   {
      
   cout << "Radius must be a positive value";
   
   return -1;
   }

   // Store the radius of the circle in the c2 object.
   c2->setRadius(rad1);
   

   // Display the circle's data.
   cout << "\nHere is the circle's data through the pointer:\n";
   cout << "Radius: " << c2->getRadius() << endl;
   cout << "Diameter: " << c2->getDiameter() << endl;
   cout << "Area: " << c2->getArea() << endl;

   return 0;
}
