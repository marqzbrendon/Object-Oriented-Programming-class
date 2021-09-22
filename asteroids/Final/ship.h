#ifndef ship_h
#define ship_h

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <cmath> // used for sin, cos, and M_PI


#define SHIP_SIZE 10
#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#define MAX_SPEED 6

#include "flyingObjects.h"
#include "velocity.h"

// Put your Ship class here
class Ship : public FlyingObjects
{
private:
   float angle;
   bool thrust;
   float totalVelocity;

public:

   Ship()
   {
      position.setX(0);
      position.setY(0);
      speed.setDx(0);
      speed.setDy(0);
      angle = 0;
      thrust = false;
      totalVelocity = 0.0;
   }

   float getAngle() { return angle; }
   void checkAngle();
   void draw();
   void moveLeft();
   void moveRight();
   void accelerate();
   void setThrust(bool t) { thrust = t; }
   Velocity getSpeed() { return speed; }
   void setAngle(int angle) { this->angle = angle; }
};


#endif /* ship_h */
