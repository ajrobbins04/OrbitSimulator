#include "acceleration.h"

/*********************************************
 * GET GRAVITY
 * Computes amount of acceleration due to gravity
 * at a given altitude
 *********************************************/
void Acceleration::setGravity(float altitude, const Position &pos)
{
	Direction dir;
	dir.setDxDy(pos.getMetersX(), pos.getMetersY());
	
	// tmp is just a temporary variable to store one
	// aspect of the gravity computation
	float tmp = EARTH_RADIUS / (EARTH_RADIUS + altitude);
	float gravity = EARTH_GRAVITY * pow(tmp, 2);
	
	setDDx(gravity * dir.getDx());
	setDDy(gravity * dir.getDy());

}

/*********************************************
 * UPDATE ACCELERATION
 * Updates the acceleration at the current direction.
 *********************************************/
void Acceleration::updateAcc(float gravity, const Direction &direction)
{
	setDDx(gravity * direction.getDx());
	setDDy(gravity * direction.getDy());
}

