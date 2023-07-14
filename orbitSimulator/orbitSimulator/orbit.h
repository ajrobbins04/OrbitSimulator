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

#include <vector>
#include <list>

#include "uiInteract.h"
#include "earth.h"
#include "star.h"
#include "ship.h"
#include "gps.h"
#include "sputnik.h"
#include "hubble.h"
#include "dragon.h"
#include "starlink.h"

const double FRAME_RATE = 30.0;    // OpenGL draws 30 frames/second
const double HOURS_PER_DAY = 24.0;
const double MIN_PER_HOUR = 60.0;
const double SEC_PER_MIN = 60.0;

const double PI = 3.14159265358979323846;

using namespace std;

class Orbit
{
public:
	
	Orbit(const Position &ptUpperRight) : ship(new Ship()), earth(new Earth()) {

		for (int i = 0; i < 200; i++)
		{
			Star star(ptUpperRight);
			stars.push_back(star);
		}
		
		satellites.push_back(ship);

		satellites.push_back(new GPS(1));
		satellites.push_back(new GPS(2));
		satellites.push_back(new GPS(3));
		satellites.push_back(new GPS(4));
		satellites.push_back(new GPS(5));
		satellites.push_back(new GPS(6));

		satellites.push_back(new Sputnik());
		satellites.push_back(new Hubble());
		satellites.push_back(new Dragon());
		satellites.push_back(new Starlink());
		
		time = computeTime();
		
		double rotationSpeed = computeRotationSpeed();
		earth->setAngularVelocity(rotationSpeed);
		
	}
	
	Orbit(Ship *ship, Earth *earth, list<Satellite*> satellites, vector<Star> &stars, double time) : ship(ship),
	earth(earth), satellites(satellites), stars(stars), time(time) {}
 
	virtual ~Orbit() {}

	double computeRotationSpeed();
	double computeTime();
	
	void handleInput(const Interface *pUI);
	void collisionDetection();
	void checkLifeSpan();
	void removeDeadSatellites();
	void move();
	void draw();
						 
private:
	Ship *ship;
	Earth *earth;
	vector<Star> stars;
	list<Satellite*> satellites;

	double time;  // (24 hours/day * 60 min/hour) /  30 frames/second = 48 seconds per frame

};

#endif /* orbit_h */
