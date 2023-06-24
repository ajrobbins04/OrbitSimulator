#include "testDirection.h"

/*********************************************
* RUN
* Runs all test cases.
*********************************************/
void TestDirection::run()
{
	test_defaultConstructor();
    test_setUp();
	test_setDown();
	test_setRight();
	test_setLeft();
	test_reverse();
	
	test_setRadians_simple();
	test_setRadians_threeQuarters();
	test_setRadians_oneLap();
	test_setRadians_sixLaps();
//	test_setRadians_negative();
//	test_setRadians_negativeThreeQuarters();
//	test_setRadians_negativeOneLap();
//	test_setRadians_negativeSixLaps();
}

/*********************************************
 * CLOSE ENOUGH
 * Determines if the difference between the actual result and
 * the expected result is within the given tolerance range.
 *********************************************/
bool TestDirection::closeEnough(float actual, float expected, float tolerance)
{
	float difference = actual - expected;
	
	return ((difference >= - tolerance) && (difference <= tolerance));
}

/*********************************************
* TEST - DEFAULT CONSTRUCTOR
*********************************************/
void TestDirection::test_defaultConstructor()
{
	Direction dir;
	assert(dir.radians == 0.0);
}

/*********************************************
* TEST - SET UP
* setUp should set direction to 0 degrees, since nothing
* occurs when the up key is pressed.
*********************************************/
void TestDirection::test_setUp()
{
	Direction dir;
	dir.setUp();
	assert(dir.radians == 0.0); // 0 degrees == 0 radians
}

/*********************************************
* TEST - SET DOWN
* setDown should  be up by 180 degrees
* compared to setUp.
*********************************************/
void TestDirection::test_setDown()
{
	Direction dir;
	dir.setDown();
	assert(closeEnough(dir.radians, M_PI, 0.001)); // 180 degrees == PI
}

/*********************************************
* TEST - SET RIGHT
* setRight should be up by 90 degrees compared
* to setUp.
*********************************************/
void TestDirection::test_setRight()
{
	Direction dir;
	dir.setRight();
	assert(closeEnough(dir.radians, M_PI_2, 0.001)); // 90 degrees == PI / 2
}

/*********************************************
* TEST - SET LEFT
* setLeft should be down by 90 degrees compared
* to setUp.
*********************************************/
void TestDirection::test_setLeft()
{
	Direction dir;
	dir.setLeft();
	assert(closeEnough(dir.radians, -M_PI_2, 0.001)); // -90 degrees == -PI / 2
}

/*********************************************
* TEST - REVERSE
* Reverse should take the given direction and reverse it
* by adding 180 degrees
*********************************************/
void TestDirection::test_reverse()
{
	Direction dir(90); // 90 degrees == PI / 2
	dir.reverse();
	assert(closeEnough(dir.radians, -M_PI_2, 0.001));
}

/*********************************************
* TEST - SET RADIANS - SIMPLE
*********************************************/
void TestDirection::test_setRadians_simple()
{
	Direction dir;
	dir.setRadians(0.34);
 
	assert(closeEnough(dir.radians, 0.34, 0.001));
}

/*********************************************
* TEST - SET RADIANS - THREE QUARTERS
* Setting the position 3/4 around the unit circle should
* make it equal to - PI / 2  (270 degrees).
*********************************************/
void TestDirection::test_setRadians_threeQuarters()
{
	Direction dir;
	dir.setRadians(M_PI + M_PI_2); // 180 degrees + 90 degrees = 270 degrees
	
	assert(closeEnough(dir.radians, -M_PI_2, 0.001)); // -PI / 2 == 270 degrees
}

/*********************************************
* TEST - SET RADIANS - ONE LAP
* Increasing the position (given in radians) by 360 degrees should
* put it back in its original position.
*********************************************/
void TestDirection::test_setRadians_oneLap()
{
	Direction dir;
	dir.setRadians(0.4 + (M_PI * 2.0)); // 360 degrees == 2 * PI
	
	assert(closeEnough(dir.radians, 0.4000, 0.001));
}

/*********************************************
* TEST - SET RADIANS - SIX LAPS
* Increasing the position (given in radians) by 360 degrees a
* total of 6 times should put it back in its original position.
*********************************************/
void TestDirection::test_setRadians_sixLaps()
{
	Direction dir;
	dir.setRadians(0.1 + (M_PI * 2.0) * 6.0); // (2 * PI) * 6 == 6 laps
	
	assert(closeEnough(dir.radians, 0.1000, 0.001));
}

/*********************************************
* TEST - SET RADIANS - NEGATIVE
*********************************************/
void TestDirection::test_setRadians_negative()
{
	Direction dir;
	dir.setRadians(-0.34);
	
	assert(closeEnough(dir.radians, -0.34, 0.001));
}

/*********************************************
* TEST - SET RADIANS - NEGATIVE THREE QUARTERS
*********************************************/
void TestDirection::test_setRadians_negativeThreeQuarters()
{
	Direction dir;
	dir.setRadians(-M_PI + -M_PI_2); // -180 degrees + -90 degrees = -270 degrees
	
	assert(closeEnough(dir.radians, M_PI_2, 0.001)); // PI / 2 == -270 degrees
}

/*********************************************
* TEST - SET RADIANS - NEGATIVE ONE LAP
*********************************************/
void TestDirection::test_setRadians_negativeOneLap()
{
	
}

/*********************************************
* TEST - SET RADIANS - NEGATIVE SIX LAPS
*********************************************/
void TestDirection::test_setRadians_negativeSixLaps()
{
	
}
