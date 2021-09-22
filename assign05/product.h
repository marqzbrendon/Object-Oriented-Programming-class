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

   // public methods
   string getName();
   void setName(string name);
   string getDescription();
   void setDescription(string description);
   float getBasePrice();
   void setBasePrice(float basePrice);
   float getWeight();
   void setWeight(float weight);
	void prompt();
	float getSalesTax();
	float getShippingCost();
	float getTotalPrice();
	void displayAdProf();
	void displayInvLine();
	void displayReceipt();

      // constructors
   Product()
   {
      name = "none";
      basePrice = 0;
      weight = 0;
      description = "";
      salesTax = 0;
      shippingCost = 0;
      totalPrice = 0;
   }

   Product(string name, string description, float basePrice, float weight)
   {
      this->name = name;
      this->description = description;
      this->basePrice = basePrice;
      this->weight = weight;
   }
};

#endif
