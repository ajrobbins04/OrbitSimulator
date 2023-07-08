/***********************************************************************
 * Header File:
 *    Projectile
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *
 ************************************************************************/

#ifndef projectile_h
#define projectile_h

#include <deque>
#include "satellite.h"

class Projectile : public Satellite
{
public:
	
	Projectile(): Satellite() {}
	Projectile(const Projectile &rhs) : Satellite(rhs) {
		setRadius(0.5);
	}
	
	Projectile(const Position &pos, double radius, const Velocity &velocity, const Direction &dir):
	Satellite(pos, radius, velocity, dir) {}
	
	virtual ~Projectile() {};
 
	void fire();
	void updateProjectilePath();
	
	virtual void move(double time)
	{
		Acceleration aGravity = getGravity();
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
		
		updateProjectilePath();
		
		increaseAge();
	}
	
	virtual bool isShip()       const { return false;  }
	virtual bool isProjectile() const { return true;   }
	/*virtual double getRadius()  const { return radius; }*/
	
	virtual void destroy()
	{
		
	}
	virtual void draw(double rotation, ogstream & gout)
	{
		{
			for (int i = 0; i < 8; i++)
				gout.drawProjectile(Position(projectilePath[i].getMetersX(), projectilePath[i].getMetersY()));
		}
	}
	
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
	Position projectilePath[8]; // path of the projectile

};
#endif
