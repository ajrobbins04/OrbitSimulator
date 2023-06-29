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

#include "uiInteract.h"
#include "satellite.h"
#include "earth.h"
#include "ship.h"

class Orbit
{
public:
	Orbit(): dreamChaser(new Ship(Position(0.0, 0.0), 10, Velocity(0.0, 0.0))), timeDilaton(48.0),
	earth(new Earth()){}
	
	Orbit(const Position &pos, double radius, const Velocity &velocity, double td):
	dreamChaser(new Ship(pos, radius, velocity)), timeDilaton(48.0),
	earth(new Earth()){}
 
	void draw(double frameRate);
						 
private:
	Ship *dreamChaser;
	Earth *earth;
	double timeDilaton;
};
#endif /* orbit_h */
