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

#include <iostream>
#include <string>
#include "position.h"
#include "direction.h"
#include "uiDraw.h"  

using namespace std;

class SpaceObject
{
public:
	SpaceObject(): pos(0.0, 0.0), radius(0.0), direction(0.0), alive(true){}
	
	SpaceObject(const Position &pos, double radius):
	pos(pos), radius(0.0), direction(0.0), alive(true)
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

	SpaceObject(double x, double y): pos(x, y), radius(0.0), direction(0.0), alive(true) {}
	
	SpaceObject(double x, double y, double radius): pos(x, y), radius(0.0),
	direction(0.0), alive(true)
	{
		if (radius != 6378000)
		{
			//assert(radius >= 2 && radius <= 12);
			double radiusMeters = pos.convertToMeters(radius);
			setRadius(radiusMeters);
		}
	}
	
	SpaceObject(double x, double y, double radius, const Direction &dir): pos(x, y), radius(0.0),
	direction(dir), alive(true)
	{
		if (radius != 6378000)
		{
			//assert(radius >= 2 && radius <= 12);
			double radiusMeters = pos.convertToMeters(radius);
			setRadius(radiusMeters);
		}
	}

	void setRadius(double radius)         { this->radius = radius;               }
	void setDirection(double radians)     { this->direction.setRadians(radians); }
	void setDirection(const Direction &d) { this->direction = d;                 }
	void setPosition(double x, double y)
	{
		pos.setMetersX(x);
		pos.setMetersY(y);
	}

	void kill()                                  { this->alive = false;                    }
	void adjustDirection(double amount)  { this->direction.rotate(amount); }
	
	Position getPos()          const { return pos;              }
	Direction getDirection()   const { return direction;        }
	double getPosX()           const { return pos.getMetersX(); }
	double getPosY()           const { return pos.getMetersY(); }
	double getDirectionAngle() const { return direction.getRadians(); }
	bool isAlive()             const { return alive;                  }
	
	virtual double getRadius() const = 0;
	virtual void draw(double rotation, ogstream & gout) = 0;
//	virtual void move(int time);
	
protected:
	Position pos;
	Direction direction;
	double radius;
	bool alive;

};
 
#endif
