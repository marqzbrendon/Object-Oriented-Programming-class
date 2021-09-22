#include "flyingObjects.h"

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

void FlyingObjects::advance()
{
   position.setX(position.getX() + speed.getDx());
   position.setY(position.getY() + speed.getDy());
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

