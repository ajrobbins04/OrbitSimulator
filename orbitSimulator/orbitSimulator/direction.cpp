#include "direction.h"

/*********************************************
 * CONVERT TO RADIANS
 * Converts a value in degrees to radians.
 *********************************************/
float Direction::convertToRadians(float degrees)
{
	return (degrees / 360.0) * (2.0 * M_PI);
}

/*********************************************
 * CONVERT TO DEGREES
 * Converts a value in radians to degrees.
 *********************************************/
float Direction::convertToDegrees(float radians)
{
	return 360.0 * (radians / (2.0 * M_PI));
}

