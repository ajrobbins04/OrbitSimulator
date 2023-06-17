/***********************************************************************
* Header File:
*    Test Satellite : Test the Satellite class.
* Author:
*    Amber Robbins, Martin Nkala
* Summary:
*    All the unit tests for Satellite.
************************************************************************/

#ifndef testSatellite_h
#define testSatellite_h

#include <iostream>
#include <cassert>
#include "position.h"
#include "velocity.h"
#include "satellite.h"


using namespace std;

/*******************************
* TEST SATELLITE
* A friend class for Satellite,
* which contains the Satellite unit tests.
********************************/
class TestSatellite
{
public:
   
    void run();
	
	void test_getAltitude_surface();
	void test_getAltitude_xAxis();
	void test_getAltitude_yAxis();

	float get_gravity(float altitude);
	void test_getGravity_surface();
	void test_getGravity_500k();
	void test_getGravity_2000k();
	
	void test_updateVelocity_stationary();
	void test_updateVelocity_moving();
	void test_updateVelocity_accFromStop();
	void test_updateVelocity_accFromStop_longer();
	void test_updateVelocity_complex();
	
	void test_updatePosition_stationary();
	void test_updatePosition_moving();
	void test_updatePosition_movingLonger();
	void test_updatePosition_fromStop();
	void test_updatePosition_fromStop_longer();
	void test_updatePosition_complex();
};

#endif
