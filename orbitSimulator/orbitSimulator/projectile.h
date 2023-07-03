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
	Projectile(double x, double y, double radius, const Velocity &velocity): Satellite(x, y, radius, velocity) {}
	Projectile(double x, double y, double radius, double dx, double dy): Satellite(x, y, radius, dx, dy) {}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawGPS(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
	
};
#endif
