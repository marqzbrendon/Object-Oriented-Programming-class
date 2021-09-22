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
	if (fuel > 0)
	{
		this->fuel = fuel;
	}
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
	if (alive && !landed && fuel > 0)
	{
		thrust = true;
	}
	else
	{
		thrust = false;
	}

	return thrust;
}

/*********************************************
 * LANDER :: SET LANDED
 * 
 *********************************************/
void Lander::setLanded(bool landed)
{
	if (landed == true)
	{
		this->landed = true;
	}
}

/*********************************************
 * LANDER :: SET ALIVE
 * 
 *********************************************/
void Lander::setAlive(bool alive)
{
	this->alive = alive;
}


/*********************************************
 * LANDER :: APPLY GRAVITY
 * 
 *********************************************/
void Lander::applyGravity(float gravity)
{
	velocity.setDy(velocity.getDy() - 0.1);
}

/*********************************************
 * LANDER :: APPLY THRUST LEFT
 * 
 *********************************************/
void Lander::applyThrustLeft()
{
	if (thrust)
	{
		velocity.setDx(velocity.getDx() + 0.1);
		fuel--;
	}
}

/*********************************************
 * LANDER :: APPLY THRUST RIGHT
 * 
 *********************************************/
void Lander::applyThrustRight()
{	
	if (thrust)
	{
		velocity.setDx(velocity.getDx() - 0.1);
		fuel--;
	}
}

/*********************************************
 * LANDER :: APPLY THRUST BOTTOM
 * 
 *********************************************/
void Lander::applyThrustBottom()
{
	if (thrust)
	{
		velocity.setDy(velocity.getDy() + 0.3);
		fuel = fuel - 3;

	}

	if (fuel < 0)
	{
		fuel = 0;
	}
}

/*********************************************
 * LANDER :: ADVANCE
 * 
 *********************************************/
void Lander::advance()
{
	//set point
	point.setX(point.getX() + velocity.getDx());

	point.setY(point.getY() + velocity.getDy());
}

/*********************************************
 * LANDER :: DRAW
 * Calls the drawing function to draw the Lander
 *********************************************/
void Lander::draw()
{
	drawLander(point);
}

/*********************************************
 * LANDER :: SET POINT
 * Calls the drawing function to draw the Lander
 *********************************************/
void Lander::setPoint(Point pos)
{
	this->point = pos;
}