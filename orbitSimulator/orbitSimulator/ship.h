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
#include "velocity.h"

class TestShip;

class Ship : public Satellite
{
public:
	friend TestShip;
 
	
	Ship() : Satellite(Position(0.0, 0.0), 0.0, Velocity(0.0, 0.0)) {}
	
	Ship(const Position &pos, float radius, const Velocity &velocity) : Satellite(pos, radius, velocity) {}
	
	Ship(float x, float y): Satellite(Position(x, y), 0.0, Velocity(0.0, 0.0)) {}
	Ship(float x, float y, float radius): Satellite(Position(x, y), radius, Velocity(0.0, 0.0)) {}
	Ship(float x, float y, float radius, const Velocity &velocity): Satellite(Position(x, y), radius, velocity) {}
	Ship(float x, float y, float radius, float dx, float dy): Satellite(Position(x, y), radius, Velocity(dx, dy)) {}
 
private:
	Position pos;
	float radius;
	float angularVelocity;
	Direction direction;
	Velocity velocity;
	bool dead;
 
};
#endif
