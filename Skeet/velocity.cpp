/***********************************************************************
 * Source File:
 *    Velocity : Not sure of its purpose at this point.
 * Author:
 *    Brendon Marques
 * Summary:
 *    In the future, I will update this area with meaningful information
 *    about the purpose of this class.
 ************************************************************************/

#include "velocity.h"

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