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
	float distance = sqrt(pos.getMetersX() * pos.getMetersX()
						  + pos.getMetersY() * pos.getMetersY());
	return distance - EARTH_RADIUS;
}
 
/*********************************************
 * TEST - GET GRAVITY SURFACE
 *
 *********************************************/
void TestAcceleration::test_getGravity_surface()
{
	Position pos(6378000, 0);
	Acceleration aGravity(0.0, 0.0);
	
	float alt = getAltitude(pos);
	//aGravity.setGravity(alt, pos);
	
	float ddx = aGravity.getDDx();
	float ddy = aGravity.getDDy();
	
	assert(closeEnough(aGravity.getDDx(), -9.806, 0.01));
	assert(closeEnough(aGravity.getDDy(), 0, 0.01));
}

/*********************************************
 * TEST - GET GRAVITY 500K
 *
 *********************************************/
void TestAcceleration::test_getGravity_500k()
{
	Position pos(6378000 + 500000, 0);
	Acceleration aGravity(0.0, 0.0);
	
	float alt = getAltitude(pos);
	//aGravity.setGravity(alt, pos);
	
 	assert(closeEnough(aGravity.getDDx(), -8.4, 0.01));
	assert(closeEnough(aGravity.getDDy(), 0, 0.01));
}

/*********************************************
 * TEST - GET GRAVITY 2000K
 *
 *********************************************/
void TestAcceleration::test_getGravity_2000k()
{
	Position pos(6378000 + 2000000, 0);
	Acceleration aGravity(0.0, 0.0);
	
	float alt = getAltitude(pos);
	//aGravity.setGravity(alt, pos);
	 
	assert(closeEnough(aGravity.getDDx(), -5.7, 0.01));
	assert(closeEnough(aGravity.getDDy(), 0, 0.01));
 
}
