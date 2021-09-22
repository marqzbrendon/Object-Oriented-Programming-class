/***************************************************************
 * File: ta04.cpp
 * Author: Brendon Marques 
 * Purpose: Contains the main function to test the Rational class.
 ***************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "rational.h"

int main()
{
   // Declare your Rational object here
   Rational Numbers;

   int multTop;
   int multBot;

   // Call your prompt function here
   Numbers.prompt();

   cout << "Multiply by top: ";
   cin >> multTop;
   cout << "Multiply by Bottom: ";
   cin >> multBot;
   
   // Call your display functions here
   Numbers.multiplyBy(multTop, multBot);
   Numbers.reduce();
   Numbers.display();
   Numbers.displayDecimal();

   return 0;
}
