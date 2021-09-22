   // File: order.cpp

#include "order.h"
#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * getProduct
 *
 * This method returns the product.
 ***********************************************************************/
Product Order::getProduct()
{
   return product;
}

/**********************************************************************
 * setProduct
 *
 * This method defines the product.
 ***********************************************************************/
void Order::setProduct(Product product)
{
   this->product = product;
}

/**********************************************************************
 * getQuantity
 *
 * Returns the quantity.
 ***********************************************************************/
int Order::getQuantity()
{
   return quantity;
}

/**********************************************************************
 * setQuantity
 *
 * Sets the quantity.
 ***********************************************************************/
void Order::setQuantity(int quantity)
{
   this->quantity = quantity;
}

/**********************************************************************
 * getCustomer
 *
 * Returns the customer info.
 ***********************************************************************/
Customer Order::getCustomer()
{
   return customer;
}

/**********************************************************************
 * setCustomer
 *
 * Defines the customer.
 ***********************************************************************/
void Order::setCustomer(Customer customer)
{
   this->customer = customer;
}

/**********************************************************************
 * getShippingZip
 *
 * Returns the customer's shipping.
 ***********************************************************************/
string Order::getShippingZip()
{
   return customer.getAddress().getZip();
}

/**********************************************************************
 * getTotalPrice
 *
 * Returns the total price of the order.
 ***********************************************************************/
float Order::getTotalPrice()
{
   return product.getTotalPrice() * quantity;
}

/**********************************************************************
 * displayShippingLabel
 *
 * Displays the shipping label.
 ***********************************************************************/
void Order::displayShippingLabel()
{
   cout << customer.getName()
        << endl
        << customer.getAddress().getStreet()
        << endl
        << customer.getAddress().getCity()
        << ", "
        << customer.getAddress().getState()
        << " "
        << customer.getAddress().getZip()
        << endl;
}

/**********************************************************************
 * displayInformation
 *
 * Displays information on the order.
 ***********************************************************************/
void Order::displayInformation()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << customer.getName()
        << endl
        << product.getName()
        << endl
        << "Total Price: $"
        << getTotalPrice()
        << endl;
}