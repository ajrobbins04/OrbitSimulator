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
	
	Earth() : SpaceObject(0.0, 0.0, 0.0) {}
	Earth(double x, double y, double radius) : SpaceObject(x, y, radius) {}
	 
	virtual void draw(double frameRate, double rotation)
	{
		Position pt;
		ogstream gout(pt);
		
		/*double angleEarth = frameRate;
		angleEarth -= -0.01;*/
		gout.drawEarth(getPosition(), rotation);
	}

private:
	// inherits pos and radius
	
};
#endif  
