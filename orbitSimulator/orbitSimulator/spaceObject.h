/***********************************************************************
 * Header File:
 *    Space Object
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *
 ************************************************************************/

#ifndef spaceObject_h
#define spaceObject_h

#include <cmath>
#include <iostream>
#include <string>
#include "position.h"
#include "direction.h"

using namespace std;

class SpaceObject
{
public:
	SpaceObject(): name("spaceObject"), pos(0.0, 0.0), radius(0.0), direction(0.0) {}
	
	SpaceObject(string name, const Position &pos, double radius, const Direction &direction):
	name("spaceObject"), pos(0.0, 0.0), radius(0.0), direction(0.0)
	{
		initialize(name, pos, radius, direction);
	}
	
	void initialize(string name, Position pos, double radius, Direction direction)
	{
		assert(name != " " || name != "");
		setName(name);
		
		// Radius given in pixels. Must convert to meters.
		assert(radius > 0);
		double radiusMeters = pos.convertToMeters(radius);
		setRadius(radiusMeters);
	}
	
	void setName(string name)     { this->name = name;     }
	void setRadius(double radius) { this->radius = radius; }
	
	double getRadius()     const { return radius; }
	Position getPosition() const { return pos;    }

	
private:
	string name;
	Position pos;
	double radius;
	Direction direction;

};
 
#endif
