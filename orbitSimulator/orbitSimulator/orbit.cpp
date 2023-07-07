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
	
	// create a random position for the ship's
	// starting point
	Position shipPos;
	shipPos.setPixelsX(-450.0);
	shipPos.setPixelsY(450.0);
	
	Position shipFrontPos;
	shipFrontPos.setPixelsX(shipPos.getPixelsX());
	shipFrontPos.setPixelsY(shipPos.getPixelsY() + 19.0);
	
	// create the ship
	Ship *ship = new Ship(shipPos, Velocity(0.0, 0.0), shipFrontPos);
	satellites.push_back(ship);
	
	GPS *GPS_1 = new GPS(Position(0.0, 26560000.0), Velocity(-3880, 0.0));
	GPS *GPS_2 = new GPS(Position(23001634.72, 13280000.0), Velocity(-1940.0, 3360.18));
	GPS *GPS_3 = new GPS(Position(23001634.72, -13280000.0), Velocity(1940, 3360.18));
	GPS *GPS_4 = new GPS(Position(0.0, -26560000.0), Velocity(3880.0, 0.0));
	GPS *GPS_5 = new GPS(Position(-23001634.72, -13280000.0), Velocity(1940.0, -3360.18));
	GPS *GPS_6 = new GPS(Position(-23001634.72, 13280000.0), Velocity(-1940.0, -3360.18));
	
	satellites.push_back(GPS_1);
	satellites.push_back(GPS_2);
	satellites.push_back(GPS_3);
	satellites.push_back(GPS_4);
	satellites.push_back(GPS_5);
	satellites.push_back(GPS_6);
	
	Sputnik *sputnik = new Sputnik(Position(-36515095.13, 21082000.0), Velocity(2050.0, 2684.68));
	satellites.push_back(sputnik);
	
	Hubble *hubble = new Hubble(Position(0.0, -42164000.0), Velocity(3100.0, 0.0));
	satellites.push_back(hubble);
	
	Dragon *dragon = new Dragon(Position(0.0, 8000000.0), Velocity(-7900.0, 0.0));
	satellites.push_back(dragon);
	
	Starlink *starlink = new Starlink(Position(0.0, -13020000.0), Velocity(5800.0, 0.0));
	satellites.push_back(starlink);
	
	double frameRate = 30.0;    // OpenGL draws 30 frames/second
	double hoursPerDay = 24.0;
	double minPerHour = 60.0;
	double secondsPerMin = 60.0;
	
	double secondsPerDay = hoursPerDay * minPerHour * secondsPerMin;
	double dilation = hoursPerDay * minPerHour;
	double time = dilation / frameRate;

	Orbit orbit(ship, earth, satellites, stars, time);
	
	double rotationSpeed = orbit.computeRotationSpeed(frameRate, secondsPerDay, dilation);
	orbit.setRotationSpeed(rotationSpeed);
	
	return orbit;
 
}

/*********************************************
 * HANDLE INPUT
 *
 *********************************************/
void Orbit::handleInput(const Interface *pUI)
{
 	ship->input(pUI, time, satellites);
}

/*********************************************
 * MOVE
 * Moves everything currently in orbit.
 *********************************************/
void Orbit::move()
{
	vector<Satellite*>::iterator sats_Iter;

	sats_Iter = satellites.begin();
	for (; sats_Iter != satellites.end(); sats_Iter++)
	{
		if ((*sats_Iter)->isAlive())
			(*sats_Iter)->move(time);
	}
	
	if (earth->isAlive())
		earth->rotate(earth->getRotationSpeed());
}

/*********************************************
 * COLLISION DETECTION
 *
 *********************************************/
void Orbit::collisionDetection()
{
	vector<Satellite*>::iterator iter1;
	vector<Satellite*>::iterator iter2;

	for (iter1 = satellites.begin(); iter1 != satellites.end(); iter1++)
	{
		for (iter2 = iter1 + 1; iter2 != satellites.end(); iter2++)
		{
			double collisionRange = computeDistance((*iter1)->getPos(), (*iter2)->getPos());
			double satelliteRadius1 = (*iter1)->getRadius();
			double satelliteRadius2 = (*iter2)->getRadius();
			
			// exclude bullets that originate from the ship
			if ((*iter2)->getRadius() != 20 && !(*iter1)->isShip())
			{
				if (collisionRange < satelliteRadius1 + satelliteRadius2)
				{
					(*iter1)->kill();
					(*iter2)->kill();
				}
			}
		}
	}

	for (iter1 = satellites.begin(); iter1 != satellites.end(); iter1++)
	{
		double height = (*iter1)->getAltitude();
	
		if (height <= 0)
		{
			(*iter1)->kill();
		}
	}
}

/*********************************************
* CHECK AGE
*********************************************/
void Orbit::checkAge()
{
	vector<Satellite*>::iterator iter1;
	
	for (iter1 = satellites.begin(); iter1 != satellites.end(); iter1++)
	{
		// check if projectile is past its lifespan
		if ( (*iter1)->isProjectile() && (*iter1)->isAlive() && (*iter1)->getAge() > 70)
		{
			(*iter1)->kill();
		}
	}
	
}

/*********************************************
* REMOVE DEAD SATELLITES
*********************************************/
void Orbit::removeDeadSatellites()
{
	vector<Satellite*>::iterator iter1 = satellites.begin();

	while (iter1 != satellites.end())
	{
		if (!(*iter1)->isAlive())
		{
		
			Satellite* pSatellite = *iter1;
			delete pSatellite;
			pSatellite = NULL;
			
			satellites.erase(iter1);
		}
		else
			++iter1;
	}
}

/*********************************************
 * DRAW
 * Draws everything currently in orbit.
 *********************************************/
void Orbit::draw()
{
	Position pt(0.0, 0.0);
 
	ogstream gout(pt);
	
	vector<Satellite*>::iterator sats_Iter;

	sats_Iter = satellites.begin();
	for (; sats_Iter != satellites.end(); sats_Iter++)
	{
		if ((*sats_Iter)->isAlive())
			(*sats_Iter)->draw((*sats_Iter)->getDirectionAngle(), gout);
	}
 
	vector<Star>::iterator stars_Iter;

	stars_Iter = stars.begin();
	for (; stars_Iter != stars.end(); stars_Iter++)
	{
		stars_Iter->draw(gout);
	}
	
	if (earth->isAlive())
	{
		earth->draw(earth->getDirectionAngle(), gout);
	}
}

/*********************************************
 * COMPUTE ROTATION SPEED
 * Sets the amount of rotation change (in radians) that's applied
 * to an object (typically earth) as each new frame is drawn.
 *********************************************/
double Orbit::computeRotationSpeed(double frameRate, double secondsPerDay, double dilation)
{
	double radiansPerDay = (M_PI * 2.0) / frameRate;
	double radiansPerFrame =  -(radiansPerDay) * (dilation / secondsPerDay);
 
	return radiansPerFrame;
}
