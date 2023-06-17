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
};

#endif  
