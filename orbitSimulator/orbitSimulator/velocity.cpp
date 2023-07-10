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
 * Computes the direction of travel based on
 * the current velocity.
 *********************************************/
Direction Velocity::getDirection() const
{
	Direction dir;
	dir.setDxDy(dx, dy);
	return dir;
}

/*********************************************
 * SET SPEED DIRECTION
 * Sets the speed and the direction of an
 * object's velocity.
 *********************************************/
void Velocity::setSpeedDirection(double speed, const Direction &dir)
{
	dx = speed * dir.getDx(); // speed * sin(angle)
	dy = speed * dir.getDy(); // speed * cos(angle)
}

/*********************************************
 * SET SPEED DIRECTION
 * Sets the speed and the direction (in degrees)
 * of an object's velocity.
 *********************************************/
void Velocity::setSpeedDirection(double speedX, double speedY, const Direction &dir)
{
	dx = speedX * dir.getDx();
	dy = speedY * dir.getDy();
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
void Velocity::updateVelocity(const Acceleration &acc, double time)
{
	// velocity = current velocity + acceleration * time
	double newDx = getDx() + acc.getDDx() * time;
	double newDy = getDy() + acc.getDDy() * time;
	
	setDx(newDx);
	setDy(newDy);
}

