/***********************************************************************
 * Header File:
 *    Direction
 * Author:
 *
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
	Direction(double degrees): radians(0.0)
	{
		radians = convertToRadians(degrees);
	}
	
	Direction(double dx, double dy): radians(0.0)
	{
		radians = atan2(dx, dy);
	}

	double convertToDegrees(double radians);
	double convertToRadians(double degrees);
	
	void setRadians(double radians)
	{
		if (radians >= 0.0)
		{
			double rotations = (double)(int)((M_PI + radians) / (M_PI * 2.0));
			radians -= rotations * (M_PI * 2.0);
		}
		else
		{
			double rotations = -(double)(int)((radians - M_PI) / (M_PI * 2.0));
			radians += rotations * (M_PI * 2.0);
		}
	}
	
	void setDxDy(double dx, double dy){ radians = atan2(dx, dy); }
	void setDegrees(double degrees)   { radians = convertToRadians(degrees); }
	
	double getDx() const { return sin(radians); }
	double getDy() const { return cos(radians); }
	
	void setDown()  { radians = M_PI; }
	void setUp()    { radians = 0.0;  }
	void setRight() { radians = M_PI_2; }
	void setLeft()  { radians = -M_PI_2; }
	
	void reverse() { setRadians(radians + M_PI); }
	
private:
	double radians;
	
};

#endif
