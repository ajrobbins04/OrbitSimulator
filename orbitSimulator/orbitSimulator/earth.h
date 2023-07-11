/***********************************************************************
 * Header File:
 *    Earth
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *
 ************************************************************************/

#ifndef earth_h
#define earth_h

#include "spaceObject.h"


class Earth : public SpaceObject
{
public:
	
	Earth() : SpaceObject(0.0, 0.0, 6378000.0) {}
	Earth(double x, double y, double radius) : SpaceObject(x, y, radius) {}
	
	virtual ~Earth() {}

	virtual void draw(ogstream & gout)
	{
		gout.drawEarth(getPos(), getDirectionAngle());
	}
	
private: // inherits pos, direction, radius, angularVelociy, and alive
	
};
#endif  
