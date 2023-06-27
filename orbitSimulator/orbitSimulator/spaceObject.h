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

using namespace std;

class SpaceObject
{
public:
	SpaceObject(): pos(0.0, 0.0), radius(0.0) {}
	
	SpaceObject(const Position &pos, double radius):
	pos(pos), radius(0.0)
	{
		// Earth's radius = 6378000 meters
		// All other radius values are given in pixels, and must be converted to meters
		if (radius != 6378000)
		{
			// fragments have smallest radius of 2 px
			// GPS Satellite has largest radius of 12 px
		//	assert(radius >= 2 && radius <= 12);
			double radiusMeters = pos.convertToMeters(radius);
			setRadius(radiusMeters);
		}
	}
	
	SpaceObject(double x, double y): pos(x, y), radius(0.0) {}
	SpaceObject(double x, double y, double radius): pos(x, y), radius(0.0)
	{
		if (radius != 6378000)
		{
			//assert(radius >= 2 && radius <= 12);
			double radiusMeters = pos.convertToMeters(radius);
			setRadius(radiusMeters);
		}
	}

	void setRadius(double radius) { this->radius = radius; }
	void setPosition(double x, double y)
	{
		pos.setMetersX(x);
		pos.setMetersY(y);
	}

//	virtual void draw() = 0;
//	virtual void move(int time);
	
	double getRadius()      const { return radius; }
	Position getPosition() const { return pos;    }

	Position getPos() { return pos; }
	double getPosX()  const { return pos.getMetersX(); }
	double getPosY()  const { return pos.getMetersY(); }
	
protected:
	Position pos;
	double radius;

};
 
#endif
