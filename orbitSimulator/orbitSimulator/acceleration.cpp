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
 * Updates the speed and direction.
 *********************************************/
void Acceleration::updateAcc(float aGravity, const Direction &direction)
{
	setDDx(aGravity * direction.getDx());
	setDDy(aGravity * direction.getDy());
}

