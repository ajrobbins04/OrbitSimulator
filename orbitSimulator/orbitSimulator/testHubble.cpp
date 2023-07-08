#include "testHubble.h"

/*********************************************
 * RUN
 * Runs all test cases.
 *********************************************/
void TestHubble::run()
{
	test_constructor_stationaryNorth();
	
	test_getAltitude_surface();
	test_getAltitude_xAxis();
	test_getAltitude_yAxis();
	
	test_getGravity_surface();
	test_getGravity_500k();
	test_getGravity_2000k();
	
	test_updateVelocity_stationary();
	test_updateVelocity_moving();
	test_updateVelocity_accFromStop();
	test_updateVelocity_accFromStop_longer();
	test_updateVelocity_complex();

	test_updatePosition_stationary();
	test_updatePosition_moving();
	test_updatePosition_movingLonger();
	test_updatePosition_fromStop();
	test_updatePosition_fromStop_longer();
	test_updatePosition_complex();
}

/*********************************************
 * CLOSE ENOUGH
 * Determines if the difference between the actual result and
 * the expected result is within the given tolerance range.
 *********************************************/
bool TestHubble::closeEnough(double actual, double expected, double tolerance)
{
	double difference = actual - expected;
	
	return ((difference >= - tolerance) && (difference <= tolerance));
}
 
/*********************************************
* TEST - 	CONSTRUCTOR - STATIONARY NORTH
*********************************************/
void TestHubble::test_constructor_stationaryNorth()
{
	Hubble sParent(Position(512000000, 640000000));
	sParent.setVelocity(0.0, 0.0);
	
	Direction d;
	d.setRadians(0.0); // kick to the north
	
	Hubble s(sParent, d);
	
	//assert(closeEnough(s.velocity.getDx(), 0.0, 250.0));      // small deviation
	//assert(closeEnough(s.velocity.getDy(), 2000.0, 1200.0));  // 1,000 <= v <= 3,000
	assert(closeEnough(s.pos.getMetersX(), 512000000.0, 512000.0)); // moving north, so x unchanged
	assert(closeEnough(s.pos.getMetersY(), 640000000.0, 512000.0));
	assert(s.direction.getRadians() == 0.0);
	assert(s.getAngularVelocity() == 0.0);
	assert(s.isAlive() == true);
	assert(s.getRadius() == 0.0);
	assert(s.age == 0.0);
	
}
/*********************************************
* TEST - 	GET ALTITUDE - SURFACE
*********************************************/
void TestHubble::test_getAltitude_surface()
{
	Hubble s(Position(6378000, 0));
	
	double alt = s.getAltitude();
	
	assert(alt == 0);
	
}

/*********************************************
* TEST - 	GET ALTITUDE - X AXIS
*********************************************/
void TestHubble::test_getAltitude_xAxis()
{
	Hubble s(Position(6379000, 0));
	
	double alt = s.getAltitude();
	
	assert(alt == 1000);
}

/*********************************************
* TEST - 	GET ALTITUDE - Y AXIS
*********************************************/
void TestHubble::test_getAltitude_yAxis()
{
	Hubble s(Position(0, 6379000));
	
	double alt = s.getAltitude();
	
	assert(alt == 1000);
}

/*********************************************
* TEST - 	GET GRAVITY - SURFACE
*********************************************/
void TestHubble::test_getGravity_surface()
{
	Hubble s(Position(6378000, 0));
	Acceleration aGravity(0.0, 0.0);
	
	aGravity = s.getGravity();

	assert(closeEnough(aGravity.getDDx(), -9.8066, 0.03));
	assert(closeEnough(aGravity.getDDy(), 0.0, 0.03));
}

/*********************************************
* TEST - 	GET GRAVITY - 500 K
*********************************************/
void TestHubble::test_getGravity_500k()
{
	Hubble s(Position(6378000 + 500000, 0));
	Acceleration aGravity(0.0, 0.0);
	
	aGravity = s.getGravity();
	
	assert(closeEnough(aGravity.getDDx(), -8.4, 0.05));
	assert(closeEnough(aGravity.getDDy(), 0.0, 0.05));

}

/*********************************************
* TEST - 	GET GRAVITY - 2000 K
*********************************************/
void TestHubble::test_getGravity_2000k()
{
	Hubble s(Position(6378000 + 2000000, 0));
	Acceleration aGravity(0.0, 0.0);
	
	aGravity = s.getGravity();
	
	assert(closeEnough(aGravity.getDDx(), -5.7, 0.03));
	assert(closeEnough(aGravity.getDDy(), 0.0, 0.03));

}

