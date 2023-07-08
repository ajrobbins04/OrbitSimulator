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
	Starlink(const Starlink &rhs) : Satellite(rhs) {}
	Starlink(double x, double y, double radius): Satellite(x, y, radius) {}
	Starlink(const Position &pos, const Velocity &velocity): Satellite(pos, 6, velocity) {} // radius = 6px
	virtual ~Starlink() {};
	
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
	
	/*virtual double getRadius() const
	{
		double rightSolarPiece = pos.convertToMeters(4);
		return radius + rightSolarPiece;
	}*/
	
	virtual void destroy(vector<Satellite*> satellites)
	{
		
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
