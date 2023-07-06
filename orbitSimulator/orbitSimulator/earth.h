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
	virtual ~Earth() {};

	void setRotationSpeed(double amount) { this->rotationSpeed = amount; }
	
	double  getRotationSpeed() const { return rotationSpeed; }
	virtual double getRadius() const { return radius;        }
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawEarth(getPos(), rotation);
	}

private:
	// inherits pos, direction, radius, and alive
	double rotationSpeed;  // amount of rotation per frame

	
};
#endif  
