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
#include "testAcceleration.h"
#include "testSatellite.h"
#include "testShip.h"


/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
    TestPosition().run();
	TestDirection().run();
	TestVelocity().run();
	TestAcceleration().run();
	TestSatellite().run();
	TestShip().run();
	
}

