#include "ship.h"
/*********************************************
* ROTATE SHIP
*********************************************/
void Ship::input(const Interface *pUI, double time, vector<Satellite*> &satellites)
{
	setPrevDir(getDirectionAngle());
	
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
		launchProjectile(satellites, time);
	 }
 }

void Ship::updateShipFrontPos(const Acceleration &aGravity, double time)
{
	
	double currentAngle = getDirectionAngle();
	double formerAngle = getPrevDirAngle();
	
	if (currentAngle != formerAngle)
	{
		double angleChange = currentAngle - formerAngle;
		double radius = 40000.0;
		double distance = radius * angleChange;
		
		shipFrontPos.setMetersX(pos.getMetersX() + distance * cos(angleChange));
		shipFrontPos.setMetersY(pos.getMetersY() + 760.0 + distance * sin(angleChange));
	}
	
	shipFrontPos.setMetersX(pos.getMetersX());
	shipFrontPos.setMetersY(pos.getMetersY() + 760.0);
}

void Ship::applyThrust(double time)
{
	setThrust(true);
	Acceleration aGravity = getGravity();
	
	// thrust acceleration is 2.0,
	// which lasts for 48 seconds of simulation time
	velocity.updateVelocity(aGravity, time * 2.0);
	updatePosition(aGravity, time);
	updateShipFrontPos(aGravity, time);
}

void Ship::launchProjectile(vector<Satellite*> &satellites, double time)
{

	// set direction for projectile to be fired
	Direction fireDirection;
	fireDirection.setRadians(getDirectionAngle());
	
	// projectile velocity should be 9,000 m/s faster than
	// the ship
	Velocity fireVelocity;
	fireVelocity.setSpeedDirection((velocity.getSpeed() + 9000), fireDirection);
	
	// create projectile with ptShipFront, a 0.5 px radius,
	// fireVelocity, and fireDirection
	Projectile *projectile = new Projectile(shipFrontPos, 0.5, fireVelocity, fireDirection);
	
	projectile->fire();
	
	// add to satellites vector
	satellites.push_back(projectile);

}

