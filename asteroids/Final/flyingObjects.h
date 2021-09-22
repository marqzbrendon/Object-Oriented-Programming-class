#ifndef flyingObject_h
#define flyingObject_h




// Put your FlyingObject class here
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

#pragma once
class FlyingObjects
{
private:

protected:
   bool alive;
   Velocity speed;

public:

   // Constructors
   FlyingObjects()
   {
      alive = true;
   }

   bool isAlive();
   Point getPoint();
   void kill();
   void advance(Point br, Point tl);
   void setVelocity(Velocity sp);
   Velocity getVelocity();
   void setPoint(Point p);
   void setAlive(bool newAlive) { alive = newAlive; }

   Point position;
};

#endif /* flyingObject_h */
