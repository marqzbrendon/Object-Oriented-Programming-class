/***************************************************************
 * File: rational.cpp
 * Author: Brendon Marques
 * Purpose: Contains the method implementations for the Rational class.
 ***************************************************************/

#include "rational.h"
#include <iostream>
#include <iomanip>
using namespace std;

// put your method bodies here
void Rational::prompt()
{
	cout << "Top: ";
	cin >> top;
	cout << "Bottom: ";
	cin >> bottom;
}

void Rational::display()
{
	if (top > bottom)
	{
		cout << top / bottom
		     << " "
		     << top % bottom
		     << "/"
		     << bottom
		     << endl;
	}

	else
		cout << top 
			  << "/" 
			  << bottom
		  	  << endl;
}

void Rational::displayDecimal()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << float (top) / float (bottom)
	     << endl;
}

void Rational::multiplyBy(int &multTop, int &multBot)
{
	top *= multTop;
	bottom *= multBot;
}

void Rational::reduce()
{
   int smallest = (top < bottom) ? top : bottom;

	for (int i = smallest; i > 1; i--)
	{
   	while (top % i == 0 &&
		  	    bottom % i == 0)
		{
			top /= i;
			bottom /= i;
		}
	}
}


