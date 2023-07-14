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

#include "satellite.h"

class Projectile : public Satellite
{
public:
	
	Projectile() : Satellite() {}
	Projectile(const Projectile &rhs) : Satellite(rhs)
	{
		setRadius(0.5);    
		setLifeSpan(70.0);
		setInvisible(true);
	}
	
	Projectile(const Position &pos, const Velocity &velocity, const Direction &dir):
	Satellite(pos, 0.5, velocity, dir)
	{
		setLifeSpan(70.0);
		setInvisible(true);
	}
	
	virtual ~Projectile() {}
 
	void fire();
	
	virtual bool isShip()       const { return false; }
	virtual bool isProjectile() const { return true;  }
	virtual bool isPiece()      const { return false; }
	virtual bool isFragment()   const { return false; }
	
	virtual void move(double time)
	{
		if (age >= 3)
			setInvisible(false);
		
		Acceleration aGravity = getGravity();
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);

		increaseAge();
	}
	
	virtual void destroy(list<Satellite*> &satellites) {}
	virtual void draw(ogstream & gout) { gout.drawProjectile(getPos()); }
	
		
private: // inherits pos, direction, radius, angularVelociy, alive,
		 // velocity, age, and lifeSpan

};
#endif
