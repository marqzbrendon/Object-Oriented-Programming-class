#ifndef ROBOT_H
#define ROBOT_H

#include "point.h"

class Robot
{
private:
   Point position;

   int energy;

public:
   void display() const;
   int getEnergy() const;
   void setEnergy(int energy);
   void setPosition(Point p);
   void moveUp();
   void moveDown();
   void moveLeft();
   void moveRight();
   void fireLaser();

   Robot()
   {
      energy = 100;
   }

   Robot(int energy)
   {
      if (energy < 0)
      {
         energy = 0;
      }

      this->energy = energy;
   }

   Robot (Point p, int energy)
   {
      position = p;

      if (energy < 0)
      {
         energy = 0;
      }

      this->energy = energy;
   }
};

#endif
