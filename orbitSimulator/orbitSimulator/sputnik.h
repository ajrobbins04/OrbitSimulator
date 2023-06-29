 
#ifndef sputnik_h
#define sputnik_h

#include "satellite.h"

class Sputnik : public Satellite
{
public:
	
	Sputnik(): Satellite() {}
	Sputnik(const Satellite &s, const Direction &d): Satellite(s, d) {}
	Sputnik(double x, double y): Satellite(x, y) {}
	Sputnik(double x, double y, double radius): Satellite(x, y, radius) {}
	Sputnik(const Position &pos, float radius, const Velocity &velocity): Satellite(pos, radius, velocity) {}
	Sputnik(double x, double y, double radius, const Velocity &velocity): Satellite(x, y, radius, velocity) {}
	Sputnik(double x, double y, double radius, double dx, double dy): Satellite(x, y, radius, dx, dy) {}
	
	virtual void draw(double rotation)
	{
		Position pt;
		ogstream gout(pt);
		
		gout.drawSputnik(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* sputnik_h */
