#include "direction.h"

/*********************************************
 * CONVERT TO RADIANS
 * Converts a value in degrees to radians.
 *********************************************/
double Direction::convertToRadians(double degrees) const
{
	return (degrees / 360.0) * (2.0 * M_PI);
}

/*********************************************
 * CONVERT TO DEGREES
 * Converts a value in radians to degrees.
 *********************************************/
double Direction::convertToDegrees(double radians) const
{
	return 360.0 * (radians / (2.0 * M_PI));
}

