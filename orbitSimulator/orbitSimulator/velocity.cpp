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
 * GET DIRECTION
 * Computes the direction based on the current
 * velocity.
 *********************************************/
Direction Velocity::getDirection() const
{
	Direction dir;
	dir.setDxDy(dx, dy);
	return dir;
}
/*********************************************
 * UPDATE
 * Updates the velocity based on its current velocity,
 * acceleration, and time.
 *********************************************/
void Velocity::updateVelocity(const Acceleration &aGravity)
{
	// velocity = current velocity + acceleration * time
	float newDx = getDx() + aGravity.getDDx() * TIME;
	float newDy = getDy() + aGravity.getDDy() * TIME;
	
	setDx(newDx);
	setDy(newDy);
}

/*********************************************
 * UPDATE
 * Updates the velocity based on its current velocity,
 * acceleration, and time.
 *********************************************/
void Velocity::updateVelocity(const Acceleration &aGravity, float time)
{
	// velocity = current velocity + acceleration * time
	float newDx = getDx() + aGravity.getDDx() * time;
	float newDy = getDy() + aGravity.getDDy() * time;
	
	setDx(newDx);
	setDy(newDy);
}


/*********************************************
 * UPDATE
 * Updates the velocity based on its current velocity,
 * acceleration, time, AND thrustAmount.
 *********************************************/
void Velocity::updateVelocity(const Acceleration &aGravity, float time, float thrustAmount)
{
	float newDx = getDx() + (aGravity.getDDx() + thrustAmount) * time;
	float newDy = getDy() + (aGravity.getDDy() + thrustAmount) * time;
	
	setDx(newDx);
	setDy(newDy);
}

