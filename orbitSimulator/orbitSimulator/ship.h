/***********************************************************************
 * Header File:
 *    Ship
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *
 ************************************************************************/

#ifndef ship_h
#define ship_h

#include "satellite.h"
#include "uiInteract.h"

class TestShip;

class Ship : public Satellite
{
public:
	friend TestShip;
 
	Ship() : Satellite(Position(0.0, 0.0), 0.0, Velocity(0.0, 0.0)), thrust(false) {}
	
	Ship(const Position &pos, double radius, const Velocity &velocity) : Satellite(pos, radius, velocity), thrust(false) {}
	
	Ship(double x, double y): Satellite(Position(x, y), 0.0, Velocity(0.0, 0.0)), thrust(false) {}
	Ship(double x, double y, double radius): Satellite(Position(x, y), radius, Velocity(0.0, 0.0)), thrust(false) {}
	Ship(double x, double y, double radius, const Velocity &velocity): Satellite(Position(x, y), radius, velocity), thrust(false) {}
	Ship(double x, double y, double radius, double dx, double dy): Satellite(Position(x, y), radius, Velocity(dx, dy)), thrust(false) {}
	
	void setThrust(bool thrust) { this->thrust = thrust; }
	void rotateShip(const Interface *pUi);
	void applyThrust(double thrustAmount, double time);
	bool getThrust() const { return thrust; }
	
	virtual void draw(double frameRate, double rotation) {
		Position pt;
		ogstream gout(pt);
		
		gout.drawShip(getPos(), rotation, getThrust());
	}
	
	void launchProjectile();
 
private:
	// inherits pos, radius, velocity, direction, dead, age, and angularVelocity
	bool thrust;
 
};
#endif
