 

#ifndef starlink_h
#define starlink_h

#include "satellite.h"

class Starlink : public Satellite
{
public:
	
	Starlink(): Satellite() {}
	Starlink(const Satellite &s, const Direction &d): Satellite(s, d) {}
	Starlink(double x, double y): Satellite(x, y) {}
	Starlink(double x, double y, double radius): Satellite(x, y, radius) {}
	Starlink(const Position &pos, float radius, const Velocity &velocity): Satellite(pos, radius, velocity) {}
	Starlink(double x, double y, double radius, const Velocity &velocity): Satellite(x, y, radius, velocity) {}
	Starlink(double x, double y, double radius, double dx, double dy): Satellite(x, y, radius, dx, dy) {}
	
	virtual void draw(double frameRate,  double rotation)
	{
		Position pt;
		ogstream gout(pt);
		
		gout.drawStarlink(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, dead,
	// angularVelocity and age
};

#endif /* starlink_h */
