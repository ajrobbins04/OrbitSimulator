/***********************************************************************
 * Header File:
 *    GPS
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *	  GPS is a whole satellite, and thus inherits from
 *	  the Satellite class.
 ************************************************************************/

#ifndef gps_h
#define gps_h

#include "satellite.h"

class GPS : public Satellite
{
public:
	
	GPS(): Satellite() {}
	GPS(const Satellite &s): Satellite(s) {}
	GPS(double x, double y): Satellite(x, y) {}
	GPS(double x, double y, double radius): Satellite(x, y, radius) {}
	GPS(const Position &pos, float radius, const Velocity &velocity): Satellite(pos, radius, velocity) {}
	GPS(double x, double y, double radius, const Velocity &velocity): Satellite(x, y, radius, velocity) {}
	GPS(double x, double y, double radius, double dx, double dy): Satellite(x, y, radius, dx, dy) {}
	
	virtual void draw(double rotation, ogstream & gout)
	{ 
		gout.drawGPS(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* gps_h */
