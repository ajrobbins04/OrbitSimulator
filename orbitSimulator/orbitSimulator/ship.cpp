#include "ship.h"

void Ship::rotateShip(float amount)
{
	direction.rotate(amount);
}

void Ship::applyThrust(float thrustAmount)
{
	setThrust(true);
	
}

void Ship::launchProjectile()
{
	
}
