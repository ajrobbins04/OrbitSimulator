/***********************************************************************
 * Header File:
 *    Hubble
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *	  Sputnik is a whole satellite, and thus inherits from
 *	  the Satellite class.
 ************************************************************************/
#ifndef hubble_h
#define hubble_h

#include "satellite.h"

class TestHubble;

class Hubble : public Satellite
{
public:
	friend TestHubble;
	
	Hubble(): Satellite() {}
	Hubble(const Satellite &s, const Direction &d): Satellite(s, d) {}
	Hubble(double x, double y): Satellite(x, y) {}
	Hubble(double x, double y, double radius): Satellite(x, y, radius) {}
	Hubble(const Position &pos, float radius, const Velocity &velocity): Satellite(pos, radius, velocity) {}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawHubble(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* hubble_h */
