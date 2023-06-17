/***********************************************************************
* Header File:
*    Test Ship : Test the Ship class.
* Author:
*    Amber Robbins, Martin Nkala
* Summary:
*    All the unit tests for Ship.
************************************************************************/

#ifndef testShip_h
#define testShip_h

#include <iostream>
#include <cassert>

#include "orbit.h"
#include "ship.h"

using namespace std;

/*******************************
* TEST SHIP
* A friend class for Ship,
* which contains the Ship unit tests.
********************************/
class TestShip
{
public:
	
	void run();
	
	void test_rotate_right();
	void test_rotate_left();
	void test_rotate_alternating();
	
	void test_applyThrust_stationary();
	void test_applyThrust_moving();
	void test_applyThrust_double();
	
	// will be implementing these test cases
	// during lab 10
	void test_launchProjectile_stationary();
	void test_launchProjectile_moving();
	void test_launchProjectile_thrustApplied();
	void test_launchProjectile_pointingDown();
	void test_launchProjectile_pointingUp();
	void test_launchProjectile_pointingRight();
	void test_launchProjectile_pointingLeft();

};

#endif  
