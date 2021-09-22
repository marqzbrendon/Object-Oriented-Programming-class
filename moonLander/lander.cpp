/***********************************************************************
 * Source File:
 *    Lander : controls the lander
 * Author:
 *    Brendon Marques
 * Summary:
 *    I am still not completely sure of what wach method will be doing
 *    in the program, so many of the headers are empty at this point.    
 ************************************************************************/

#include "lander.h"
#include "point.h"

 /*********************************************
  * LANDER :: SET FUEL
  * 
  *********************************************/
void Lander::setFuel(int fuel)
{

}

/*********************************************
 * LANDER :: GET POINT
 * 
 *********************************************/
Point Lander::getPoint() const
{
	return point;
}

/*********************************************
 * LANDER :: GET VELOCITY
 * 
 *********************************************/
Velocity Lander::getVelocity() const
{
	return velocity;
}

/*********************************************
 * LANDER :: IS ALIVE
 * 
 *********************************************/
bool Lander::isAlive()
{
	return alive;
}

/*********************************************
 * LANDER :: IS LANDED
 * 
 *********************************************/
bool Lander::isLanded()
{
	return landed;
}

/*********************************************
 * LANDER :: GET FUEL
 * 
 *********************************************/
int Lander::getFuel()
{
	return fuel;
}

/*********************************************
 * LANDER :: CAN THRUST
 * 
 *********************************************/
bool Lander::canThrust()
{
	return thrust;
}

/*********************************************
 * LANDER :: SET LANDED
 * 
 *********************************************/
void Lander::setLanded(bool landed)
{
	
}

/*********************************************
 * LANDER :: SET ALIVE
 * 
 *********************************************/
void Lander::setAlive(bool alive)
{
	
}

/*********************************************
 * LANDER :: APPLY GRAVITY
 * 
 *********************************************/
void Lander::applyGravity(float gravity)
{

}

/*********************************************
 * LANDER :: APPLY THRUST LEFT
 * 
 *********************************************/
void Lander::applyThrustLeft()
{

}

/*********************************************
 * LANDER :: APPLY THRUST RIGHT
 * 
 *********************************************/
void Lander::applyThrustRight()
{

}

/*********************************************
 * LANDER :: APPLY THRUST BOTTOM
 * 
 *********************************************/
void Lander::applyThrustBottom()
{

}

/*********************************************
 * LANDER :: ADVANCE
 * 
 *********************************************/
void Lander::advance()
{

}

/*********************************************
 * LANDER :: DRAW
 * Calls the drawing function to draw the Lander
 *********************************************/
void Lander::draw()
{
	drawLander(point);
}