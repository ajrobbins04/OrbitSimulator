#include "orbit.h"

/*********************************************
 * INITIALIZE
 * Sets all the values needed to run the
 * orbit simulator.
 * *********************************************/
Orbit initialize(const Position &ptUpperRight)
{

	Ship *ship = new Ship(Position(0.0, 0.0), 10, Velocity(0.0, 0.0));
	
	Earth *earth = new Earth();
	
	// create stars
	vector<Star> stars;
	for (int i = 0; i < 200; i++)
	{
		Star star(ptUpperRight);
		stars.push_back(star);
	}
	vector<Satellite*> satellites;
	Hubble *hubble = new Hubble(Position(0, -42164000), 10, Velocity(3100, 0));
	satellites.push_back(hubble);
	
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

	/*GPS *one = new GPS(Position(0.0, 26560000.0), 12, Velocity(-3880, 0.0));
	GPS *two = new GPS(Position(23001634.72, 13280000), 12, Velocity(-1940, 3360.18));
	GPS *three = new GPS(Position(23001634.72, -13280000), 12, Velocity(1940, 3360.18));
	GPS *four = new GPS(Position(0.0, -26560000), 12, Velocity(3880, 0.0));
	GPS *five = new GPS(Position(-23001634.72, -13280000), 12, Velocity(1940, -3360.18));
	GPS *six = new GPS(Position(-23001634.72, 13280000), 12, Velocity(-1940, -3360.18));
	 Hubble *hubble = new Hubble(Position(0, -42164000), 10, Velocity(3100, 0));
	satellites[0] = one;
	satellites[1] = two;*/
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
	earth->adjustAngle(rotationSpeed);
	
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
