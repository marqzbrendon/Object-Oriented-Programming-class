#include <iostream>
#include "circle.h"

using namespace std;

/***********************************************************
 * Function: Circle :: promptForCircle
 * 
 ***********************************************************/
void Circle :: promptForCircle()
{
   center.promptForPoint();

   cout << "Enter radius: ";
   cin >> radius;
}

/***********************************************************
 * Function: Circle :: display
 * 
 ***********************************************************/
void Circle :: display()
{
   center.display();

   cout << " - Radius: " << radius << endl;
}

void Circle :: setPoint(int x, int y)
{
   center.setX(x);
   center.setY(y);
}