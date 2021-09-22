/***************************************************************
 * File: assign04.cpp
 * Author: Brendon Marques
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "product.h"

/**********************************************************************
 * main
 *
 * it is the driver of the program.
 ***********************************************************************/
int main()
{
   // Declare Store object
   Product store;

   // Call function prompt
   store.prompt();

   // pre-written code
   cout << endl;
   cout << "Choose from the following options:\n";
   cout << "1 - Advertising profile\n";
   cout << "2 - Inventory line item\n";
   cout << "3 - Receipt\n";
   cout << endl;
   cout << "Enter the option that you would like displayed: ";

   int choice;
   cin >> choice;

   cout << endl;

   // call each function according to the user's answer
   if (choice == 1)
   {
      // Call display advertising profile function
      store.displayAdProf();
   }
   else if (choice == 2)
   {
      // Call display inventory line item function
      store.displayInvLine();
   }
   else
   {
      // Call display receipt
      store.displayReceipt();
   }

   return 0;
}
