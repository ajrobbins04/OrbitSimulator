 

#ifndef gps_h
#define gps_h

#include "satellite.h"

class GPS : public Satellite
{
public:
	
	GPS(): Satellite() {}
	GPS(const Satellite &s, const Direction &d): Satellite(s, d) {}
	GPS(double x, double y): Satellite(x, y) {}
	GPS(double x, double y, double radius): Satellite(x, y, radius) {}
	GPS(const Position &pos, float radius, const Velocity &velocity): Satellite(pos, radius, velocity) {}
	GPS(double x, double y, double radius, const Velocity &velocity): Satellite(x, y, radius, velocity) {}
	GPS(double x, double y, double radius, double dx, double dy): Satellite(x, y, radius, dx, dy) {}
	
	virtual void draw(double rotation)
	{
		Position pt;
		ogstream gout(pt);
		
		gout.drawGPS(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* gps_h */
