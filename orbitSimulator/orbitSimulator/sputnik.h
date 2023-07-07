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
	Sputnik(double x, double y, double radius): Satellite(x, y, radius) {}
	Sputnik(const Position &pos, const Velocity &velocity): Satellite(pos, 4, velocity) {} // radius = 4px
	virtual ~Sputnik() {};
	
	virtual void move(double time)
	{
		Position posPrev = getPos();
		Acceleration aGravity = getGravity();
			
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
		updateDirection(posPrev, time);
	}
	
	virtual bool isShip()       const { return false;  }
	virtual bool isProjectile() const { return false;  }
	virtual double getRadius()  const { return radius; }
	
	virtual void draw(double rotation, ogstream & gout)
	{ 
		gout.drawSputnik(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* sputnik_h */
