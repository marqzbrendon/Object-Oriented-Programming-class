#include "ship.h"

// Put your ship methods here

void Ship::draw()
{
   drawShip(position, angle, false);
}

void Ship::moveLeft()
{
   angle += ROTATE_AMOUNT;
}

void Ship::moveRight()
{
   angle -= ROTATE_AMOUNT;
}

void Ship::accelerate()
{
   speed.setDx(speed.getDx() + THRUST_AMOUNT* (cos(M_PI / 180.0 * (angle + 90.0))));
   if (speed.getDx() > 5)
   {
      speed.setDx(5);
   }
   else if (speed.getDx() < -5)
   {
      speed.setDx(-5);
   }
   speed.setDy(speed.getDy() + THRUST_AMOUNT* (sin(M_PI / 180.0 * (angle + 90.0))));
   if (speed.getDy() > 5)
   {
      speed.setDy(5);
   }
   else if (speed.getDy() < -5)
   {
      speed.setDy(-5);
   }
}
