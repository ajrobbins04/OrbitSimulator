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

void Satellite::update()
{
	/*double x = pos->getMetersX();
	double dx = v.getDx();
	double ddx = acc->getDDx();
	
	double accTimeX = ddx * pow(TIME, 2);
	double newX = x + dx * TIME + (accTimeX / 2);
	pos->setMetersX(newX);
   
	double y = pos->getMetersY();
	double dy = v->getDy();
	double ddy = acc->getDDy();

	double accTimeY = ddy * pow(TIME, 2);
	double newY = y + dy * TIME + (accTimeY / 2);

	pos->setMetersY(newY);*/
}

