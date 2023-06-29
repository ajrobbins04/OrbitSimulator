

#ifndef dragon_h
#define dragon_h

#include "satellite.h"

class Dragon : public Satellite
{
public:
	
	Dragon(): Satellite() {}
	Dragon(const Satellite &s, const Direction &d): Satellite(s, d) {}
	Dragon(double x, double y): Satellite(x, y) {}
	Dragon(double x, double y, double radius): Satellite(x, y, radius) {}
	Dragon(const Position &pos, float radius, const Velocity &velocity): Satellite(pos, radius, velocity) {}
	Dragon(double x, double y, double radius, const Velocity &velocity): Satellite(x, y, radius, velocity) {}
	Dragon(double x, double y, double radius, double dx, double dy): Satellite(x, y, radius, dx, dy) {}
	
	virtual void draw(double rotation)
	{
		Position pt;
		ogstream gout(pt);
		
		gout.drawCrewDragon(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* dragon_h */
