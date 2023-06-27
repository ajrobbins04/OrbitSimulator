#include "satellite.h"

/*********************************************
 *  GET ALTITUDE
 *  Computes the distance from the center of the
 *  earth to the satellite's current position.
 *********************************************/
double Satellite::getAltitude()
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
	double altitude = getAltitude();
	
	// direction of gravity points down
	Direction dir;
	dir.setDxDy(pos.getMetersX(), pos.getMetersY());
	
	double tmp = EARTH_RADIUS / (EARTH_RADIUS + altitude);
	double aGravity = EARTH_GRAVITY * pow(tmp, 2);
	
	return Acceleration(aGravity, dir);
}

/*********************************************
 *  UPDATE
 *  Updates the satellite's position based on its current
 *  position, velocity, and time.
 *********************************************/
void Satellite::updatePosition()
{
	double x = pos.getMetersX() + velocity.getDx() * TIME;
	double y = pos.getMetersY() + velocity.getDy() * TIME;
	
	pos.setMeters(x, y);
}

void Satellite::updatePosition(double time)
{
	double x = pos.getMetersX() + velocity.getDx() * time;
	double y = pos.getMetersY() + velocity.getDy() * time;
	
	pos.setMeters(x, y);
}
/*********************************************
 *  UPDATE
 *  Updates the satellite's position based on its current
 *  position, velocity, and time.
 *********************************************/
void Satellite::updatePosition(double time, const Acceleration &acc)
{
	//float x = pos.getMetersX() + velocity.getDx() * time;
	//float y = pos.getMetersY() + velocity.getDy() * time;
	
	//pos.setMeters(x, y);
	
	pos.addMetersX(velocity.getDx() * time + (0.5 * acc.getDDx()) * (time * time));
	pos.addMetersY(velocity.getDy() * time + (0.5 * acc.getDDy()) * (time * time));
}

/*********************************************
 *  MOVE
 *  Moves the satellite by updating the velocity, followed
 *  by the position.
 *********************************************/
void Satellite::move()
{
	double altitude = getAltitude();
	//Acceleration acc(altitude, direction);
	Acceleration acc = getGravity();
	velocity.updateVelocity(acc);
	updatePosition();
}
