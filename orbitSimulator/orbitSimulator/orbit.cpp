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
 
	
	/*GPS *GPS_1 = new GPS(Position(0.0, 26560000.0), Velocity(-3880, 0.0));
	GPS *GPS_2 = new GPS(Position(23001634.72, 13280000.0), Velocity(-1940.0, 3360.18));
	GPS *GPS_3 = new GPS(Position(23001634.72, -13280000.0), Velocity(1940, 3360.18));
	GPS *GPS_4 = new GPS(Position(0.0, -26560000.0), Velocity(3880.0, 0.0));
	GPS *GPS_5 = new GPS(Position(-23001634.72, -13280000.0), Velocity(1940.0, -3360.18));
	GPS *GPS_6 = new GPS(Position(-23001634.72, 13280000.0), Velocity(-1940.0, -3360.18));
	
	GPS *GPS_1 = new GPS(1);
	GPS *GPS_2 = new GPS(2);
	GPS *GPS_3 = new GPS(3);
	GPS *GPS_4 = new GPS(4);
	GPS *GPS_5 = new GPS(5);
	GPS *GPS_6 = new GPS(6);
	
	satellites.push_back(GPS_1);
	satellites.push_back(GPS_2);
	satellites.push_back(GPS_3);
	satellites.push_back(GPS_4);
	satellites.push_back(GPS_5);
	satellites.push_back(GPS_6);*/
	
	//Sputnik *sputnik = new Sputnik(Position(-36515095.13, 21082000.0), Velocity(2050.0, 2684.68));
	// hubble (Position(0.0, -42164000.0), Velocity(3100.0, 0.0));
	
	//Dragon *dragon = new Dragon(Position(0.0, 8000000.0), Velocity(-7900.0, 0.0));
	
	//Starlink *starlink = new Starlink(Position(0.0, -13020000.0), Velocity(5800.0, 0.0));
	
	
	Ship *ship = new Ship();
	satellites.push_back(ship);
 
	GPS *GPS_1 = new GPS(1);
	GPS *GPS_2 = new GPS(2);
	GPS *GPS_3 = new GPS(3);
	GPS *GPS_4 = new GPS(4);
	GPS *GPS_5 = new GPS(5);
	GPS *GPS_6 = new GPS(6);
	
	satellites.push_back(GPS_1);
	satellites.push_back(GPS_2);
	satellites.push_back(GPS_3);
	satellites.push_back(GPS_4);
	satellites.push_back(GPS_5);
	satellites.push_back(GPS_6);

	Sputnik *sputnik = new Sputnik();
	satellites.push_back(sputnik);
	
	Hubble *hubble = new Hubble();
	satellites.push_back(hubble);
	
	Dragon *dragon = new Dragon();
	satellites.push_back(dragon);
	
	Starlink *starlink = new Starlink();
	satellites.push_back(starlink);

	
	double frameRate = 30.0;    // OpenGL draws 30 frames/second
	double hoursPerDay = 24.0;
	double minPerHour = 60.0;
	double secondsPerMin = 60.0;
	
	double secondsPerDay = hoursPerDay * minPerHour * secondsPerMin;
	double dilation = hoursPerDay * minPerHour;
	double time = dilation / frameRate;

	double rotationSpeed = computeRotationSpeed(frameRate, secondsPerDay, dilation);
	earth->setAngularVelocity(rotationSpeed);
	
	Orbit orbit(ship, earth, satellites, stars, time);

	return orbit;
 
}

/*********************************************
 * COMPUTE ROTATION SPEED
 * Sets the amount of rotation change (in radians) that's applied
 * to an object (typically earth) as each new frame is drawn.
 *********************************************/
double computeRotationSpeed(double frameRate, double secondsPerDay, double dilation)
{
	double radiansPerDay = (M_PI * 2.0) / frameRate;
	double radiansPerFrame =  -(radiansPerDay) * (dilation / secondsPerDay);
 
	return radiansPerFrame;
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
	vector<Satellite*>::iterator iter;

	iter = satellites.begin();
	for (; iter != satellites.end(); iter++)
	{
		if ((*iter)->isAlive())
			(*iter)->move(time);
	}
	
	// always rotate earth
	earth->rotate(earth->getAngularVelocity());

	collisionDetection();
	checkEarthReEntry();
	checkLifeSpan();
	removeDeadSatellites();
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
			if  ((*iter1)->isAlive() && (*iter2)->isAlive() &&
				 !(*iter1)->isInvisible() && !(*iter2)->isInvisible())
			{
				double distance = computeDistance((*iter1)->getPos(), (*iter2)->getPos());
				
				if (distance < (*iter1)->getRadius() + (*iter2)->getRadius())
				{
					(*iter1)->kill();
					(*iter2)->kill();
				}
			}
		}
	}
}

/*********************************************
* REMOVE EARTH RE-ENTRY
* Removes a satellite has re-entered the
* Earth's atmosphere. This action will
* not result in broken-off pieces or fragments.
*********************************************/
void Orbit::checkEarthReEntry()
{
	vector<Satellite*>::iterator iter;
	 
	for (iter = satellites.begin(); iter != satellites.end();)
	{
		double height = (*iter)->getAltitude();
	
		if (height <= 0)
		{
			(*iter)->kill(); // gets reabsorbed in earth's atmosphere
			Satellite* pSatellite = *iter;
			delete pSatellite;
			pSatellite = NULL;
			
			// erase the satellite & update the iterator
			iter = satellites.erase(iter);
		}
		else
			++iter;
	}
}

/*********************************************
* CHECK LIFESPAN
*********************************************/
void Orbit::checkLifeSpan()
{
	vector<Satellite*>::iterator iter1;
	
	for (iter1 = satellites.begin(); iter1 != satellites.end(); iter1++)
	{
		// check if projectile or fragment is past its lifespan
		if ( ((*iter1)->isProjectile() || (*iter1)->isFragment())
			&& (*iter1)->isAlive() && (*iter1)->getAge() >= (*iter1)->getLifeSpan())
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
	vector<Satellite*>::iterator iter = satellites.begin();

	while (iter != satellites.end())
	{
		if (!(*iter)->isAlive() && (*iter) != NULL)
		{
			(*iter)->destroy(satellites); // create any potential pieces/fragments
			
			Satellite* pSatellite = *iter;
			delete pSatellite;
			pSatellite = NULL;
			
			// erase the satellite & update the iterator
			iter = satellites.erase(iter);
		}
		else
			++iter;
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
			(*sats_Iter)->draw(gout);
	}
 
	vector<Star>::iterator stars_Iter;

	stars_Iter = stars.begin();
	for (; stars_Iter != stars.end(); stars_Iter++)
	{
		stars_Iter->draw(gout);
	}
	
	earth->draw(gout);
}
