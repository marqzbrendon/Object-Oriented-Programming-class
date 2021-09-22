#include "ship.h"

// Put your ship methods here

void Ship::checkAngle()
{
   if (angle < 0)
   {
      float newAngle = 360 + angle;
      angle = newAngle;
   }
   
   if (angle > 360)
   {
      float newAngle = 0 + (angle - 360);
      angle = newAngle;
   }
}

void Ship::draw()
{
   drawShip(position, (int)angle, thrust);
}

void Ship::moveLeft()
{
   if (isAlive())
   { 
      angle += ROTATE_AMOUNT;
   }
}

void Ship::moveRight()
{
   if (isAlive())
   {
      angle -= ROTATE_AMOUNT;
   }
}

void Ship::accelerate()
{
   if (isAlive())
   {
      float newAngle = angle + 90;
      // set the speed to move the ship
      speed.setDx(speed.getDx() + THRUST_AMOUNT * (cos(M_PI / 180.0 * (newAngle))));
      speed.setDy(speed.getDy() + THRUST_AMOUNT * (sin(M_PI / 180.0 * (newAngle))));

      // calculate the ship's total velocity
      totalVelocity = sqrt((speed.getDx() * speed.getDx()) + (speed.getDy() * speed.getDy()));

      // don't allow the ship to go over the Max_Speed
      if (totalVelocity > MAX_SPEED)
      {
         speed.setDx((speed.getDx() * MAX_SPEED) / totalVelocity);
         speed.setDy((speed.getDy() * MAX_SPEED) / totalVelocity);
      }

   }
}
