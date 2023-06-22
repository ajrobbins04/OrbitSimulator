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
#include "testSatellite.h"
#include "testShip.h"
#include "testAcceleration.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
    TestPosition().run();
	TestAcceleration().run();
	TestSatellite().run();
	TestShip().run();
	
}

