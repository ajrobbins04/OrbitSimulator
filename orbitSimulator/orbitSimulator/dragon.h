/***********************************************************************
 * Header File:
 *    Dragon
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *	  Dragon is a whole satellite, and thus inherits from
 *	  the Satellite class.
 ************************************************************************/
#ifndef dragon_h
#define dragon_h

#include "satellite.h"

class Dragon : public Satellite
{
public:
	
	Dragon(): Satellite() {}
	Dragon(const Satellite &s): Satellite(s) {}
	Dragon(double x, double y, double radius): Satellite(x, y, radius) {}
	Dragon(const Position &pos, const Velocity &velocity): Satellite(pos, radius, velocity) {} // radius = 7px
	virtual ~Dragon() {};
	
	virtual bool isShip()       const { return false; }
	virtual bool isProjectile() const { return false; }
	
	virtual void move(double time)
	{
		Position posPrev = getPos();
		Acceleration aGravity = getGravity();
			
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
		updateDirection(posPrev, time);
	}
	
	virtual double getRadius() const
	{
		// left & right solar array pieces each
		// have 6 px. radius
		double solarPiece = pos.convertToMeters(6);
		
		return radius + (solarPiece * 2);
	}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawCrewDragon(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* dragon_h */
