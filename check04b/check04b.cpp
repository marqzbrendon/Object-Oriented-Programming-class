/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"
#include <iostream>
using namespace std;

int main()
{
   // prompt for month, day, year   
   cout << "Month: ";
   int month;
	cin >> month;

	cout << "Day: ";
	int day;
	cin >> day;

	cout << "Year: ";
	int year;
	cin >> year;
   cout << endl;

   // create a Date object
   Date Date;

   // set its values
   Date.set(day, month, year);

   // call each display function
   Date.displayAmerican();

   Date.displayEuropean();

   Date.displayISO();

   return 0;
}
