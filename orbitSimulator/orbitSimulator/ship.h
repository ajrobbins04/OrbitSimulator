/***********************************************************************
 * Header File:
 *    Ship
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *	  Ship inherits from the satellite class, but it includes
 *	  additional functionalities.
 ************************************************************************/

#ifndef ship_h
#define ship_h

#include "uiInteract.h"
#include "satellite.h"
#include "projectile.h"

class TestShip;

class Ship : public Satellite
{
public:
	friend TestShip;
 
	Ship() : Satellite(Position(0.0, 0.0), 0.0, Velocity(0.0, 0.0)), thrust(false) {}
	
	Ship(const Position &pos, double radius, const Velocity &velocity) : Satellite(pos, radius, velocity), thrust(false) {}
	
	Ship(double x, double y): Satellite(Position(x, y), 0.0, Velocity(0.0, 0.0)), thrust(false) {}
	Ship(double x, double y, double radius): Satellite(Position(x, y), radius, Velocity(0.0, 0.0)), thrust(false) {}
	
	void setThrust(bool thrust) { this->thrust = thrust; }
	void input(const Interface *pUI, double time, vector<Satellite*> satellites);
	void applyThrust(double thrustAmount, double time);
	bool getThrust() const { return thrust; }
	
	void launchProjectile(vector<Satellite*> satellites, double time);

	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawShip(getPos(), rotation, getThrust());
	}
 
private:
	// inherits pos, radius, velocity, direction, alive, age, and angularVelocity
	bool thrust;
 
};
#endif
