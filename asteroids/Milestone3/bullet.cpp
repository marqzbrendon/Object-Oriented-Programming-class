#include "bullet.h"


// Put your bullet methods here

void Bullet::fire(Point point, float angle)
{
   setPoint(point);

   speed.setDx(BULLET_SPEED * (cos(M_PI / 180.0 * (angle + 90.0))));
   speed.setDy(BULLET_SPEED * (sin(M_PI / 180.0 * (angle + 90.0))));
}

void Bullet::draw()
{
   drawDot(getPoint());
   count(ct);
}

void Bullet::count(int &count)
{
   count--;

   if (count < 0)
   {
      kill();
   }
}
