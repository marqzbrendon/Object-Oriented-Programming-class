// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "address.h"
#include <iostream>
using namespace std;

// customer class
class Customer
{
private:
   string name;
   Address address;

public:
   string getName();
   void setName(string name);
   Address getAddress();
   void setAddress(Address address);
   void display();

   Customer()
   {
      name = "unspecified";
   }

   Customer(string name, Address address)
   {
      this->name = name;
      this->address = address;
   }
};

#endif
