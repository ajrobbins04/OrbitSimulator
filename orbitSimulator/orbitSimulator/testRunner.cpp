/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "testRunner.h"
#include "testPosition.h"
#include "testDirection.h"
#include "testVelocity.h"
#include "testHubble.h"
#include "testShip.h"


/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
	cout << "Running Position test cases...\n";
    TestPosition().run();
	cout << "Position test cases pass.\n\n";
	cout << "Running Direction test cases...\n";
	TestDirection().run();
	cout << "Direction test cases pass.\n\n";
	cout << "Running Velocity test cases...\n";
	TestVelocity().run();
	cout << "Velocity test cases pass.\n\n";
	cout << "Running Satellite test cases...\n";
	TestHubble().run();
	cout << "Satellite test cases pass.\n\n";
	cout << "Running Ship test cases...\n";
	TestShip().run();
	cout << "Ship test cases pass.\n\n";
	
}

