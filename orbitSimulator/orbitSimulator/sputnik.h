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
	
	/*Sputnik(): Satellite() {
		
		pos.setMeters(-36515095.13, 21082000.0);
		velocity.setDxDy(2050.0, 2684.68);
	}*/
	Sputnik(): Satellite() {}
	Sputnik(const Sputnik &rhs) : Satellite(rhs) {}
	Sputnik(double x, double y, double radius): Satellite(x, y, radius) {}
	Sputnik(const Position &pos, const Velocity &velocity): Satellite(pos, 4, velocity) {} // radius = 4px
	
	virtual ~Sputnik() {}
	
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
	
	// breaks into 4 fragments
	virtual void destroy(vector<Satellite*> &satellites)
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
	
	virtual void draw(ogstream & gout)
	{ 
		gout.drawSputnik(getPos(), getAngularVelocity());
	}
	
	
private: // inherits pos, direction, radius, angularVelociy, alive,
		 // velocity, age, and lifeSpan
	
};

#endif /* sputnik_h */
