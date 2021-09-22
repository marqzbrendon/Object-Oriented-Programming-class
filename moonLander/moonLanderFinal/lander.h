/***********************************************************************
 * Header File:
 *    LANDER : A class represting the Lander.
 * Author:
 *    Brendon Marques
 * Summary:
 *    This class conteins important methods about the Lander and its
 *	  functionalities.
 ************************************************************************/

#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

 /********************************************
  * LANDER
  * Yeah sure
  ********************************************/
class Lander
{
private:

	// Private variables
	Point point;
	Velocity velocity;
	bool alive;
	bool landed;
	int fuel;
	bool thrust;

public:

	// Methods
	Point getPoint() const;
	Velocity getVelocity() const;
	bool isAlive();
	bool isLanded();
	int getFuel();
	bool canThrust();
	void setFuel(int fuel);
	void setLanded(bool landed);
	void setAlive(bool alive);
	void applyGravity(float gravity);
	void applyThrustLeft();
	void applyThrustRight(); 
	void applyThrustBottom();
	void advance();
	void draw();
	void setPoint(Point point);

	// Constructor
	Lander()
	{	
		alive = true;
		landed = false;
		fuel = 0;
		thrust = false;
	}
	
};

#endif