// File: address.h

#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
using namespace std;

// Address class
class Address
{
private:
   string street;
   string city;
   string state;
   string zip;

public:
   string getStreet();
   void setStreet(string street);
   string getState();
   void setState(string state);
   string getCity();
   void setCity(string city);
   string getZip();
   void setZip(string zip);
   void display();

   Address()
   {
      street = "unknown";
      zip = "00000";
      city = "";
      state = "";
   }

   Address(string street, string city, string state, string zip)
   {
      this->street = street;
      this->city = city;
      this->state = state;
      this->zip = zip;
   }
};

#endif
