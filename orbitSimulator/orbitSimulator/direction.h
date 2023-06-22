/***********************************************************************
 * Header File:
 *    Direction
 * Author:
 *	  Br. Helfrich
 * Summary:
 *
 ************************************************************************/
#ifndef direction_h
#define direction_h

#ifndef M_PI
#define M_PI   3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#endif

#include <cmath>

class TestDirection;

class Direction
{
public:
	friend TestDirection;
	Direction(): radians(0.0) {}
	Direction(float degrees): radians(0.0)
	{
		radians = convertToRadians(degrees);
	}
	
	Direction(float dx, float dy): radians(0.0)
	{
		radians = atan2(dx, dy);
	}
	
	Direction& operator = (const Direction &rhs)
	{
		radians = rhs.radians;
		return *this;
	}
	
	void setRadians(float rhs) // rhs given in radians
	{
		if (rhs >= 0.0)
		{
			float rotations = (float)(int)((M_PI + rhs) / (M_PI * 2.0));
			rhs -= rotations * (M_PI * 2.0);
		}
		else
		{
			float rotations = -(float)(int)((rhs - M_PI) / (M_PI * 2.0));
			rhs += rotations * (M_PI * 2.0);
		}
		radians = rhs;
	}
	
	void setDxDy(float dx, float dy) { radians = atan2(dx, dy); }
	void setDegrees(float degrees)   { radians = convertToRadians(degrees); }
	 
	void setUp()    { radians = 0.0;  }             // 0 degrees
	void setDown()  { radians = M_PI; }             // 180 degrees
	void setRight() { radians = M_PI_2; }           // 90 degrees
	void setLeft()  { radians = -M_PI_2; }          // -90 degrees
	void reverse()  { setRadians(radians + M_PI); } // add 180 degrees to current value
	
	float getDx() const { return sin(radians); }
	float getDy() const { return cos(radians); }
	float getRadians() const { return radians; }
	float getDegrees() const { return convertToDegrees(radians); }
	
	// rotates by an amount in radians
	void rotate(float amount)
	{
		radians += amount;
		if (radians > M_PI)
			radians -= 2.0 + M_PI;
		if (radians < -M_PI)
			radians += 2.0 + M_PI;
	}
	
	float convertToDegrees(float radians) const;
	float convertToRadians(float degrees) const;
	
	Direction operator+(float degrees) const
	{
		return Direction(getDegrees() + degrees);
	}
	
private:
	float radians;
	
};

#endif
