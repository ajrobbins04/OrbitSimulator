#include "acceleration.h"

/*********************************************
 * GET GRAVITY
 * Computes amount of acceleration due to gravity
 * at a given altitude
 *********************************************/
float Acceleration::getGravity(float altitude)
{
	// tmp is just a temporary variable to store one
	// aspect of the gravity computation
	float tmp = EARTH_RADIUS / (EARTH_RADIUS + altitude);
	float gravity = EARTH_GRAVITY * pow(tmp, 2);
	
	return gravity;
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

