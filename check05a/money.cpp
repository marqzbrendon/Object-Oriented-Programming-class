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
 * Function: getDollars
 * Purpose: Get the dollars to be displayed.
 ****************************************************************/
int Money :: getDollars() const
{
   return dollars;
}

/*****************************************************************
 * Function: getCents
 * Purpose: Get the cents to be displayed.
 ****************************************************************/
int Money :: getCents() const
{
   return cents;  
}

/*****************************************************************
 * Function: setDollars
 * Purpose: define the value of dollars.
 ****************************************************************/
void Money :: setDollars(int dol)
{  
   if (dol < 0)
   {
      dollars = dol * -1;
   }

   else

      dollars = dol;
}

/*****************************************************************
 * Function: setCents
 * Purpose: define the value of cents.
 ****************************************************************/
void Money :: setCents(int cen)
{
    if (cen < 0)
   {
      cents = cen * -1;
   }

   else

      cents = cen;
}