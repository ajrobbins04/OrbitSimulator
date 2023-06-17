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
	Direction(float degrees): radians(0.0)
	{
		radians = convertToRadians(degrees);
	}
	
	Direction(float dx, float dy): radians(0.0)
	{
		radians = atan2(dx, dy);
	}

	float convertToDegrees(float radians);
	float convertToRadians(float degrees);
	
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
	
	float getDx() const { return sin(radians); }
	float getDy() const { return cos(radians); }
	
	void setDown()  { radians = M_PI; }
	void setUp()    { radians = 0.0;  }
	void setRight() { radians = M_PI_2; }
	void setLeft()  { radians = -M_PI_2; }
	
	void reverse() { setRadians(radians + M_PI); }
	
private:
	float radians;
	
};

#endif
