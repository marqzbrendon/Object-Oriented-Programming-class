// File: customer.cpp

#include "customer.h"
#include <iostream>
using namespace std;

/**********************************************************************
 * getName
 *
 * Returns the name of the customer.
 ***********************************************************************/
string Customer::getName()
{
   return name;
}

/**********************************************************************
 * setName
 *
 * Defines the name of the customer.
 ***********************************************************************/
void Customer::setName(string name)
{
   this->name = name;
}

/**********************************************************************
 * getAddress
 *
 * Returns the address.
 ***********************************************************************/
Address Customer::getAddress()
{
   return address;
}

/**********************************************************************
 * setAddress
 *
 * Sets the address.
 ***********************************************************************/
void Customer::setAddress(Address address)
{
   this->address = address;
}

/**********************************************************************
 * display
 *
 * Displays information on the customer.
 ***********************************************************************/
void Customer::display()
{
   cout << name
        << endl
        << address.getStreet()
        << endl
        << address.getCity()
        << ", "
        << address.getState()
        << " "
        << address.getZip()
        << endl;
}