#include "orbit.h"

void Orbit::initialize(const Position &ptUpperRight)
{
	double frameRate = 30.0;    // OpenGL draws 30 frames/second
	double hoursPerDay = 24.0;
	double minPerHour = 60.0;
	double secondsPerMin = 60.0;
	
	double secondsPerDay = hoursPerDay * minPerHour * secondsPerMin;
	double timeDilation = hoursPerDay * minPerHour;
	this->time = timeDilation;
	
	setRotationSpeed(frameRate, secondsPerDay);
	

	GPS *one = new GPS(Position(0.0, 26560000.0), 12, Velocity(-3880, 0.0));
	GPS *two = new GPS(Position(23001634.72, 13280000), 12, Velocity(-1940, 3360.18));
	GPS *three = new GPS(Position(23001634.72, -13280000), 12, Velocity(1940, 3360.18));
	GPS *four = new GPS(Position(0.0, -26560000), 12, Velocity(3880, 0.0));
	GPS *five = new GPS(Position(-23001634.72, -13280000), 12, Velocity(1940, -3360.18));
	GPS *six = new GPS(Position(-23001634.72, 13280000), 12, Velocity(-1940, -3360.18));
	
	satellites[0] = one;
	satellites[1] = two;
	


	
}
void Orbit::draw()
{

	if (satellites[0]->isAlive())
	{
		satellites[0]->draw(satellites[0]->getRotateAngle());
		satellites[0]->adjustAngle(rotationSpeed);
	}
	
	Hubble *hubble = new Hubble(Position(0, -42164000), 10, Velocity(3100, 0));
	hubble->draw(hubble->getRotateAngle());
	hubble->adjustAngle(-0.01);
	
	if (earth->isAlive())
	{
		earth->draw(earth->getRotateAngle());
		earth->adjustAngle(rotationSpeed);
	}
}

void Orbit::setRotationSpeed(double frameRate, double secondsPerDay)
{
	double radiansPerDay = (M_PI * 2.0) / frameRate;
	double radiansPerFrame =  -(radiansPerDay) * (time / secondsPerDay);
 
	rotationSpeed = radiansPerFrame;
}
