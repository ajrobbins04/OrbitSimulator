#include "orbit.h"

/*********************************************
 * INITIALIZE
 * Sets all the values needed to run the
 * orbit simulator.
 * *********************************************/
Orbit initialize(const Position &ptUpperRight)
{
	// create earth
	Earth *earth = new Earth();
	
	// create stars
	vector<Star> stars;
	for (int i = 0; i < 200; i++)
	{
		Star star(ptUpperRight);
		stars.push_back(star);
	}
	
	// create satellites (including the ship)
	vector<Satellite*> satellites;
	
	Ship *ship = new Ship(Position(0.0, 0.0), 10, Velocity(0.0, 0.0));
	satellites.push_back(ship);
	
	GPS *GPS_1 = new GPS(Position(0.0, 26560000.0), 12, Velocity(-3880, 0.0));
	GPS *GPS_2 = new GPS(Position(23001634.72, 13280000.0), 12, Velocity(-1940.0, 3360.18));
	GPS *GPS_3 = new GPS(Position(23001634.72, -13280000.0), 12, Velocity(1940, 3360.18));
	GPS *GPS_4 = new GPS(Position(0.0, -26560000.0), 12, Velocity(3880.0, 0.0));
	GPS *GPS_5 = new GPS(Position(-23001634.72, -13280000.0), 12, Velocity(1940.0, -3360.18));
	GPS *GPS_6 = new GPS(Position(-23001634.72, 13280000.0), 12, Velocity(-1940.0, -3360.18));
	
	satellites.push_back(GPS_1);
	satellites.push_back(GPS_2);
	satellites.push_back(GPS_3);
	satellites.push_back(GPS_4);
	satellites.push_back(GPS_5);
	satellites.push_back(GPS_6);
	
	Sputnik *sputnik = new Sputnik(Position(-36515095.13, 21082000.0), 4, Velocity(2050.0, 2684.68));
	satellites.push_back(sputnik);
	
	Hubble *hubble = new Hubble(Position(0.0, -42164000.0), 10, Velocity(3100.0, 0.0));
	satellites.push_back(hubble);
	
	Dragon *dragon = new Dragon(Position(0.0, 8000000.0), 7, Velocity(-7900.0, 0.0));
	satellites.push_back(dragon);
	
	Starlink *starlink = new Starlink(Position(0.0, -13020000.0), 6, Velocity(5800.0, 0.0));
	satellites.push_back(starlink);
	
	double frameRate = 30.0;    // OpenGL draws 30 frames/second
	double hoursPerDay = 24.0;
	double minPerHour = 60.0;
	double secondsPerMin = 60.0;
	
	double secondsPerDay = hoursPerDay * minPerHour * secondsPerMin;
	double dilation = hoursPerDay * minPerHour;
	double time = dilation / frameRate;

	Orbit orbit(ship, earth, satellites, stars, time);
	orbit.setRotationSpeed(frameRate, secondsPerDay, dilation);
	
	return orbit;
 
}
 
/*********************************************
 * MOVE
 * Moves everything currently in orbit.
 *********************************************/
void Orbit::move()
{
 
}
/*********************************************
 * DRAW
 * Draws everything currently in orbit.
 *********************************************/
void Orbit::draw()
{
	Position pt;
 
	ogstream gout(pt);

	earth->draw(earth->getRotationAngle(), gout);
	earth->adjustDirection(rotationSpeed);
	
	vector<Satellite*>::iterator sats_Iter;

	sats_Iter = satellites.begin();
	for (; sats_Iter != satellites.end(); sats_Iter++)
	{
		(*sats_Iter)->draw((*sats_Iter)->getRotationAngle(), gout);
	}
 
	vector<Star>::iterator stars_Iter;

	stars_Iter = stars.begin();
	for (; stars_Iter != stars.end(); stars_Iter++)
	{
		stars_Iter->draw(gout);
		stars_Iter->advancePhaseStar();
	}
 
}

/*********************************************
 * SET ROTATION SPEED
 * Sets the amount of rotation change (in radians) that's
 * applied to earth as each new frame is drawn.
 *********************************************/
void Orbit::setRotationSpeed(double frameRate, double secondsPerDay, double dilation)
{
	double radiansPerDay = (M_PI * 2.0) / frameRate;
	double radiansPerFrame =  -(radiansPerDay) * (dilation / secondsPerDay);
 
	rotationSpeed = radiansPerFrame;
}
