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
#define M_PI    3.14159265358979323846
#define M_PI_2  1.57079632679489661923
#endif

#include <cmath>

class TestDirection;

class Direction
{
public:
	friend TestDirection;
	Direction(): radians(0.0) {}
	Direction(double degrees): radians(0.0)
	{
		radians = convertToRadians(degrees);
	}
	
	Direction(double dx, double dy): radians(0.0)
	{
		radians = atan2(dx, dy);
	}
	
	Direction& operator = (const Direction &rhs)
	{
		radians = rhs.radians;
		return *this;
	}
	
	void setRadians(double rhs) // rhs given in radians
	{
		if (rhs >= 0.0)
		{
			double rotations = (double)(int)((M_PI + rhs) / (M_PI * 2.0));
			rhs -= rotations * (M_PI * 2.0);
		}
		else
		{
			double rotations = -(double)(int)((rhs - M_PI) / (M_PI * 2.0));
			rhs += rotations * (M_PI * 2.0);
		}
		radians = rhs;
	}
	
	void setDxDy(double dx, double dy) { radians = atan2(dx, dy);             }
	void setDegrees(double degrees)    { radians = convertToRadians(degrees); }
	 
	void setUp()    { radians = 0.0;  }             // 0 degrees
	void setDown()  { radians = M_PI; }             // 180 degrees
	void setRight() { radians = M_PI_2; }           // 90 degrees
	void setLeft()  { radians = -M_PI_2; }          // -90 degrees
	void reverse()  { setRadians(radians + M_PI); } // add 180 degrees to current value
	
	double getDx() const { return sin(radians); }
	double getDy() const { return cos(radians); }

	double getRadians() const { return radians; }
	double getDegrees() const { return convertToDegrees(radians); }
	
	void update(double dx, double dy)
	{
		double angleDifference = atan2(dx, dy);
		rotate(angleDifference);
	}
	
	// rotates by an amount in radians
	void rotate(double amount)
	{
		radians += amount;
		if (radians > M_PI)
			radians -= 2.0 + M_PI;
		if (radians < -M_PI)
			radians += 2.0 + M_PI;
	}
	
	double convertToDegrees(double radians) const;
	double convertToRadians(double degrees) const;
	
	Direction operator+(double degrees) const
	{
		return Direction(getDegrees() + degrees);
	}
	
private:
	double radians;
	
};

#endif
