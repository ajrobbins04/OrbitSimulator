#include "orbit.h"

void Orbit::initialize(Position ptUpperRight)
{
	double frameRate = 30.0;
	double hoursPerDay = 24.0;
	double minPerHour = 60.0;
	double secondsPerMin = 60.0;
	
	double secondsPerDay = hoursPerDay * minPerHour * secondsPerMin;
	double timeDilation = hoursPerDay * minPerHour;
	this->time = timeDilation;
	
	
}
void Orbit::draw()
{
	Position pt;
	ogstream gout(pt);
	
	if (earth->isAlive())
	{
		earth->draw(earth->getRotateAngle());
		earth->adjustAngle(-0.01);
	}
}

void Orbit::setRotationSpeed()
{
	double frameRate = 30.0;           // OpenGL draws 30 frames/second
	double secondsPerDay = 86400.0;    // 24 hours/day * 60 minutes/hour * 60 seconds/min
	double radiansPerDay = M_PI * 2.0;
	double radiansPerFrame = (radiansPerDay / frameRate) * (time / secondsPerDay);
 
	rotationSpeed = radiansPerFrame;

}
