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
 * APPLY ACCELERATION
 * Applies acceleration to the current velocity
 *********************************************/
void Velocity::applyAcceleration(const Acceleration &acc)
{
	dx += acc.getDDx();
	dy += acc.getDDy();
}

/*********************************************
 * UPDATE
 * Updates the velocity based on its current velocity,
 * acceleration, and time.
 *********************************************/
void Velocity::updateVelocity(const Acceleration &acc)
{
	// velocity = current velocity + acceleration * time
	float newDx = getDx() + acc.getDDx() * TIME;
	float newDy = getDy() + acc.getDDy() * TIME;
	
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
	// velocity = current velocity + acceleration * time
	float newDx = getDx() + acc.getDDx() * time;
	float newDy = getDy() + acc.getDDy() * time;
	
	setDx(newDx);
	setDy(newDy);
}


/*********************************************
 * UPDATE
 * Updates the velocity based on its current velocity,
 * acceleration, time, AND thrustAmount.
 *********************************************/
void Velocity::updateVelocity(const Acceleration &acc, float time, float thrustAmount)
{
	float newDx = getDx() + (acc.getDDx() + thrustAmount) * time;
	float newDy = getDy() + (acc.getDDy() + thrustAmount) * time;
	
	setDx(newDx);
	setDy(newDy);
}

