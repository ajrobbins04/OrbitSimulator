#include "velocity.h"

/*********************************************
 * GET SPEED
 * Computes the velocity speed.
 *********************************************/
double Velocity::getSpeed() const
{
	return sqrt(dx * dx + dy * dy);
}

/*********************************************
 * UPDATE
 * Updates the velocity based on its current velocity,
 * acceleration, and time.
 *********************************************/
void Velocity::updateVelocity(const Acceleration &acc)
{
	double currDx = getDx();
	double currDy = getDy();
	
	// velocity = current velocity + acceleration * time
	double newDx = currDx + acc.getDDx() * TIME;
	double newDy = currDy + acc.getDDy() * TIME;
	
	setDx(newDx);
	setDy(newDy);
}

/*********************************************
 * UPDATE
 * Updates the velocity based on its current velocity,
 * acceleration, and time.
 *********************************************/
void Velocity::updateVelocity(const Acceleration &acc, int time)
{
	double currDx = getDx();
	double currDy = getDy();
	
	// velocity = current velocity + acceleration * time
	double newDx = currDx + acc.getDDx() * time;
	double newDy = currDy + acc.getDDy() * time;
	
	setDx(newDx);
	setDy(newDy);
}

