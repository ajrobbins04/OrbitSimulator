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
#include "satelliteFragment.h"

class Sputnik : public Satellite
{
public:
	
	Sputnik(): Satellite() {}
	Sputnik(const Sputnik &rhs) : Satellite(rhs) {}
	Sputnik(double x, double y, double radius): Satellite(x, y, radius) {}
	Sputnik(const Position &pos, const Velocity &velocity): Satellite(pos, 4, velocity) {} // radius = 4px
	
	virtual ~Sputnik() {}
	
	virtual bool isShip()       const { return false;  }
	virtual bool isProjectile() const { return false;  }
	
	virtual void move(double time)
	{
		Position posPrev = getPos();
		Acceleration aGravity = getGravity();
			
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
		updateDirection(posPrev, time);
	}
	
	virtual void destroy(vector<Satellite*> satellites)
	{
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, 330);
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, 250);
		satellites.push_back(sFragment2);
		
		SatelliteFragment *sFragment3 = new SatelliteFragment(*this, 130);
		satellites.push_back(sFragment3);
		
		SatelliteFragment *sFragment4 = new SatelliteFragment(*this, 90);
		satellites.push_back(sFragment4);

	}
	
	virtual void draw(double rotation, ogstream & gout)
	{ 
		gout.drawSputnik(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* sputnik_h */
