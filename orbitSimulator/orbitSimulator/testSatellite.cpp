#include "testSatellite.h"

void TestSatellite::run()
{
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
}

double TestSatellite::get_gravity(double altitude)
{
	// tmp is just a temporary variable to store one
	// aspect of the gravity computation
	double tmp = EARTH_RADIUS / (EARTH_RADIUS + altitude);
	double gravity = EARTH_GRAVITY * pow(tmp, 2);

	return gravity;
}


void TestSatellite::test_getAltitude_surface()
{
	Satellite s(6378000, 0);
	
	double alt = s.getAltitude();
	
	assert(alt == 0);
	
}

void TestSatellite::test_getAltitude_xAxis()
{
	Satellite s(6379000, 0);
	
	double alt = s.getAltitude();
	
	assert(alt == 1000);
}

void TestSatellite::test_getAltitude_yAxis()
{
	Satellite s(0, 6379000);
	
	double alt = s.getAltitude();
	
	assert(alt == 1000);
}

void TestSatellite::test_getGravity_surface()
{
	Satellite s(6378000, 0);
	
	double alt = s.getAltitude();
	double gravity = get_gravity(alt);
	
	//assert(gravity == -9.8066);
}

void TestSatellite::test_getGravity_500k()
{
	Satellite s(6378000 + 500000, 0);
	
	double alt = s.getAltitude();
	double gravity = get_gravity(alt);
	
	
//	assert(gravity == -8.4);
}

void TestSatellite::test_getGravity_2000k()
{
	Satellite s(6378000 + 2000000, 0);
	
	double alt = s.getAltitude();
	double gravity = get_gravity(alt);
	
//	assert(gravity == -5.7);
}

void TestSatellite::test_updateVelocity_stationary()
{
	Velocity v(0.0, 0.0);
	Acceleration acc;
	int time = 0;
	v.updateVelocity(acc, time);
	
	assert(v.getDx() == 0.0 && v.getDy() == 0.0);
	
	
}

void TestSatellite::test_updateVelocity_moving()
{
	Velocity v(1.2, 3.4);
	Acceleration acc;
	int time = 0;
	v.updateVelocity(acc, time);
	
	assert(v.getDx() == 1.2 && v.getDy() == 3.4);
	
}

void TestSatellite::test_updateVelocity_accFromStop()
{
	Velocity v(0.0, 0.0);
	Acceleration acc;
	int time = 0;
	v.updateVelocity(acc, time);
	
	assert(v.getDx() == 1.2 && v.getDy() == 3.4);
}
void TestSatellite::test_updateVelocity_accFromStop_longer()
{
	
}
