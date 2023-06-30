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
	
	Satellite() : SpaceObject(0.0, 0.0), velocity(0.0, 0.0), direction(0.0, 0.0), age(0.0),
	angularVelocity(0.0) {}
	
	Satellite(const Satellite &s, const Direction &d) : SpaceObject(s.pos.getMetersX(), s.pos.getMetersY(), 0.0),
	velocity(s.velocity.getDx(), s.velocity.getDy()), direction(d.getRadians()), age(0.0), angularVelocity(0.0) {}
	
	Satellite(double x, double y): SpaceObject(Position(x, y), 0.0), velocity(0.0, 0.0),
	direction(0.0, 0.0), age(0.0), angularVelocity(0.0)  {}
	
	Satellite(double x, double y, double radius): SpaceObject(Position(x, y), radius), velocity(0.0, 0.0),
	direction(0.0, 0.0), age(0.0), angularVelocity(0.0) {}
	
	Satellite(const Position &pos, float radius, const Velocity &velocity) :
	SpaceObject(pos, radius), velocity(velocity), direction(0.0, 0.0),
	age(0.0), angularVelocity(0.0)  {
		
		direction = velocity.getDirection();
	}
	
	Satellite(double x, double y, double radius, const Velocity &velocity): SpaceObject(Position(x, y), radius), velocity(velocity),
	direction(0.0, 0.0), age(0.0), angularVelocity(0.0)
	{
		direction = velocity.getDirection();
	}
	
	Satellite(double x, double y, double radius, double dx, double dy): SpaceObject(Position(x, y), radius), velocity(dx, dy),
	direction(0.0, 0.0), age(0.0), angularVelocity(0.0)
	{
		direction = velocity.getDirection();
	}
   
	void setVelocity(double dx, double dy)
	{
		velocity.setDx(dx);
		velocity.setDy(dy);
	}
	
	double getAltitude();
	Acceleration getGravity();
	double getAngularVelocity() { return angularVelocity; }
	
	void addKick();
	void updatePosition(const Acceleration &acGravity, double time);
	void move(double time);
	void destroy();
 
	virtual void draw(double rotation, ogstream & gout) = 0;
//  virtual void destroy();
 
	
protected: // inherits pos, radius, and alive
	Velocity velocity;
	Direction direction;
	double angularVelocity;
	double age;
   
};


#endif /* satellite_h */


