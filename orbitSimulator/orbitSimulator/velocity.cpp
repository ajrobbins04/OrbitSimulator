#include "velocity.h"

/*********************************************
 * GET SPEED
 * Computes the velocity speed.
 *********************************************/
float Velocity::getSpeed() const
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
	float currDx = getDx();
	float currDy = getDy();
	
	// velocity = current velocity + acceleration * time
	float newDx = currDx + acc.getDDx() * TIME;
	float newDy = currDy + acc.getDDy() * TIME;
	
	setDx(newDx);
	setDy(newDy);
}

/*********************************************
 * UPDATE
 * Updates the velocity based on its current velocity,
 * acceleration, and time.
 *********************************************/
void Velocity::updateVelocity(const Acceleration &acc, float time)
{
	float currDx = getDx();
	float currDy = getDy();
	
	// velocity = current velocity + acceleration * time
	float newDx = currDx + acc.getDDx() * time;
	float newDy = currDy + acc.getDDy() * time;
	
	setDx(newDx);
	setDy(newDy);
}


/*********************************************
 * UPDATE
 * Updates the velocity based on its current velocity,
 * acceleration, and time.
 *********************************************/
void Velocity::updateVelocity(const Acceleration &acc, float time, float thrustAmount)
{
	float currDx = getDx();
	float currDy = getDy();
	
	// velocity = current velocity + acceleration * time
	float newDx = currDx + acc.getDDx() + thrustAmount * time;
	float newDy = currDy + acc.getDDy() + thrustAmount * time;
	
	setDx(newDx);
	setDy(newDy);
}

