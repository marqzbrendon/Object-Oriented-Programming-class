/***********************************************************************
 * Header File:
 *    VELOCITY : ...
 * Author:
 *    Brendon Marques
 * Summary:
 *    This class will control the Lander velocity.
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
private:
	// Private variables
	float x;
	float y;
public:

	// Methods
	float getDx();
	float getDy();
	void setDx(float x);
	void setDy(float y);

	// Constructors
	Velocity()
	{
		x = 0;
		y = 0;
	}

	Velocity(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

};

#endif
