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
	
	Projectile(): Satellite() {}
	Projectile(const Projectile &rhs) : Satellite(rhs) {
		setRadius(0.5);
	}
	
	Projectile(const Position &pos, const Velocity &velocity, const Direction &dir):
	Satellite(pos, 0.5, velocity, dir) {} // radius = 0.5 px.
	
	virtual ~Projectile() {}
 
	void fire();
	void updateProjectilePath();
	
	virtual bool isShip()       const { return false; }
	virtual bool isProjectile() const { return true;  }
	virtual bool isPiece()      const { return false; }
	virtual bool isFragment()   const { return false; }
	
	virtual void move(double time)
	{
		Acceleration aGravity = getGravity();
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);

		increaseAge();
	}
	
	virtual void destroy(vector<Satellite*> satellites) { kill(); }
	virtual void draw(double rotation, ogstream & gout) { gout.drawProjectile(getPos()); }
	
		
private:


};
#endif
