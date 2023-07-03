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
	Projectile(const Satellite &s): Satellite(s) {}
	Projectile(double x, double y): Satellite(x, y) {}
	Projectile(double x, double y, double radius): Satellite(x, y, radius) {}
	Projectile(const Position &pos, float radius, const Velocity &velocity): Satellite(pos, radius, velocity) {}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawProjectile(getPos());
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
	
};
#endif
