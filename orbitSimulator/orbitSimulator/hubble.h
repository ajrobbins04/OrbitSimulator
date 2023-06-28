
#ifndef hubble_h
#define hubble_h

#include "satellite.h"

class TestHubble;

class Hubble : public Satellite
{
public:
	friend TestHubble;
	
	Hubble(): Satellite() {}
	Hubble(const Satellite &s, const Direction &d): Satellite(s, d) {}
	Hubble(double x, double y): Satellite(x, y) {}
	Hubble(double x, double y, double radius): Satellite(x, y, radius) {}
	Hubble(const Position &pos, float radius, const Velocity &velocity): Satellite(pos, radius, velocity) {}
	Hubble(double x, double y, double radius, const Velocity &velocity): Satellite(x, y, radius, velocity) {}
	Hubble(double x, double y, double radius, double dx, double dy): Satellite(x, y, radius, dx, dy) {}
	
	virtual void draw(double frameRate,  double rotation)
	{
		Position pt;
		ogstream gout(pt);
		
		gout.drawHubble(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, dead,
	// angularVelocity and age
};

#endif /* hubble_h */
