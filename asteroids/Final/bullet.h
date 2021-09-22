#ifndef bullet_h
#define bullet_h
#include "flyingObjects.h"
#include "point.h"
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <cmath> // used for sin, cos, and M_PI

#define BULLET_SPEED 7
#define BULLET_LIFE 40


// Put your Bullet class here
class Bullet : public FlyingObjects
{
private:

   int ct;

public:

   void fire(Point point, float angle, const Velocity shipSpeed);
   void draw();
   void count(int &count);

   Bullet()
   {
      ct = 40;
   }
};



#endif /* bullet_h */
