#include "ship.h"
/*********************************************
* ROTATE SHIP
*********************************************/
void Ship::rotateShip(const Interface *pUi)
{
	// ship turns counter-clockwise
	if (pUi->isLeft())
	{
		// rotates in radians
		//direction.setLeft();
		direction.rotate(-0.1);
		
		while (pUi->isLeft())
			direction.rotate(-0.1);

	}
	 
	// ship turns clockwise
	if (pUi->isRight())
	{
		// rotates in radians
		//direction.setRight();
		direction.rotate(0.1);
		while (pUi->isRight())
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
	velocity.updateVelocity(aGravity, time, thrustAmount);
	updatePosition(aGravity, time);
}

void Ship::launchProjectile()
{
	
}

