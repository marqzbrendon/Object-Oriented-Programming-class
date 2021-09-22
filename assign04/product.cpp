/***************************************************************
 * File: product.cpp
 * Author: Brendon Marques
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"
#include <iostream>
#include <iomanip>
using namespace std;


/**********************************************************************
 * prompt
 *
 * This method prompts for the product information, then initializes
 * getSalesTax, getShippingCost, and getTotalPrice methods.
 ***********************************************************************/
void Product::prompt()
{
   // prompt infos
	cout << "Enter name: ";
	getline(cin, name);

	cout << "Enter description: ";
	getline(cin, description); 

	cout << "Enter weight: ";
	cin >> weight;

   // keep prompting in case of invalid price
   do 
   {  
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }

	   cout << "Enter price: ";
	   cin >> basePrice;
   }
   while (basePrice < 0 || cin.fail());

   // initialize variables to be displayed later
   getSalesTax();
   getShippingCost();
   getTotalPrice();
}

/**********************************************************************
 * getSalesTax
 *
 * This method calculates the sales tax.
 ***********************************************************************/
void Product::getSalesTax()
{
   salesTax = basePrice * 0.06;
}

/**********************************************************************
 * getShippingCost
 *
 * This method calculates the shipping costs for each product.
 ***********************************************************************/
void Product::getShippingCost()
{
   // products that weights less than 5 lbs
   if (weight < 5)
   {
      shippingCost = 2;
   }

   // products that weight 5 lbs or more
   else
   {
      shippingCost = 2 + ((int)weight - 5) * 0.1;
   }
}

/**********************************************************************
 * getTotalPrice
 *
 * This method calculates the total price of the product.
 ***********************************************************************/
void Product::getTotalPrice()
{
   totalPrice = basePrice + salesTax + shippingCost;
}

/**********************************************************************
 * displayAdProf
 *
 * This method displays the Advertising profile
 ***********************************************************************/
void Product::displayAdProf()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << name << " - $" << basePrice << endl
        << "(" << description << ")" << endl;
}

/**********************************************************************
 * displayInvLine
 *
 * This method displays the Inventory line
 ***********************************************************************/
void Product::displayInvLine()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "$" << basePrice << " - ";

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);

   cout << name << " - " << weight << " lbs\n";
}

/**********************************************************************
 * displayReceipt
 *
 * This method displays the receipt.
 ***********************************************************************/
void Product::displayReceipt()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << name << endl;

   cout << "  Price:         $" << setw(8) << basePrice << endl
        << "  Sales tax:     $" << setw(8) << salesTax << endl
        << "  Shipping cost: $" << setw(8) << shippingCost << endl
        << "  Total:         $" << setw(8) << totalPrice << endl;
}