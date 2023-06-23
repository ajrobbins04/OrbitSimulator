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
	
	SpaceObject(const Position &pos, float radius):
	pos(pos), radius(0.0)
	{
		// Earth's radius = 6378000 meters
		// All other radius values are given in pixels, and must be converted to meters
		if (radius != 6378000)
		{
			// fragments have smallest radius of 2 px
			// GPS Satellite has largest radius of 12 px
		//	assert(radius >= 2 && radius <= 12);
			float radiusMeters = pos.convertToMeters(radius);
			setRadius(radiusMeters);
		}
	}
	
	SpaceObject(float x, float y): pos(x, y), radius(0.0) {}
	SpaceObject(float x, float y, float radius): pos(x, y), radius(0.0)
	{
		if (radius != 6378000)
		{
			//assert(radius >= 2 && radius <= 12);
			float radiusMeters = pos.convertToMeters(radius);
			setRadius(radiusMeters);
		}
	}

	void setRadius(float radius) { this->radius = radius; }
	void setPosition(float x, float y)
	{
		pos.setMetersX(x);
		pos.setMetersY(y);
	}

//	virtual void draw() = 0;
//	virtual void move(int time);
	
	float getRadius()      const { return radius; }
	Position getPosition() const { return pos;    }

	Position getPos() { return pos; }
	float getPosX()  const { return pos.getMetersX(); }
	float getPosY()  const { return pos.getMetersY(); }
	
protected:
	Position pos;
	float radius;

};
 
#endif
