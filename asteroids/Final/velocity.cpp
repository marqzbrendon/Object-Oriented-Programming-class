#include "velocity.h"


// Put your velocity methods here
/*********************************************
  * VELOCITY :: GET DX
  *
  *
  *********************************************/
float Velocity::getDx()
{
   return dx;
}

/*********************************************
 * VELOCITY :: GET DY
 *
 *
 *********************************************/
float Velocity::getDy()
{
   return dy;
}

/*********************************************
 * VELOCITY :: SET DX
 *
 *
 *********************************************/
void Velocity::setDx(float x)
{
   dx = x;
}

/*********************************************
 * VELOCITY :: SET DY
 *
 *
 *********************************************/
void Velocity::setDy(float y)
{
   dy = y;
}