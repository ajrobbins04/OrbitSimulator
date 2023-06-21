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
   
	// test helper functions
    void run();
	float get_gravity(float altitude);
	bool closeEnough(float actual, float predicted);
	
	void test_getAltitude_surface();
	void test_getAltitude_xAxis();
	void test_getAltitude_yAxis();
	
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
	
	// will be implementing these test cases
	// during lab 10
	void test_destroySputnik();
	void test_destroyGPS();
	void test_destroyHubble();
	void test_destroyDragon();
	void test_destroyStarlink();
	void test_createPiece_inheritVelocity();
	void test_createPiece_addKick();
	void test_createPiece_tooClose();
	void test_destroyPiece_leftSolar();
	void test_destroyPiece_rightSolar();
	void test_destroyPiece_center();
	void test_destroyPiece_telescope();
	void test_destroyPiece_computer();
	void test_destroyPiece_body();
	void test_createFragment_inheritVelocity();
	void test_createFragment_addKick();
	void test_createFragment_tooClose();
	void test_createFragment_expire();

	
	
};

#endif
