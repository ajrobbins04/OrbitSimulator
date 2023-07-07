#include "ship.h"
/*********************************************
* ROTATE SHIP
*********************************************/
void Ship::input(const Interface *pUI, double time, vector<Satellite*> &satellites)
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
		// thrust acceleration is 2.0,
		// which lasts for 48 seconds of simulation time
		applyThrust(2.0, 48);
	}
	
	if (!pUI->isDown())
		setThrust(false);
	
	// launch projectile
	if (pUI->isSpace())
	{
		launchProjectile(satellites, time);
	 }
 }

void Ship::applyThrust(double thrustAmount, double time)
{
	setThrust(true);
	Acceleration aGravity = getGravity();
	velocity.updateVelocity(aGravity, time * 2.0);
	updatePosition(aGravity, time);
}

void Ship::launchProjectile(vector<Satellite*> &satellites, double time)
{
	// set direction for projectile to be fired
	Direction fireDirection;
	fireDirection.setRadians(getDirectionAngle());
	
	// projectile should originate at the front
	// of the ship
	Position ptShipFront(pos.getMetersX() + 760.0, pos.getMetersY());

	// projectile velocity should be 9,000 m/s faster than
	// the shipj
	Velocity fireVelocity;
	fireVelocity.setSpeedDirection((velocity.getSpeed() + 9000), getDirection());
	
	// create projectile with ptShipFront, a 0.5 px radius,
	// fireVelocity, and fireDirection
	Projectile *p = new Projectile(ptShipFront, 0.5, fireVelocity, fireDirection);
	
	// add to satellites vector
	satellites.push_back(p);

}

