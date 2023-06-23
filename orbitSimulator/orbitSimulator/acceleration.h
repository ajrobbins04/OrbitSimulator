/***********************************************************************
 * Header File:
 *    Acceleration
 * Author:
 *	  Amber Robbins, Martin Nkala
 * Summary:
 *
 ************************************************************************/

#ifndef acceleration_h
#define acceleration_h

#define EARTH_RADIUS 6378000
#define EARTH_HEIGHT 35786000
#define EARTH_GRAVITY -9.8067

#include <cmath>
#include <iostream>
#include "direction.h"

class TestAcceleration;

using namespace std;

class Acceleration
{
public:
	friend TestAcceleration;
	
	Acceleration(): ddx(0.0), ddy(0.0) {}
	Acceleration(float ddx, float ddy): ddx(ddx), ddy(ddy) {}
	Acceleration(float gravity, const Direction &direction): ddx(0.0), ddy(0.0)
	{
		setAcc(gravity, direction);
	}
	
	void setAcc(float altitude, const Direction &direction);
	void setDDx(float ddx) { this->ddx = ddx; }
	void setDDy(float ddy) { this->ddy = ddy; }
	
	float getDDx() const { return ddx; }
	float getDDy() const { return ddy; }
   
private:
	float ddx; // change in change in x
	float ddy; // change in change in y
   
};

#endif /* acceleration_h */

