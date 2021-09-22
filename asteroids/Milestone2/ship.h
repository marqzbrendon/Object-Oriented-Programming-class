#ifndef ship_h
#define ship_h

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <cmath> // used for sin, cos, and M_PI


#define SHIP_SIZE 10
#define ANGLE_START 0

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "flyingObjects.h"

// Put your Ship class here
class Ship : public FlyingObjects
{
private:
   float angle;

public:

   Ship()
   {
      position.setX(0);
      position.setY(0);
      speed.setDx(0);
      speed.setDy(0);
      angle = ANGLE_START;
   }

   float getAngle() { return angle; }
   void draw();
   void moveLeft();
   void moveRight();
   void accelerate();
};


#endif /* ship_h */
