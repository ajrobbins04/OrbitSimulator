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
	
	virtual double getRadius() const
	{
		// left & right solar array pieces each
		// have 8 px. radius
		double solarPiece = pos.convertToMeters(8);
		
		double telescopePiece = pos.convertToMeters(10);
		double computerPiece = pos.convertToMeters(7);
		
		return radius + (solarPiece * 2) + telescopePiece + computerPiece;
	}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawHubble(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* hubble_h */
