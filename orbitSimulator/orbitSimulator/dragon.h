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
#include "satelliteFragment.h"
#include "dragonCenter.h"
#include "dragonLeft.h"
#include "dragonRight.h"

class Dragon : public Satellite
{
public:
	
	Dragon(): Satellite() {
		
		pos.setMeters(0.0, 8000000.0);
		velocity.setDxDy(-7900.0, 0.0);
	}
	
	Dragon(const Dragon &rhs) : Satellite(rhs) {}
	Dragon(double x, double y, double radius): Satellite(x, y, radius) {}
	Dragon(const Position &pos, const Velocity &velocity): Satellite(pos, radius, velocity) {} // radius = 7px
	
	virtual ~Dragon() {}
	
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
	
	// breaks into 3 pieces & 2 fragments
	virtual void destroy(vector<Satellite*> &satellites)
	{
		DragonCenter *dCenter = new DragonCenter(*this, 160);
		satellites.push_back(dCenter);
		
		DragonLeft *dLeft = new DragonLeft(*this, 85);
		satellites.push_back(dLeft);
		
		DragonRight *dRight = new DragonRight(*this, 200);
		satellites.push_back(dRight);
		
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, 350);
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, 270);
		satellites.push_back(sFragment2);
	}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawCrewDragon(getPos(), getAngularVelocity());
	}

	
private: // inherits pos, direction, radius, angularVelociy, alive,
		 // velocity, age, and lifeSpan
	
};

#endif /* dragon_h */
