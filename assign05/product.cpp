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
 * getSalesTax
 *
 * This method calculates the sales tax.
 ***********************************************************************/
float Product::getSalesTax()
{
   return getBasePrice() * 0.06;
}

/**********************************************************************
 * getShippingCost
 *
 * This method calculates the shipping costs for each product.
 ***********************************************************************/
float Product::getShippingCost()
{
   // products that weights less than 5 lbs
   if (getWeight() < 5)
   {
      return 2;
   }

   // products that weight 5 lbs or more
   else
   {
      return 2 + ((int)getWeight() - 5) * 0.1;
   }
}

/**********************************************************************
 * getTotalPrice
 *
 * This method calculates the total price of the product.
 ***********************************************************************/
float Product::getTotalPrice()
{
   return getBasePrice() + getShippingCost() + getSalesTax();
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

   cout << "  Price:         $" << setw(8) << getBasePrice() << endl
        << "  Sales tax:     $" << setw(8) << getSalesTax() << endl
        << "  Shipping cost: $" << setw(8) << getShippingCost() << endl
        << "  Total:         $" << setw(8) << getTotalPrice() << endl;
}

/**********************************************************************
 * getName
 *
 * Returns the name of the product.
 ***********************************************************************/
string Product::getName()
{
   return name;
}

/**********************************************************************
 * setName
 *
 * Defines the name of the product.
 ***********************************************************************/
void Product::setName(string name)
{
   this->name = name;
}

/**********************************************************************
 * getDescription
 *
 * Returns the description of the product.
 ***********************************************************************/
string Product::getDescription()
{
   return description;
}

/**********************************************************************
 * setDescription
 *
 * Sets the description of the product.
 ***********************************************************************/
void Product::setDescription(string description)
{
   this->description = description;
}

/**********************************************************************
 * getBasePrice
 *
 * Returns the base price of the product.
 ***********************************************************************/
float Product::getBasePrice()
{
   return basePrice;
}

/**********************************************************************
 * setBasePrice
 *
 * Defines the base price of the product.
 ***********************************************************************/
void Product::setBasePrice(float basePrice)
{
   this->basePrice = basePrice;
}

/**********************************************************************
 * getWeight
 *
 * This method returns the weight.
 ***********************************************************************/
float Product::getWeight()
{
   return weight;
}

/**********************************************************************
 * setWeight
 *
 * This method sets the weight.
 ***********************************************************************/
void Product::setWeight(float weight)
{
   this->weight = weight;
}  