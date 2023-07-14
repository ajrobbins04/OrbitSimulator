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
#include "satelliteFragment.h"
#include "starlinkBody.h"
#include "starlinkArray.h"

class Starlink : public Satellite
{
public:
	
	/*Starlink(): Satellite() {
		
		pos.setMeters(0.0, -13020000.0);
		velocity.setDxDy(5800.0, 0.0);
	}*/
	Starlink(): Satellite() {}
	Starlink(const Starlink &rhs) : Satellite(rhs) {}
	Starlink(double x, double y, double radius): Satellite(x, y, radius) {}
	Starlink(const Position &pos, const Velocity &velocity): Satellite(pos, 6, velocity) {} // radius = 6px
	
	virtual ~Starlink() {}
	
	virtual bool isShip()       const { return false; }
	virtual bool isProjectile() const { return false; }
	virtual bool isPiece()      const { return false; }
	virtual bool isFragment()   const { return false; }
	
	virtual void move(double time)
	{
		Acceleration aGravity = getGravity();
			
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
	}

	// breaks into 2 pieces & 2 fragments
	virtual void destroy(vector<Satellite*> &satellites)
	{
		StarlinkBody *sBody = new StarlinkBody(*this, 305);
		satellites.push_back(sBody);
		
		StarlinkArray *sArray = new StarlinkArray(*this, 100);
		satellites.push_back(sArray);
		
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, 50);
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, 240);
		satellites.push_back(sFragment2);
	}
	
	virtual void draw(ogstream & gout)
	{ 
		gout.drawStarlink(getPos(), getAngularVelocity());
	}
	
	
private: // inherits pos, direction, radius, angularVelociy, alive,
		 // velocity, age, and lifeSpan
	
};

#endif /* starlink_h */
