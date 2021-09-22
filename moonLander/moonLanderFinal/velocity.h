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
	float dx;
	float dy;
public:

	// Methods
	float getDx();
	float getDy();
	void setDx(float dx);
	void setDy(float dy);

	// Constructors
	Velocity()
	{
		dx = 1;
		dy = 1;
	}

	Velocity(float dx, float dy)
	{
		this->dx = dx;
		this->dy = dy;
	}

};

#endif
