#include "velocity.h"

#include <iostream>
using namespace std;

// TODO: Put your method bodies here



void Velocity :: prompt()
{
   cout << "dx: ";
   cin >> dx;

   cout << "dy: ";
   cin >> dy;
}

void Velocity :: display() const 
{
   cout << "(dx=" << dx << ", dy=" << dy << ")";
}

Velocity operator + (const Velocity &lhs, const Velocity &rhs)
{
   Velocity temp;

   temp.setDx(lhs.getDx() + rhs.getDx());
   temp.setDy(lhs.getDy() + rhs.getDy());

   return temp;
}

void operator += (Velocity &lhs, const Velocity &rhs)
{
   lhs.setDx(lhs.getDx() + rhs.getDx());
   lhs.setDy(lhs.getDy() + rhs.getDy());
}