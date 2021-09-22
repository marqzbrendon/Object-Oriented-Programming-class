#ifndef BULLET_H
#define BULLET_H

#define _USE_MATH_DEFINES
#include <cmath> // used for sin, cos, and M_PI
#include "point.h"
#include "flyingObjects.h"

#define BULLET_SPEED 10.0
#pragma once
class Bullet : public FlyingObjects
{
private:


public:

	void fire(Point point, float angle);
   void draw();

   Bullet()
   {
      speed.setDx(speed.getDx() - 1);

   }
};

#endif