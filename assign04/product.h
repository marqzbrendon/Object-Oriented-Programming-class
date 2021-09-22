/***************************************************************
 * File: product.h
 * Author: (your name here)
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;

// Defining class Product
class Product
{
private: 

   // private variables
	string name;
	float basePrice;
	float weight;
	string description;
   float salesTax;
   float shippingCost;
   float totalPrice;

public:

   // constructors
   Product()
   {
      name = "N/A";
      basePrice = 0;
      weight = 0;
      description = "N/A";
      salesTax = 0;
      shippingCost = 0;
      totalPrice = 0;
   }

   // public methods
	void prompt();
	void getSalesTax();
	void getShippingCost();
	void getTotalPrice();
	void displayAdProf();
	void displayInvLine();
	void displayReceipt();
};

#endif
