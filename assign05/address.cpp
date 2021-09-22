// File: address.cpp

#include "address.h"
#include <iostream>
using namespace std;

/**********************************************************************
 * getStreet
 *
 * Returns the street name.
 ***********************************************************************/
string Address::getStreet()
{
   return street;
}

/**********************************************************************
 * setStreet
 *
 * Sets the name of the street.
 ***********************************************************************/
void Address::setStreet(string street)
{
   this->street = street;
}

/**********************************************************************
 * getState
 *
 * Returns the name of the state.
 ***********************************************************************/
string Address::getState()
{
   return state;
}

/**********************************************************************
 * setState
 *
 * Defines the name of the state.
 ***********************************************************************/
void Address::setState(string state)
{
   this->state = state;
}

/**********************************************************************
 * getCity
 *
 * Returns the city name.
 ***********************************************************************/
string Address::getCity()
{
   return city;
}

/**********************************************************************
 * setCity
 *
 * Sets the name of the city.
 ***********************************************************************/
void Address::setCity(string city)
{
   this->city = city;
}

/**********************************************************************
 * getZip
 *
 * Returns the zip code.
 ***********************************************************************/
string Address::getZip()
{
   return zip;
}

/**********************************************************************
 * setZip
 *
 * Defines the zip code.
 ***********************************************************************/
void Address::setZip(string zip)
{
   this->zip = zip;
}

/**********************************************************************
 * display
 *
 * Displays the address.
 ***********************************************************************/
void Address::display()
{
   cout << street 
        << endl
        << city 
        << ", "
        << state
        << " "
        << zip
        << endl;
}