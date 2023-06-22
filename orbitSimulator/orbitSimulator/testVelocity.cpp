#include "testVelocity.h"

/*********************************************
* RUN
* Runs all test cases.
*********************************************/
void TestVelocity::run()
{
	test_defaultConstructor();
	test_nonDefaultConstructor();
	test_copyConstructor();
	test_assignmentOperator();
	
	test_getSpeed_vertical();
	test_getSpeed_horizontal();
	test_getSpeed_diagonal();
	
	test_getDirection_north();
	test_getDirection_east();
	test_getDirection_northEast();
	test_getDirection_west();
	test_getDirection_south();
	test_getDirection_negative(); }

/*********************************************
 * CLOSE ENOUGH
 * Determines if the difference between the actual result and
 * the expected result is within the given tolerance range.
 *********************************************/
bool TestVelocity::closeEnough(float actual, float expected, float tolerance)
{
	float difference = actual - expected;
	
	return ((difference >= - tolerance) && (difference <= tolerance));
}

/*********************************************
* TEST -  DEFAULT CONSTRUCTOR
*********************************************/
void TestVelocity::test_defaultConstructor()
{
	Velocity v;
	
	assert(v.getDx() == 0.0);
	assert(v.getDy() == 0.0);
}

/*********************************************
* TEST - NON DEFAULT CONSTRUCTOR
*********************************************/
void TestVelocity::test_nonDefaultConstructor()
{
	Velocity v(4.5, 6.7);
	
	assert(closeEnough(v.getDx(), 4.5, 0.001));
	assert(closeEnough(v.getDy(), 6.7, 0.001));
}

/*********************************************
* TEST - COPY CONSTRUCTOR
*********************************************/
void TestVelocity::test_copyConstructor()
{
	Velocity v1(-4.2, 7.9);
	
	Velocity v2(v1);
	
	assert(closeEnough(v1.getDx(), -4.2, 0.001));
	assert(closeEnough(v1.getDy(), 7.9, 0.001));
	assert(closeEnough(v2.getDx(), -4.2, 0.001));
	assert(closeEnough(v2.getDy(), 7.9, 0.001));
}

/*********************************************
* TEST - ASSIGNMENT OPERATOR
*********************************************/
void TestVelocity::test_assignmentOperator()
{
	Velocity v1(10.1, -9.9);
	Velocity v2;
	
	v2 = v1;
	
	assert(closeEnough(v1.getDx(), 10.1, 0.001));
	assert(closeEnough(v1.getDy(), -9.9, 0.001));
	assert(closeEnough(v2.getDx(), 10.1, 0.001));
	assert(closeEnough(v2.getDy(), -9.9, 0.001));
}

/*********************************************
* TEST - GET SPEED - VERTICAL
*********************************************/
void TestVelocity::test_getSpeed_vertical()
{
	
}

/*********************************************
* TEST - GET SPEED - HORIZONTAL
*********************************************/
void TestVelocity::test_getSpeed_horizontal()
{
	
}

/*********************************************
* TEST - GET SPEED - DIAGONAL
*********************************************/
void TestVelocity::test_getSpeed_diagonal()
{
	
}

/*********************************************
* TEST - GET DIRECTION - NORTH
*********************************************/
void TestVelocity::test_getDirection_north()
{
	
}

/*********************************************
* TEST - GET DIRECTION - EAST
*********************************************/
void TestVelocity::test_getDirection_east()
{
	
}

/*********************************************
* TEST - GET DIRECTION - NORTHEAST
*********************************************/
void TestVelocity::test_getDirection_northEast()
{
	
}

/*********************************************
* TEST - GET DIRECTION - WEST
*********************************************/
void TestVelocity::test_getDirection_west()
{
	
}

/*********************************************
* TEST - GET DIRECTION - SOUTH
*********************************************/
void TestVelocity::test_getDirection_south()
{
	
}

/*********************************************
* TEST - GET DIRECTION - NEGATIVE
*********************************************/
void TestVelocity::test_getDirection_negative()
{
	
}
