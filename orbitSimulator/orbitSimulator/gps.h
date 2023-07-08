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
#include "satelliteFragment.h"
#include "gpsCenter.h"
#include "gpsLeft.h"
#include "gpsRight.h"

class GPS : public Satellite
{
public:
	
	GPS(): Satellite() {}
	GPS(const GPS &rhs) : Satellite(rhs) {}
	GPS(double x, double y, double radius): Satellite(x, y, radius) {}
	GPS(const Position &pos, const Velocity &velocity): Satellite(pos, 12, velocity) {} // radius = 12 px
	
	virtual ~GPS() {}
	
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
	
	virtual void destroy(vector<Satellite*> satellites)
	{
		GPSCenter *gpsCenter = new GPSCenter(*this, 90);
		satellites.push_back(gpsCenter);
		
		GPSLeft *gpsLeft = new GPSLeft(*this, 0);
		satellites.push_back(gpsLeft);
		
		GPSRight *gpsRight = new GPSRight(*this, 180);
		satellites.push_back(gpsRight);
		
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, 330);
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, 250);
		satellites.push_back(sFragment2);
	
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
