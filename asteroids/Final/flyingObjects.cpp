#include "flyingObjects.h"


// Put your FlyingObject method bodies here
bool FlyingObjects::isAlive()
{
   return alive;
}

Point FlyingObjects::getPoint()
{
   return position;
}

void FlyingObjects::kill()
{
   alive = false;
}

void FlyingObjects::advance(Point br, Point tl)
{
   position.setX(position.getX() + speed.getDx());
   if (position.getX() > br.getX() || position.getX() < tl.getX())
   {
      position.setX(-position.getX());
   }
   position.setY(position.getY() + speed.getDy());
   if (position.getY() > tl.getY() || position.getY() < br.getY())
   {
      position.setY(-position.getY());
   }
}

void FlyingObjects::setVelocity(Velocity sp)
{
   speed = sp;
}

Velocity FlyingObjects::getVelocity()
{
   return speed;
}

void FlyingObjects::setPoint(Point p)
{
   position = p;
}
