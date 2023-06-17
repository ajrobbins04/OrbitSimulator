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
#define M_PI 3.14159265358
#define M_PI_2 1.5707963267
#endif

#include <cmath>

class Direction
{
public:
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
	
	void setRadians(float radians)
	{
		if (radians >= 0.0)
		{
			float rotations = (float)(int)((M_PI + radians) / (M_PI * 2.0));
			radians -= rotations * (M_PI * 2.0);
		}
		else
		{
			float rotations = -(float)(int)((radians - M_PI) / (M_PI * 2.0));
			radians += rotations * (M_PI * 2.0);
		}
	}
	
	void setDxDy(float dx, float dy) { radians = atan2(dx, dy); }
	void setDegrees(float degrees)   { radians = convertToRadians(degrees); }
	
	void setDown()  { radians = M_PI; }
	void setUp()    { radians = 0.0;  }
	void setRight() { radians = M_PI_2; }
	void setLeft()  { radians = -M_PI_2; }
	
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
	
	void reverse() { setRadians(radians + M_PI); }
	
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
