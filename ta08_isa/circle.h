#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class Circle : public Point
{
public:

   float getRadius() { return radius; }
   void setRadius(float radius) { this->radius = radius; }
   void promptForCircle();
   void display();

private:

   float radius;
   
};

#endif