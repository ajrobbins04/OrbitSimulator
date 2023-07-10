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

/*********************************************
* UPDATE SHIP FRONT POSITION
*********************************************/
void Ship::updateShipFrontPos(const Acceleration &aGravity, double time)
{
	double distance = 19.0 * 40.0;

	shipFrontPos.setMetersX(pos.getMetersX() + distance * sin(direction.getDegrees()));
	shipFrontPos.setMetersY(pos.getMetersY() + distance * cos(direction.getDegrees()));

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
	updateShipFrontPos(aGravity, time);
}

/*********************************************
* LAUNCH PROJECTILE
*********************************************/
void Ship::launchProjectile(vector<Satellite*> &satellites, double time)
{

	// set direction for projectile to be fired
	Direction fireDirection;
	fireDirection.setRadians(getDirectionAngle());
	
	// projectile velocity should be 9,000 m/s faster than
	// the ship
	Velocity fireVelocity;
	fireVelocity.setSpeedDirection((velocity.getSpeed() + 9000), fireDirection);
	
	Position firePos(getPos());
	//firePos.addPixelsY(19.0);
	
	// create projectile with ptShipFront, a 0.5 px radius,
	// fireVelocity, and fireDirection
	Projectile *projectile = new Projectile(firePos, fireVelocity, fireDirection);
	
	// add to satellites vector
	satellites.push_back(projectile);

}

