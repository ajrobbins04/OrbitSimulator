/***********************************************************************
 * Header File:
 *    Satellite
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *
 ************************************************************************/
#ifndef satellite_h
#define satellite_h
 
#define TIME 48
#define EARTH_RADIUS 6378000
#define EARTH_GRAVITY -9.8067

#include <cmath>
#include <iostream>
#include <iomanip>
#include "velocity.h"
#include "direction.h"
#include "spaceObject.h"

class TestSatellite;

class Satellite : public SpaceObject
{
public:
	friend TestSatellite;
	
	Satellite() : SpaceObject(0.0, 0.0), velocity(0.0, 0.0), direction(0.0, 0.0), dead(false) {}
	
	Satellite(float x, float y): SpaceObject(Position(x, y), 0.0), velocity(0.0, 0.0), direction(0.0, 0.0), dead(false) {}
	
	Satellite(float x, float y, float radius): SpaceObject(Position(x, y), radius), velocity(0.0, 0.0), direction(0.0, 0.0), dead(false) {}
	
	Satellite(const Position &pos, float radius, const Velocity &velocity) :
	SpaceObject(pos, radius), velocity(velocity), direction(0.0, 0.0), dead(false) {
		
		direction = velocity.getDirection();
	}
	
	Satellite(float x, float y, float radius, const Velocity &velocity): SpaceObject(Position(x, y), radius), velocity(velocity),
	direction(0.0, 0.0), dead(false)
	{
		direction = velocity.getDirection();
	}
	
	Satellite(float x, float y, float radius, float dx, float dy): SpaceObject(Position(x, y), radius), velocity(dx, dy),
	direction(0.0, 0.0), dead(false)
	{
		direction = velocity.getDirection();
	}
   
	void setVelocity(float dx, float dy)
	{
		velocity.setDx(dx);
		velocity.setDy(dy);
	}
	
	float getAltitude();
	Acceleration getGravity();
	bool isDead() const { return dead; }
	void kill();
	void addKick();
	void updatePosition();
	void move();
	void destroy();
 
//	virtual void draw();
//  virtual void destroy();
 
	
protected: // inherits pos and radius
	Velocity velocity;
	Direction direction;
	bool dead;
	float angularVelocity;
   
};


#endif /* satellite_h */


