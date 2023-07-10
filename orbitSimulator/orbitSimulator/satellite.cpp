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
	// altitude = height above the earth
	double altitude = getAltitude();
	double gravity = 9.8067;
	
	// direction of gravity points down
	Direction dirGravity;
	dirGravity.setDxDy(-pos.getMetersX(), -pos.getMetersY());

	double tmp = earthRadius / (earthRadius + altitude);
	double aGravity = gravity * pow(tmp, 2);
	
	return Acceleration(aGravity, dirGravity);
}

/*********************************************
 * 	UPDATE DIRECTION
 *********************************************/
void Satellite::updateDirection(const Position &posPrev, double time)
{
	Position posCurrent = getPos();

	double distance = computeDistance(posCurrent, posPrev);
	double linearVelocity = distance / time;
		
	double angularVelocity = linearVelocity / 40000;
	double angleChange = angularVelocity / time;
	direction.rotate(angleChange);

}

/*********************************************
 *  MOVE FORWARD
 *  Shifts the position of a satellite forward based
 *  on the given distance amount.
 *********************************************/
void Satellite::moveForward(double amount)
{
	//pos.addMetersX(amount * direction.getDx());
	//pos.addMetersY(amount * direction.getDy());
	//pos.addMetersX(dx);
	//pos.addMetersY(dy);
 
	pos.addMetersY(amount);

}

/*********************************************
 *  UPDATE POSITION
 *  Updates the satellite's position based on its current
 *  position, velocity, and time.
 *********************************************/
void Satellite::updatePosition(const Acceleration &aGravity, double time)
{
	pos.addMetersX(velocity.getDx() * time + (0.5 * aGravity.getDDx()) * (time * time));
	pos.addMetersY(velocity.getDy() * time + (0.5 * aGravity.getDDy()) * (time * time));
}

