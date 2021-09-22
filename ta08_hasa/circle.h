#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class Circle
{
public:

   float getRadius() { return radius; }
   void setRadius(float radius) { this->radius = radius; }
   void promptForCircle();
   void display();
   void setPoint(int x, int y);
   int getX() { return center.getX(); }
   int getY() { return center.getY(); }

private:

   Point center;
   float radius;
   
};

#endif