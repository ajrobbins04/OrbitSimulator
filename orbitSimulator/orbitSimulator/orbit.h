/***********************************************************************
 * Header File:
 *    Orbit
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *
 ************************************************************************/

#ifndef orbit_h
#define orbit_h

#ifndef M_PI
#define M_PI    3.14159265358979323846
#endif

#include <cmath>
#include "uiInteract.h"
#include "satellite.h"
#include "earth.h"
#include "ship.h"

class Orbit
{
public:
	Orbit(Position ptUpperRight): dreamChaser(new Ship(Position(0.0, 0.0), 10, Velocity(0.0, 0.0))), earth(new Earth()),
	time(48.0) {

		setRotationSpeed();
	}
	
	Orbit(Position ptUpperRight, const Position &pos, double radius, const Velocity &velocity, double t):
	dreamChaser(new Ship(pos, radius, velocity)), earth(new Earth()), time(t) {}
	
	Orbit(const Position &pos, double radius, const Velocity &velocity, double t, double rate):
	dreamChaser(new Ship(pos, radius, velocity)), earth(new Earth()), time(t) {}
	void initialize();
	void setRotationSpeed();
	void move();
	void draw();
						 
private:
	Ship *dreamChaser;
	Earth *earth;
	double time;          // (24 hours/day * 60 min/hour) /  30 frames/second = 48 seconds per frame
	double rotationSpeed; // amount of rotation per frame

};
#endif /* orbit_h */