/*********************************************
* TEST - UPDATE VELOCITY  -
*********************************************/
void TestHubble::test_updateVelocity_stationary()
{
	Velocity v(0.0, 0.0);
	Acceleration acc;
	double time = 0;
	
	v.updateVelocity(acc, time);
	
	assert(v.getDx() == 0.0 && v.getDy() == 0.0);
	
}

void TestHubble::test_updateVelocity_moving()
{
	Velocity v(1.2, 3.4);
	Acceleration acc;
	double time = 0;
	v.updateVelocity(acc, time);
 
	assert(closeEnough(v.getDx(), 1.2, 0.01));
	assert(closeEnough(v.getDy(), 3.4, 0.01));
}

void TestHubble::test_updateVelocity_accFromStop()
{
	Velocity v(0.0, 0.0);
	Acceleration acc(1.2, 3.4);
	double time = 1;
	v.updateVelocity(acc, time);
	
	assert(closeEnough(v.getDx(), 1.2, 0.01));
	assert(closeEnough(v.getDy(), 3.4, 0.01));
}

void TestHubble::test_updateVelocity_accFromStop_longer()
{
	Velocity v(0.0, 0.0);
	Acceleration acc(1.2, 3.4);
	double time = 2;
	v.updateVelocity(acc, time);
	
	assert(closeEnough(v.getDx(), 2.4, 0.01));
	assert(closeEnough(v.getDy(), 6.8, 0.01));
}

void TestHubble::test_updateVelocity_complex()
{
	Velocity v(4.1, 6.0);
	Acceleration acc(0.5, 0.2);
	double time = 3;
	v.updateVelocity(acc, time);
	
	assert(closeEnough(v.getDx(), 5.6, 0.01));
	assert(closeEnough(v.getDy(), 6.6, 0.01));
}

void TestHubble::test_updatePosition_stationary()
{
	Hubble s(Position(11.1, 22.2));
	Velocity velocity(0.0, 0.0);
	Acceleration acc;
	double time = 0;
	
	velocity.updateVelocity(acc, time);
	s.updatePosition(acc, time);
	
	assert(closeEnough(s.getPosX(), 11.1, 0.01));
	assert(closeEnough(s.getPosY(), 22.2, 0.01));
}

void TestHubble::test_updatePosition_moving()
{
	Hubble s(Position(11.1, 22.2));
	s.setVelocity(0.5, 0.4);
	Acceleration acc(0.0, 0.0);
	double time = 1;
	
	s.velocity.updateVelocity(acc, time);
	s.updatePosition(acc, time);
	
	assert(closeEnough(s.getPosX(), 11.6, 0.01));
	assert(closeEnough(s.getPosY(), 22.6, 0.01));
}

void TestHubble::test_updatePosition_movingLonger()
{
	Hubble s(Position(11.1, 22.2));
	s.setVelocity(0.5, 0.4);
	Acceleration acc;
	double time = 2;
	
	s.velocity.updateVelocity(acc, time);
	s.updatePosition(acc, time);
	
	assert(closeEnough(s.getPosX(), 12.1, 0.01));
	assert(closeEnough(s.getPosY(), 23.0, 0.01));
}

void TestHubble::test_updatePosition_fromStop()
{
	Hubble s(Position(11.1, 22.2));
	s.setVelocity(0.0, 0.0);
	Acceleration acc(0.2, 0.3);
	double time = 1;
	
	s.velocity.updateVelocity(acc, time);
	s.updatePosition(acc, time);
	
	assert(closeEnough(s.getPosX(), 11.2, 1));
	assert(closeEnough(s.getPosY(), 22.35, 1));
}

void TestHubble::test_updatePosition_fromStop_longer()
{
	Hubble s(Position(11.1, 22.2));
	s.setVelocity(0.0, 0.0);
	Acceleration acc(0.2, 0.3);
	double time = 2;
	
	s.velocity.updateVelocity(acc, time);
	s.updatePosition(acc, time);
	
	assert(closeEnough(s.getPosX(), 11.5, 1));
//	assert(closeEnough(s.getPosY(), 22.8, 1));
}

void TestHubble::test_updatePosition_complex()
{
	Hubble s(Position(11.1, 22.2));
	s.setVelocity(1.0, 2.0);
	Acceleration acc(0.2, 0.3);
	double time = 2;
	
	Hubble s2(Position(11.1, 22.2));
	s2.velocity.updateVelocity(acc, time);
	
	s.updatePosition(acc, time);

	
	assert(closeEnough(s.getPosY(), 26.8, 1));
	assert(closeEnough(s.getPosX(), 13.5, 1));
	 
}

