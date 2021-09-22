#include "bullet.h"

void Bullet::fire(Point point, float angle)
{
   setPoint(point);
   speed.setDx(BULLET_SPEED * (-cos(M_PI / 180.0 * angle)));
   speed.setDy(BULLET_SPEED * (sin(M_PI / 180.0 * angle)));
}

void Bullet::draw()
{
   drawDot(getPoint());
}
