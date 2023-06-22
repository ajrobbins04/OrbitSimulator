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
	test_getSpeed_diagonal_1();
	test_getSpeed_diagonal_2();
	
	test_getDirection_north();
	test_getDirection_east();
	test_getDirection_northEast();
	test_getDirection_west();
	test_getDirection_south();
	test_getDirection_negative();
 
	test_updateVelocity_northEast();
	test_updateVelocity_east();
	test_updateVelocity_north();
	
	test_reverse_northEast();
	test_reverse_east();
	test_reverse_north();
}

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
	
	assert(closeEnough(v.getDx(), 4.5, 0.0001));
	assert(closeEnough(v.getDy(), 6.7, 0.0001));
}

/*********************************************
* TEST - COPY CONSTRUCTOR
*********************************************/
void TestVelocity::test_copyConstructor()
{
	Velocity v1(-4.2, 7.9);
	
	Velocity v2(v1);
	
	assert(closeEnough(v1.getDx(), -4.2, 0.0001));
	assert(closeEnough(v1.getDy(), 7.9, 0.0001));
	assert(closeEnough(v2.getDx(), -4.2, 0.0001));
	assert(closeEnough(v2.getDy(), 7.9, 0.0001));
}

/*********************************************
* TEST - ASSIGNMENT OPERATOR
*********************************************/
void TestVelocity::test_assignmentOperator()
{
	Velocity v1(10.1, -9.9);
	Velocity v2;
	
	v2 = v1;
	
	assert(closeEnough(v1.getDx(), 10.1, 0.0001));
	assert(closeEnough(v1.getDy(), -9.9, 0.0001));
	assert(closeEnough(v2.getDx(), 10.1, 0.0001));
	assert(closeEnough(v2.getDy(), -9.9, 0.0001));
}

/*********************************************
* TEST - GET SPEED - VERTICAL
* The amount of speed should equal the vertical velocity
* when no horizontal velocity is given.
*********************************************/
void TestVelocity::test_getSpeed_vertical()
{
	Velocity v(0.0, 1.0);
	
	// speed = sqrt(dx * dx + dy * dy)
	float speed = v.getSpeed();
	
	assert(closeEnough(speed, 1.00, 0.0001));
	assert(v.getDx() == 0.0);
	assert(v.getDy() == 1.0);
}

/*********************************************
* TEST - GET SPEED - HORIZONTAL
* The amount of speed should equal the horizontal velocity
* when no vertical velocity is given.
*********************************************/
void TestVelocity::test_getSpeed_horizontal()
{
	Velocity v(1.0, 0.0);
	
	// speed = sqrt(dx * dx + dy * dy)
	float speed = v.getSpeed();
	
	assert(closeEnough(speed, 1.00, 0.0001));
	assert(v.getDx() == 1.0);
	assert(v.getDy() == 0.0);
}

/*********************************************
* TEST - GET SPEED - DIAGONAL 1
* *********************************************/
void TestVelocity::test_getSpeed_diagonal_1()
{
	Velocity v(3.0, 4.0);
	
	// speed = sqrt(dx * dx + dy * dy)
	float speed = v.getSpeed();
	
	assert(closeEnough(speed, 5.00, 0.0001));
	assert(v.getDx() == 3.0);
	assert(v.getDy() == 4.0);
}

/*********************************************
* TEST - GET SPEED - DIAGONAL 2
* *********************************************/
void TestVelocity::test_getSpeed_diagonal_2()
{
	Velocity v(8.0, 6.0);
	
	// speed = sqrt(dx * dx + dy * dy)
	float speed = v.getSpeed();
	
	assert(closeEnough(speed, 10.00, 0.0001));
	assert(v.getDx() == 8.0);
	assert(v.getDy() == 6.0);
}

/*********************************************
* TEST - GET DIRECTION - NORTH
* If there's only vertical velocity moving up, then its direction
* should equal 0 radians.
*********************************************/
void TestVelocity::test_getDirection_north()
{
	Velocity v(0.0, 1.0);
	
	Direction d = v.getDirection();
	
	assert(closeEnough(d.getRadians(), 0.00, 0.0001));
	assert(v.getDx() == 0.0);
	assert(v.getDy() == 1.0);
}

/*********************************************
* TEST - GET DIRECTION - EAST
* If there's only horizontal velocity moving to the right,
* then its direction should equal PI / 2 (that's 90 degrees)
* *********************************************/
void TestVelocity::test_getDirection_east()
{
	Velocity v(1.0, 0.0);
	
	Direction d = v.getDirection();
	
	assert(closeEnough(d.getRadians(), M_PI_2, 0.0001));
	assert(v.getDx() == 1.0);
	assert(v.getDy() == 0.0);
}

/*********************************************
* TEST - GET DIRECTION - NORTHEAST
* *********************************************/
void TestVelocity::test_getDirection_northEast()
{
	Velocity v(1.0, 1.0);
	
	Direction d = v.getDirection();
	
	assert(closeEnough(d.getRadians(), M_PI_2 / 2.0, 0.0001));
	assert(v.getDx() == 1.0);
	assert(v.getDy() == 1.0);
}

/*********************************************
* TEST - GET DIRECTION - WEST
* If there's only horizontal velocity moving to the left,
* then its direction should equal - PI / 2 ( that's -90 degrees)
* *********************************************/
void TestVelocity::test_getDirection_west()
{
	Velocity v(-1.0, 0.0);
	
	Direction d = v.getDirection();
	
	assert(closeEnough(d.getRadians(), - M_PI_2, 0.0001));
	assert(v.getDx() == -1.0);
	assert(v.getDy() == 0.0);
}

/*********************************************
* TEST - GET DIRECTION - SOUTH
* If there's only vertical velocity moving down, then its direction
* should equal PI (that's 180 degrees)
* *********************************************/
void TestVelocity::test_getDirection_south()
{
	Velocity v(0.0, -1.0);
	
	Direction d = v.getDirection();
	
	assert(closeEnough(d.getRadians(), M_PI, 0.0001));
	assert(v.getDx() == 0.0);
	assert(v.getDy() == -1.0);
}

/*********************************************
* TEST - GET DIRECTION - NEGATIVE
* *********************************************/
void TestVelocity::test_getDirection_negative()
{
	
}


/*********************************************
* TEST - SET SPEED - NORTHEAST
* *********************************************/
void TestVelocity::test_updateVelocity_northEast()
{

}

/*********************************************
* TEST - SET SPEED - EAST
* *********************************************/
void TestVelocity::test_updateVelocity_east()
{

}

/*********************************************
* TEST - SET SPEED - NORTH
* *********************************************/
void TestVelocity::test_updateVelocity_north()
{
	
}

/*********************************************
* TEST - REVERSE - NORTHEAST
* *********************************************/
void TestVelocity::test_reverse_northEast()
{
	
}

/*********************************************
* TEST - REVERSE - EAST
* *********************************************/
void TestVelocity::test_reverse_east()
{
	
}

/*********************************************
* TEST - REVERSE - NORTH
* *********************************************/
void TestVelocity::test_reverse_north()
{
	
}

