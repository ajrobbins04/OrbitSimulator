#include "ship.h"

void Ship::rotateShip(float amount)
{
	direction.rotate(amount);
}

void Ship::applyThrust(float thrustAmount, float time)
{
	setThrust(true);
	float altitude = getAltitude();
	Acceleration acc(altitude, direction);
	velocity.updateVelocity(acc, time, thrustAmount);
	updatePosition();
	
}

void Ship::launchProjectile()
{
	
}
