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

class TestShip;

class Ship : public Satellite
{
public:
	friend TestShip;
 
	Ship() : Satellite(Position(0.0, 0.0), 0.0, Velocity(0.0, 0.0)), thrust(false) {}
	
	Ship(const Position &pos, float radius, const Velocity &velocity) : Satellite(pos, radius, velocity), thrust(false) {}
	
	Ship(float x, float y): Satellite(Position(x, y), 0.0, Velocity(0.0, 0.0)), thrust(false) {}
	Ship(float x, float y, float radius): Satellite(Position(x, y), radius, Velocity(0.0, 0.0)), thrust(false) {}
	Ship(float x, float y, float radius, const Velocity &velocity): Satellite(Position(x, y), radius, velocity), thrust(false) {}
	Ship(float x, float y, float radius, float dx, float dy): Satellite(Position(x, y), radius, Velocity(dx, dy)), thrust(false) {}
	
	void setThrust(bool thrust) { this->thrust = thrust; }
	void rotateShip(float amount);
	void applyThrust(float thrustAmount, float time);
	
	void launchProjectile();
 
private:
	// inherits pos, radius, velocity, direction, aGravity, dead, and angularVelocity
	bool thrust;
 
};
#endif
