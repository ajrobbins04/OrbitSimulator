/***********************************************************************
 * Header File:
 *    Starlink
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *	  Starlink is a whole satellite, and thus inherits from
 *	  the Satellite class.
 ************************************************************************/
#ifndef starlink_h
#define starlink_h

#include "satellite.h"

class Starlink : public Satellite
{
public:
	
	Starlink(): Satellite() {}
	Starlink(const Satellite &s): Satellite(s) {}
	Starlink(double x, double y): Satellite(x, y) {}
	Starlink(double x, double y, double radius): Satellite(x, y, radius) {}
	Starlink(const Position &pos, float radius, const Velocity &velocity): Satellite(pos, radius, velocity) {}
	virtual ~Starlink() {};
	
	virtual double getRadius() const
	{
		double rightSolarPiece = pos.convertToMeters(4);
		return radius + rightSolarPiece;
	}
	
	virtual void draw(double rotation, ogstream & gout)
	{ 
		gout.drawStarlink(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* starlink_h */
