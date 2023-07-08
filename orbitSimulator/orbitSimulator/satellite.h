/***********************************************************************
 * Header File:
 *    Satellite
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *	Represent a whole satellite object in the orbit simulator. A satellite
 *	object can be one of the satellites orbiting the earth, the ship that
 *	shoots projectile, or the projectile itself.
 ************************************************************************/
#ifndef satellite_h
#define satellite_h
 
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "velocity.h"
#include "spaceObject.h"

const double earthRadius = 6378000;

class TestSatellite;

class Satellite : public SpaceObject
{
public:
	friend TestSatellite;
	
	Satellite() : SpaceObject(0.0, 0.0), velocity(0.0, 0.0), age(0.0), angularVelocity(0.0) {}
	
	Satellite(const Satellite &rhs) : SpaceObject(rhs), velocity(rhs.getVelocity()),
	angularVelocity(rhs.getAngularVelocity()), age(rhs.getAge()) {}
	
	Satellite(const Satellite &s, const Direction &dir) : SpaceObject(s.pos.getMetersX(), s.pos.getMetersY(), 0.0, Direction(dir.getRadians())),
	velocity(s.velocity.getDx(), s.velocity.getDy()), age(0.0), angularVelocity(0.0) {}
	
	Satellite(double x, double y): SpaceObject(Position(x, y), 0.0), velocity(0.0, 0.0),
	age(0.0), angularVelocity(0.0)  {}
	
	Satellite(double x, double y, double radius): SpaceObject(Position(x, y), radius), velocity(0.0, 0.0),
	age(0.0), angularVelocity(0.0) {}
	
	Satellite(const Position &pos, float radius, const Velocity &velocity) :
	SpaceObject(pos, radius), velocity(velocity), age(0.0), angularVelocity(0.0)  {}
	
	Satellite(const Position &pos, float radius, const Velocity &velocity, const Direction &dir) :
	SpaceObject(pos, radius, dir), velocity(velocity), age(0.0), angularVelocity(0.0)  {}
	
	virtual ~Satellite() {}
	
	void setVelocity(double dx, double dy)
	{
		velocity.setDx(dx);
		velocity.setDy(dy);
	}
	
	double getAltitude();
	Acceleration getGravity();
	
	Velocity getVelocity()      const { return velocity;        }
	double getAngularVelocity() const { return angularVelocity; }
	
	void updateDirection(const Position &posPrev, double time);
	void updatePosition(const Acceleration &acGravity, double time);
	
	void increaseAge()     { age += 1;   }
	double getAge() const  { return age; }
	
	virtual bool isShip() const = 0;
	virtual bool isProjectile() const = 0;
	virtual void move(double time) = 0;
	virtual void destroy(vector<Satellite*> satellites) = 0;
	virtual void draw(double rotation, ogstream & gout) = 0;
 
 
	
protected: // inherits pos, direction, radius, and alive
	Velocity velocity;
	double angularVelocity;
	double age;
   
};


#endif /* satellite_h */


