/***********************************************************************
* Header File:
*    Test Acceleration : Test the Acceleration class.
* Author:
*    Amber Robbins, Martin Nkala
* Summary:
*    All the unit tests for Acceleration.
************************************************************************/
#ifndef testAcceleration_h
#define testAcceleration_h
#include <iostream>
#include <cassert>

#include "satellite.h"

using namespace std;

/*******************************
* TEST ACCELERATION
* A friend class for Acceleration,
* which contains the Acceleration unit tests.
********************************/
class TestAcceleration
{
public:
	
	// test utility methods
	void run();
	float getAltitude(const Position &pos);
	bool closeEnough(float actual, float expected, float tolerance);
	
	void test_getGravity_surface();
	void test_getGravity_500k();
	void test_getGravity_2000k();
	
};
#endif /* testAcceleration_h */
