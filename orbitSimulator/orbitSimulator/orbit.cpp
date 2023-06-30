#include "orbit.h"

/*********************************************
 * INITIALIZE
 * Sets all the values needed to run the
 * orbit simulator.
 * *********************************************/
Orbit initialize(const Position &ptUpperRight)
{
	// create ship
	Ship *ship = new Ship(Position(0.0, 0.0), 10, Velocity(0.0, 0.0));
	
	// create stars
	vector<Star> stars;
	for (int i = 0; i < 200; i++)
	{
		Star star(ptUpperRight);
		stars.push_back(star);
	}
	
	Earth *earth = new Earth();
	
	double frameRate = 30.0;    // OpenGL draws 30 frames/second
	double hoursPerDay = 24.0;
	double minPerHour = 60.0;
	double secondsPerMin = 60.0;
	
	double secondsPerDay = hoursPerDay * minPerHour * secondsPerMin;
	double timeDilation = hoursPerDay * minPerHour;


	Orbit orbit(ship, earth, stars, timeDilation);
	orbit.setRotationSpeed(frameRate, secondsPerDay);
	
	return orbit;

	/*GPS *one = new GPS(Position(0.0, 26560000.0), 12, Velocity(-3880, 0.0));
	GPS *two = new GPS(Position(23001634.72, 13280000), 12, Velocity(-1940, 3360.18));
	GPS *three = new GPS(Position(23001634.72, -13280000), 12, Velocity(1940, 3360.18));
	GPS *four = new GPS(Position(0.0, -26560000), 12, Velocity(3880, 0.0));
	GPS *five = new GPS(Position(-23001634.72, -13280000), 12, Velocity(1940, -3360.18));
	GPS *six = new GPS(Position(-23001634.72, 13280000), 12, Velocity(-1940, -3360.18));
	
	satellites[0] = one;
	satellites[1] = two;*/
}
 
/*********************************************
 * DRAW
 * Draws everything currently in orbit.
 *********************************************/
void Orbit::draw()
{

	/*if (satellites[0]->isAlive())
	{
		satellites[0]->draw(satellites[0]->getRotateAngle());
		satellites[0]->adjustAngle(rotationSpeed);
	}*/
	
	Hubble *hubble = new Hubble(Position(0, -42164000), 10, Velocity(3100, 0));
 
	/*hubble->draw(hubble->getRotateAngle());
	hubble->adjustAngle(-0.01);
	
	if (earth->isAlive())
	{
		earth->draw(earth->getRotateAngle());
		earth->adjustAngle(rotationSpeed);
	}*/
	Position pt;
 
	ogstream gout(pt);
	
	hubble->draw(hubble->getRotationAngle(), gout);
	hubble->adjustAngle(-0.01);

	earth->draw(earth->getRotationAngle(), gout);
	earth->adjustAngle(rotationSpeed);
	
	vector<Star>::iterator stars_Iter;

	stars_Iter = stars.begin();
	for (; stars_Iter != stars.end(); stars_Iter++)
	{
		stars_Iter->draw(gout);
	}
 
}

/*********************************************
 * SET ROTATION SPEED
 * Sets the amount of rotation change (in radians) that's
 * applied to earth as each new frame is drawn.
 *********************************************/
void Orbit::setRotationSpeed(double frameRate, double secondsPerDay)
{
	double radiansPerDay = (M_PI * 2.0) / frameRate;
	double radiansPerFrame =  -(radiansPerDay) * (time / secondsPerDay);
 
	rotationSpeed = radiansPerFrame;
}
