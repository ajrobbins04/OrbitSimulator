#include "satellite.h"

/*********************************************
 *  GET ALTITUDE
 *  Computes the distance from the center of the
 *  earth to the satellite's current position.
 *********************************************/
float Satellite::getAltitude(const Position &posEarth)
{
	// earth is at (0,0) - which is the default Position
	float distance = sqrt((pos.getMetersX() - posEarth.getMetersX()) * (pos.getMetersX() - posEarth.getMetersX()) +
				(pos.getMetersY() - posEarth.getMetersY()) * (pos.getMetersY() - posEarth.getMetersY()));
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
	float altitude = getAltitude(Position());
	//aGravity.updateAcc()
	aGravity.setGravity(altitude, pos);
	velocity.updateVelocity(aGravity);
	updatePosition();
	
}
