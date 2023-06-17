#include "satellite.h"

/*********************************************
 *  GET ALTITUDE
 *  Computes the distance from the center of the
 *  earth to the satellite's current position.
 *********************************************/
double Satellite::getAltitude()
{
	// earth is at (0,0) - which is the default Position
	double distance = sqrt((pos.getMetersX() * pos.getMetersX())
						   + (pos.getMetersY() * pos.getMetersY()));
	return distance - EARTH_RADIUS;
}

/*********************************************
 *  UPDATE
 *  Updates the satellite's position based on its current
 *  position, velocity, and time.
 *********************************************/
void Satellite::update()
{
	double x = pos.getMetersX() + velocity.getDx() * TIME;
	double y = pos.getMetersY() + velocity.getDy() * TIME;
	
	pos.setMeters(x, y);
}

