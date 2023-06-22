#include "testAcceleration.h"

/*********************************************
* RUN
* Runs all test cases.
* *********************************************/
void TestAcceleration::run()
{
	test_getGravity_surface();
	test_getGravity_500k();
	test_getGravity_2000k();
}

/*********************************************
* CLOSE ENOUGH
* Determines if the difference between the actual result and
* the expected result is within the given tolerance range.
*********************************************/
bool TestAcceleration::closeEnough(float actual, float expected, float tolerance)
{
	float difference = actual - expected;
	
	return ((difference >= - tolerance) && (difference <= tolerance));
}
 
/*********************************************
* GET ALTITUDE
* Finds the altitude between the earth's location and the
* location at a given position (pos).
*********************************************/
float TestAcceleration::getAltitude(const Position &pos)
{
	// earth is at (0,0)
	Position posEarth(0.0, 0.0);
	
	float distance = sqrt((pos.getMetersX() - posEarth.getMetersX()) * (pos.getMetersX() - posEarth.getMetersX()) +
				(pos.getMetersY() - posEarth.getMetersY()) * (pos.getMetersY() - posEarth.getMetersY()));
	return distance - EARTH_RADIUS;
}

/*********************************************
 * CONVERT TO DEGREES
 * Converts a value in radians to degrees.
 *********************************************/
void TestAcceleration::test_getGravity_surface()
{
	Position pos(6378000, 0);
	Acceleration aGravity(0.0, 0.0);
	
	float alt = getAltitude(pos);
	float ddx = getDDx(aGravity, alt, pos);
	float ddy = getDDy(aGravity, alt, pos);
	assert(closeEnough(ddx, -9.806, 0.01));
	assert(closeEnough(ddy, 0, 0.01));
}

/*********************************************
 * CONVERT TO DEGREES
 * Converts a value in radians to degrees.
 *********************************************/
void TestAcceleration::test_getGravity_500k()
{
	Position pos(6378000 + 500000, 0);
	Acceleration aGravity(0.0, 0.0);
	
	float alt = getAltitude(pos);
	float ddx = getDDx(aGravity, alt, pos);
	float ddy = getDDy(aGravity, alt, pos);
	 
	assert(closeEnough(ddx, -8.4, 0.01));
	assert(closeEnough(ddy, 0, 0.01));
}

/*********************************************
 * CONVERT TO DEGREES
 * Converts a value in radians to degrees.
 *********************************************/
void TestAcceleration::test_getGravity_2000k()
{
	Position pos(6378000 + 2000000, 0);
	Acceleration aGravity(0.0, 0.0);
	
	float alt = getAltitude(pos);
	float ddx = getDDx(aGravity, alt, pos);
	float ddy = getDDy(aGravity, alt, pos);
	 
	assert(closeEnough(ddx, -5.7, 0.01));
	assert(closeEnough(ddy, 0, 0.01));
 
}
