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
 * SET SPEED DIRECTION
 * Sets the speed and the direction of an
 * object's velocity.
 *********************************************/
void Velocity::setSpeedDirection(double speed, const Direction &dir)
{
	dx = speed * dir.getDx();
	dy = speed * dir.getDy();
}

/*********************************************
 * UPDATE
 * Updates the velocity based on its current velocity,
 * acceleration, and time.
 *********************************************/
void Velocity::updateVelocity(const Acceleration &acc, double time)
{
	// velocity = current velocity + acceleration * time
	double newDx = getDx() + acc.getDDx() * time;
	double newDy = getDy() + acc.getDDy() * time;
	
	setDx(newDx);
	setDy(newDy);
}



