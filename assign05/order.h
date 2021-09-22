// File: order.h

#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include "customer.h"
#include <iostream>
using namespace std;


// Put your Order class here
class Order
{
private:
   Product product;
   int quantity;
   Customer customer;

public:
   Product getProduct();
   void setProduct(Product product);
   int getQuantity();
   void setQuantity(int quantity);
   Customer getCustomer();
   void setCustomer(Customer customer);
   string getShippingZip();
   float getTotalPrice();
   void displayShippingLabel();
   void displayInformation();

   Order()
   {
      quantity = 0;
   }

   Order(Product product, int quantity, Customer customer)
   {
      this->product = product;
      this->quantity = quantity;
      this->customer = customer;
   }
};


#endif
