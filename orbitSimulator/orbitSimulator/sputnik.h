/***********************************************************************
 * Header File:
 *    Sputnik
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *	  Sputnik is a whole satellite, and thus inherits from
 *	  the Satellite class.
 ************************************************************************/
#ifndef sputnik_h
#define sputnik_h

#include "satellite.h"

class Sputnik : public Satellite
{
public:
	
	Sputnik(): Satellite() {}
	Sputnik(const Satellite &s): Satellite(s) {}
	Sputnik(double x, double y): Satellite(x, y) {}
	Sputnik(double x, double y, double radius): Satellite(x, y, radius) {}
	Sputnik(const Position &pos, float radius, const Velocity &velocity): Satellite(pos, radius, velocity) {}

	virtual void draw(double rotation, ogstream & gout)
	{ 
		gout.drawSputnik(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* sputnik_h */
