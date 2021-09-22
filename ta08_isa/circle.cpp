#include <iostream>
#include "circle.h"

using namespace std;

/***********************************************************
 * Function: Circle :: promptForCircle
 * 
 ***********************************************************/
void Circle :: promptForCircle()
{
   Point::promptForPoint();

   cout << "Enter radius: ";
   cin >> radius;
}

/***********************************************************
 * Function: Circle :: display
 * 
 ***********************************************************/
void Circle :: display()
{
   Point::display();

   cout << " - Radius: " << radius << endl;
}
