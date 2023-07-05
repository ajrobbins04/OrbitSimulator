#include "satellite.h"

/*********************************************
 *  GET ALTITUDE
 *  Computes the distance from the center of the
 *  earth to the satellite's current position.
 *********************************************/
double Satellite::getAltitude()
{
 
	float distance = sqrt(pos.getMetersX() * pos.getMetersX()
						  + pos.getMetersY() * pos.getMetersY());

	return distance - earthRadius;
}

/*********************************************
 * GET GRAVITY
 * Computes amount and direction of gravity
 * at a given altitude
 *********************************************/
Acceleration Satellite::getGravity()
{
	double altitude = getAltitude();
	double gravity = -9.8067;
	
	Direction dirGravity;
	dirGravity.setDxDy(pos.getMetersX(), pos.getMetersY());

	double tmp = earthRadius / (earthRadius + altitude);
	double aGravity = gravity * pow(tmp, 2);
	
	return Acceleration(aGravity, dirGravity);
}

/*********************************************
 * 	COMPUTE ANGULAR VELOCITY
 *********************************************/
void Satellite::computeAngularVelocity(double time)
{

}

/*********************************************
 *  UPDATE
 *  Updates the satellite's position based on its current
 *  position, velocity, and time.
 *********************************************/
void Satellite::updatePosition(const Acceleration &aGravity, double time)
{
	pos.addMetersX(velocity.getDx() * time + (0.5 * aGravity.getDDx()) * (time * time));
	pos.addMetersY(velocity.getDy() * time + (0.5 * aGravity.getDDy()) * (time * time));
}

/*********************************************
 *  MOVE
 *  Moves the satellite by updating the velocity, followed
 *  by the position.
 *********************************************/
void Satellite::move(double time)
{
	Acceleration aGravity = getGravity();
	velocity.updateVelocity(aGravity, time);
	updatePosition(aGravity, time);
}
