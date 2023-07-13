#include "testShip.h"

/*********************************************
 * RUN
 * Runs all test cases.
 *********************************************/
void TestShip::run()
{
	test_rotate_right();
    test_rotate_left();
	test_rotate_alternating();
	
	test_applyThrust_stationary();
	test_applyThrust_moving();
	test_applyThrust_double();
}


/*********************************************
 * CLOSE ENOUGH
 * Determines if the difference between the actual result and
 * the expected result is within the given tolerance range.
 *********************************************/
bool TestShip::closeEnough(double actual, double expected, double tolerance)
{
	double difference = actual - expected;
	
	return ((difference >= - tolerance) && (difference <= tolerance));
}

/*********************************************
*  TEST - ROTATE RIGHT
*********************************************/
void TestShip::test_rotate_right()
{
	Ship ship(Position(0.0, 26560000), Velocity(-3.880, 0));

	// equivalent of clicking right keyboard arrow 3 times
	ship.direction.rotate(0.1);
	ship.direction.rotate(0.1);
	ship.direction.rotate(0.1);
	
//	assert(closeEnough(ship.direction.getRadians(), -1.2708, 0.01));

}

/*********************************************
*  TEST - ROTATE LEFT
*********************************************/
void TestShip::test_rotate_left()
{
	Ship ship(Position(0.0, 26560000), Velocity(-3.880, 0));
	
	// equivalent of clicking right keyboard arrow 3 times
	ship.direction.rotate(-0.1);
	ship.direction.rotate(-0.1);
	ship.direction.rotate(-0.1);

//	assert(closeEnough(ship.direction.getRadians(), -1.8708, 0.01));
}

/*********************************************
*  TEST - ROTATE ALTERNATING
*********************************************/
void TestShip::test_rotate_alternating()
{
	Ship ship(Position(0, -26560000), Velocity(3880, 0));

	ship.direction.rotate(-0.1); // click left
	ship.direction.rotate(0.1);  // click right
	ship.direction.rotate(0.1);  // click right
	ship.direction.rotate(-0.1); // click left
	ship.direction.rotate(0.1);  // click right
	ship.direction.rotate(0.1);  // click right
		
	//assert(closeEnough(ship.direction.getRadians(), 1.7707, 0.01));
}

/*********************************************
*  TEST - APPLY THRUST - STATIONARY
*********************************************/
void TestShip::test_applyThrust_stationary()
{
	Ship ship(Position(-23001634.72, 13280000), Velocity(0, 0));
	
	// thrust amount = 2.0 and time = 1
	ship.applyThrust(1);
	
	//assert(closeEnough(ship.velocity.getDx(), 2.489, 0.01));
//	assert(closeEnough(ship.velocity.getDy(), 1.717, 0.01));

}

/*********************************************
*  TEST - APPLY THRUST - MOVING
*********************************************/
void TestShip::test_applyThrust_moving()
{
	Ship ship(Position(-23001634.72, 13280000), Velocity(-1940, -3360.18));

	// thrust amount = 2.0 and time = 1
	ship.applyThrust(1);
	
	assert(closeEnough(ship.velocity.getDx(), -1937.51, 0.01));
	assert(closeEnough(ship.velocity.getDy(), -3358.46, 0.01));
}

/*********************************************
*  TEST - APPLY THRUST - DOUBLE
*********************************************/
void TestShip::test_applyThrust_double()
{
	Ship ship(Position(-23001634.72, 13280000), Velocity(-1940, -3360.18));

	// thrust amount = 2.0 and time = 1
	ship.applyThrust(1);
	ship.applyThrust(1);
	
//	assert(closeEnough(ship.velocity.getDx(), -1935.01, 0.01));
//	assert(closeEnough(ship.velocity.getDy(), -3356.74, 0.01));
	
}
