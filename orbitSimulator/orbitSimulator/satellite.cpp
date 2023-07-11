#include "satellite.h"
 
/*********************************************
 *  COMPUTE ANGULAR VELOCITY
 *********************************************/
void Satellite::computeAngularVelocity()
{
	double angularVelocity = velocity.getSpeed() / radius;
	setAngularVelocity(angularVelocity);
}

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
 *  UPDATE POSITION
 *  Updates the satellite's position based on its current
 *  position, velocity, and time.
 *********************************************/
void Satellite::updatePosition(const Acceleration &aGravity, double time)
{
	pos.addMetersX(velocity.getDx() * time + (0.5 * aGravity.getDDx()) * (time * time));
	pos.addMetersY(velocity.getDy() * time + (0.5 * aGravity.getDDy()) * (time * time));
}

/*********************************************
 * 	EXPLODE
 *  Makes a Satellite object "shoot off" in a random
 *  direction upon collosion.
 *********************************************/
void Satellite::explode()
{
	if (isYPositive())
		pos.addPixelsY(4.0); // moves satelliteFragment 4px. from its point of creation
	else
		pos.addPixelsY(-4.0);
	
	velocity.setSpeed(velocity.getDx() + random(5000, 9000), velocity.getDy() + random(5000, 9000));
}
