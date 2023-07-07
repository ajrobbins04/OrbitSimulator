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
	virtual ~GPS() {};
	
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
		// have 8 px. radius
		double pieceRadius = pos.convertToMeters(8);
		
		return radius + pieceRadius * 2;
	}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawGPS(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* gps_h */
