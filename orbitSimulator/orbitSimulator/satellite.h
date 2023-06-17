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

#include <cmath>
#include <iostream>
#include "position.h"
#include "velocity.h"
#include "direction.h"
#include "spaceObject.h"

class TestSatellite;

class Satellite : public SpaceObject
{
public:
	friend TestSatellite;
	
	Satellite() : pos(0.0, 0.0), radius(0.0),
	direction(0.0), velocity(0.0, 0.0), dead(false) {}
	
	Satellite(string name, const Position &pos, double radius, Direction &dir, const Velocity &velocity) :
	pos(0.0, 0.0), radius(0.0),
	direction(0.0), velocity(0.0, 0.0), dead(false) {
		
		dir.setDxDy(velocity.getDx(), velocity.getDy());
		
	}
  
	void setPosition(double x, double y)
	{
		pos.setMetersX(x);
		pos.setMetersY(y);
	}

   
	void setVelocity(double dx, double dy)
	{
		velocity.setDx(dx);
		velocity.setDy(dy);
	}
	
	Position getPos() { return pos; }
	double getPosX()  const { return pos.getMetersX(); }
	double getPosY()  const { return pos.getMetersY(); }
	double getAltitude();

	bool isDead() const { return dead; }
	void kill();
	void update();
	void move();
 
//	virtual void draw();
 
	
private:
	Position pos;
	double radius;
	double angularVelocity;
	Direction direction;
	Velocity velocity;
	bool dead;
   
};

#endif /* satellite_h */


