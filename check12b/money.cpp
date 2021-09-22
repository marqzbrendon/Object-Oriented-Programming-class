/***********************
 * File: money.cpp
 ***********************/

#include <iostream>
#include <iomanip>
using namespace std;

#include "money.h"

/*****************************************************************
 * Function: prompt
 * Purpose: Asks the user for values for dollars and cents
 *   and stores them.
 ****************************************************************/
void Money :: prompt()
{
   int dollars;
   int cents;

   cout << "Dollars: ";
   cin >> dollars;

   cout << "Cents: ";
   cin >> cents;

   setDollars(dollars);
   setCents(cents);
}

/*****************************************************************
 * Function: display
 * Purpose: Displays the value of the money object.
 ****************************************************************/
void Money :: display() const 
{
   cout << "$" << getDollars() << ".";
   cout << setfill('0') << setw(2) << getCents();
}

/*****************************************************************
 * Function: handleOverflow
 * Purpose: Checks if cents is greater than 100, and if so, rolls
 *   that amount over to dollars.
 ****************************************************************/
void Money :: handleOverflow()  
{
   if (cents > 100)
   {
      dollars += cents / 100;
      cents = cents % 100;
   }
   else if (cents == 100)
   {
      dollars += 1;
      cents = 0;
   }
}


// Put the bodies of your member functions here!
Money Money :: operator + (const Money &rhs)
{
   Money temp;
   temp.cents = (cents + rhs.cents);
   temp.dollars = (dollars + rhs.dollars);
   temp.handleOverflow();
   return temp;
}

Money Money :: operator += (const Money &rhs)
{
   dollars += rhs.dollars;
   cents += rhs.cents;
   handleOverflow();
   return *this;
}

Money Money :: operator ++ ()
{
   cents += 1;
   handleOverflow();
   return *this;
}