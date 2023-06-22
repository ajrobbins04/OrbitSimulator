/***********************************************************************
* Header File:
*    Test Velocity : Test the Velocity class.
* Author:
*    Br. Helfrich
* Summary:
*    All the unit tests for Velocity.
************************************************************************/

#ifndef testVelocity_h
#define testVelocity_h

#include <iostream>
#include <cassert>

#include "velocity.h"

using namespace std;

/*******************************
* TEST VELOCITY
* A friend class for Velocity,
* which contains the Velocity unit tests.
********************************/
class TestVelocity
{
public:
	
	// test utility methods
	void run();
	float getAltitude(const Position &pos);
	bool closeEnough(float actual, float expected, float tolerance);
	
	void test_defaultConstructor();
	void test_nonDefaultConstructor();
	void test_copyConstructor();
	void test_assignmentOperator();
	
	void test_getSpeed_vertical();
	void test_getSpeed_horizontal();
	void test_getSpeed_diagonal();
	
	void test_getDirection_north();
	void test_getDirection_east();
	void test_getDirection_northEast();
	void test_getDirection_west();
	void test_getDirection_south();
 	void test_getDirection_negative();
	
	void test_setSpeed_northEast();
	void test_setSpeed_east();
	void test_setSpeed_north();
	
	void test_reverse_northEast();
	void test_reverse_east();
	void test_reverse_north();
	
	void test_add_north();
	void test_add_south();
	
	void test_add_stationary();
	void test_add_moving();
	void test_fromStop();
	void test_fromStopLonger();
	void test_add_complex();
};
#endif /* testVelocity_h */
