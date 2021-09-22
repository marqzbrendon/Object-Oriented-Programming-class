#ifndef BIRD_H
#define BIRD_H

#include "flyingObjects.h"
#include "point.h"

#pragma once
class Bird : public FlyingObjects
{
private:
   
public:

	virtual int hit() = 0;
   virtual void draw() = 0;

   Bird()
   {

   }
};

#endif