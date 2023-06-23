#include "satellite.h"

/*********************************************
 *  GET ALTITUDE
 *  Computes the distance from the center of the
 *  earth to the satellite's current position.
 *********************************************/
float Satellite::getAltitude()
{
	Position posEarth(0.0, 0.0);
	/*float distance = sqrt(pos.getMetersX() * pos.getMetersX()
						  + pos.getMetersY() * pos.getMetersY());*/
	float distance = sqrt((pos.getMetersX() - posEarth.getMetersX()) * (pos.getMetersX() - posEarth.getMetersX()) +
				(pos.getMetersY() - posEarth.getMetersY()) * (pos.getMetersY() - posEarth.getMetersY()));
	return distance - EARTH_RADIUS;
}

/*********************************************
 * GET GRAVITY
 * Computes amount and direction of gravity
 * at a given altitude
 *********************************************/
Acceleration Satellite::getGravity()
{
	float altitude = getAltitude();
	
	// direction of gravity points down
	Direction dir;
	dir.setDxDy(-pos.getMetersX(), -pos.getMetersY());
	
	float tmp = EARTH_RADIUS / (EARTH_RADIUS + altitude);
	float aGravity = EARTH_GRAVITY * pow(tmp, 2);
	
	return Acceleration(aGravity, dir);
}

/*********************************************
 *  UPDATE
 *  Updates the satellite's position based on its current
 *  position, velocity, and time.
 *********************************************/
void Satellite::updatePosition()
{
	float x = pos.getMetersX() + velocity.getDx() * TIME;
	float y = pos.getMetersY() + velocity.getDy() * TIME;
	
	pos.setMeters(x, y);
}


/*********************************************
 *  MOVE
 *  Moves the satellite by updating the velocity, followed
 *  by the position.
 *********************************************/
void Satellite::move()
{
	float altitude = getAltitude();
	Acceleration acc(altitude, direction);
	velocity.updateVelocity(acc);
	updatePosition();
}
