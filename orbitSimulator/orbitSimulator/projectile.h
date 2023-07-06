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
	Projectile(const Satellite &s): Satellite(s) {
		setRadius(0.5);
	}
	Projectile(const Position &pos, double radius, const Velocity &velocity): Satellite(pos, radius, velocity) {}
	virtual ~Projectile() {};
	
	void fire(double time);
	
	virtual double getRadius() const { return radius; }
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawProjectile(getPos());
	}
	
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
	
	deque<Position> projectilePath;

};
#endif
