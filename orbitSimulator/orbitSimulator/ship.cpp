#include "ship.h"
/*********************************************
* ROTATE SHIP
*********************************************/
void Ship::input(const Interface *pUi, vector<Satellite*> satellites)
{
	// ship turns counter-clockwise
	if (pUi->isLeft())
	{
		// rotates in radians
		direction.rotate(-0.1);
	}
	 
	// ship turns clockwise
	if (pUi->isRight())
	{
		// rotates in radians
		direction.rotate(0.1);
	}
  
	// add thrust
	if (pUi->isDown())
	{
		// thrust acceleration is 2.0,
		// which lasts for 48 seconds of simulation time
		 
		applyThrust(2.0, 48);
	}
  
	// launch projectile
	if (pUi->isSpace())
	{
		launchProjectile();
	 }
 }

void Ship::applyThrust(double thrustAmount, double time)
{
	setThrust(true);
	Acceleration aGravity = getGravity();
	velocity.updateVelocity(aGravity, time * 2.0);
	updatePosition(aGravity, time);
}

void Ship::launchProjectile()
{
	
}

