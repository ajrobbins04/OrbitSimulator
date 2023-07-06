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
	Direction fireDirection;
 
	fireDirection.setRadians(getDirectionAngle() * -1 + (M_PI / 2.0));
	Projectile *p = new Projectile(getPos(), 1, getVelocity());
	satellites.push_back(p);
	p->fire(time);
}

