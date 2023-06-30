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
#include "uiInteract.h"
#include "earth.h"
#include "star.h"
#include "ship.h"
#include "hubble.h"
#include "gps.h"

using namespace std;

class Orbit
{
public:
 
	Orbit(Ship *ship, Earth *earth, Hubble *hubble, vector<Star> &stars, double time): ship(ship), earth(earth),
	hubble(hubble), stars(stars), time(time), rotationSpeed(0.0) {}
	
	/*Orbit(const Position &ptUpperRight): ship(new Ship(Position(0.0, 0.0), 10, Velocity(0.0, 0.0))), earth(new Earth()), time(48.0) {
		
		initialize(ptUpperRight);
	}
	
	Orbit(const Position &ptUpperRight, const Position &pos, double radius, const Velocity &velocity, double t):
	ship(new Ship(pos, radius, velocity)), earth(new Earth()), time(t) {
		
		initialize(ptUpperRight);
	}
	
	Orbit(const Position &ptUpperRight, const Position &pos, double radius, const Velocity &velocity, double t, double rate):
	ship(new Ship(pos, radius, velocity)), earth(new Earth()), time(t) {}*/
	
	void initialize(const Position &ptUpperRight);
	void setRotationSpeed(double frameRate, double secondsPerDay, double dilation);

	void move();
	void draw();
						 
private:
	Ship *ship;
	Earth *earth;
	vector<Star> stars;
	Hubble *hubble;
	//Satellite *satellites[10];
	
	//Position ptUpperRight; // size of screen that will display orbit simulator
	double time;           // (24 hours/day * 60 min/hour) /  30 frames/second = 48 seconds per frame
	double rotationSpeed;  // amount of rotation per frame


};

/*********************************************
 * INITIALIZE
 * Create all attributes to be passed into a new orbit
 * object, then return the object.
 *********************************************/
Orbit initialize(const Position &ptUpperRight);

#endif /* orbit_h */
