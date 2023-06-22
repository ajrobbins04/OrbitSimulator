#include "satellite.h"

/*********************************************
 *  GET ALTITUDE
 *  Computes the distance from the center of the
 *  earth to the satellite's current position.
 *********************************************/
float Satellite::getAltitude()
{
 	float distance = sqrt(pos.getMetersX() * pos.getMetersX()
						  + pos.getMetersY() * pos.getMetersY());
	return distance - EARTH_RADIUS;
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
	//aGravity.updateAcc()
	aGravity.setGravity(altitude, pos);
	velocity.updateVelocity(aGravity);
	updatePosition();
	
}
