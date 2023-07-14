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
#include <vector>
#include <deque>
#include <typeinfo>

#include "uiInteract.h"
#include "earth.h"
#include "star.h"
#include "ship.h"
#include "gps.h"
#include "sputnik.h"
#include "hubble.h"
#include "dragon.h"
#include "starlink.h"


using namespace std;

class Orbit
{
public:
 
	Orbit(Ship *ship, Earth *earth, vector<Satellite*> satellites, vector<Star> &stars, double time) : ship(ship),
	earth(earth), satellites(satellites), stars(stars), time(time) {}
 
	virtual ~Orbit() {}

	void initialize(const Position &ptUpperRight);
	void handleInput(const Interface *pUI);
	void collisionDetection();
	void checkEarthReEntry();
	void checkLifeSpan();
	void removeDeadSatellites();
	void move();
	void draw();
						 
private:
	Ship *ship;
	Earth *earth;
	vector<Star> stars;
	vector<Satellite*> satellites;

	double time;  // (24 hours/day * 60 min/hour) /  30 frames/second = 48 seconds per frame

};

/*********************************************
 * INITIALIZE
 * Create all attributes to be passed into a new orbit
 * object, then return the object.
 *********************************************/
Orbit initialize(const Position &ptUpperRight);

/*********************************************
 * COMPUTE ROTATION SPEED
 * Sets the amount of rotation change (in radians) that's applied
 * to an object (typically earth) as each new frame is drawn.
 *********************************************/
double computeRotationSpeed(double frameRate, double secondsPerDay, double dilation);

#endif /* orbit_h */
