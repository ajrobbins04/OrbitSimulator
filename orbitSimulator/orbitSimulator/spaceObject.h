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
	
	void initialize(string name, Position pos, double radiusPixels, Direction direction)
	{
		assert(name != " " || name != "");
		setName(name);
		
		
		// Earth's radius = 6378000 meters
		// All other radius values are given in pixels, and must be converted to meters
		if (radius != 6378000)
		{
			// fragments have smallest radius of 2 px
			// GPS Satellite has largest radius of 12 px
			assert(radius >= 2 && radius <= 12);
			double radiusMeters = pos.convertToMeters(radius);
			setRadius(radiusMeters);
		}
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
