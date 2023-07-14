#include "ship.h"
/*********************************************
* ROTATE SHIP
*********************************************/
void Ship::input(const Interface *pUI, double time, list<Satellite*> &satellites)
{
	
	// ship turns counter-clockwise
	if (pUI->isLeft())
	{
		// rotates direction in radians
		rotate(-0.1);
	}
	 
	// ship turns clockwise
	if (pUI->isRight())
	{
		// rotates direction in radians
		rotate(0.1);
	}
  
	// add thrust
	if (pUI->isDown())
	{
		applyThrust(time);
	}
	
	if (!pUI->isDown())
		setThrust(false);
	
	// launch projectile
	if (pUI->isSpace())
	{
		launchProjectile(satellites);
	 }
 }

/*********************************************
* APPLY THRUST
*********************************************/
void Ship::applyThrust(double time)
{
	setThrust(true);

	velocity.setSpeedDirection(velocity.getSpeed() + 15, getDirection());
	Acceleration aGravity = getGravity();
	
	// thrust acceleration is 2.0,
	// which lasts for 48 seconds of simulation time
	velocity.updateVelocity(aGravity, time * 2.0);
	updatePosition(aGravity, time);
}

/*********************************************
* LAUNCH PROJECTILE
*********************************************/
void Ship::launchProjectile(list<Satellite*> &satellites)
{
	// set direction for projectile to be fired
	Direction fireDirection;
	fireDirection.setRadians(getDirectionAngle());
	
	// projectile is 9,000 m/s faster than the ship
	Velocity fireVelocity;
	fireVelocity.setSpeedDirection((velocity.getSpeed() + 9000), fireDirection);

	Projectile *projectile = new Projectile(getPos(), fireVelocity, fireDirection);
	// add to satellites list
	satellites.push_back(projectile);
	
}

