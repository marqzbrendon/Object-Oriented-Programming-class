#ifndef FLYINGOBJECTS_H
#define FLYINGOBJECTS_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

#pragma once
class FlyingObjects
{
private:

protected:
	bool alive;
	Point position;
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
	void advance();
	void setVelocity(Velocity sp);
	Velocity getVelocity();
   void setPoint(Point p);
	
	
};

#endif