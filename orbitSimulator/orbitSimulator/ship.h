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
	
	Ship() : pos(0.0, 0.0), radius(0.0),
	direction(0.0), velocity(0.0, 0.0), dead(false) {}
	
	Ship(const Position &pos, float radius, Direction &dir, const Velocity &velocity) :
	pos(0.0, 0.0), radius(0.0),
	direction(0.0), velocity(0.0, 0.0), dead(false) {
		
		dir.setDxDy(velocity.getDx(), velocity.getDy());
		
	}
	Ship(float x, float y): pos(x, y), radius(0.0),
	direction(0.0), velocity(0.0, 0.0), dead(false) {}
 
  
 
private:
	Position pos;
	float radius;
	float angularVelocity;
	Direction direction;
	Velocity velocity;
	bool dead;
 
};
#endif
