#include "orbit.h"

/*********************************************
 * COMPUTE TIME
 *
 *********************************************/
double Orbit::computeTime()
{
	double dilation = HOURS_PER_DAY * MIN_PER_HOUR;
	return dilation / FRAME_RATE;
	
}
/*********************************************
 * COMPUTE ROTATION SPEED
 * Sets the amount of rotation change (in radians) that's applied
 * to an object (typically earth) as each new frame is drawn.
 *********************************************/
double Orbit::computeRotationSpeed()
{
	double dilation = HOURS_PER_DAY * MIN_PER_HOUR;
	double secondsPerDay = HOURS_PER_DAY * MIN_PER_HOUR * SEC_PER_MIN;
	double radiansPerDay = (PI * 2.0) / FRAME_RATE;
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
	list<Satellite*>::iterator iter;

	iter = satellites.begin();
	for (; iter != satellites.end(); iter++)
	{
		if ((*iter)->isAlive())
			(*iter)->move(time);
	}
	
	// always rotate earth
	earth->rotate(earth->getAngularVelocity());

	collisionDetection();
	removeDeadSatellites();
}

/*********************************************
 * COLLISION DETECTION
 *
 *********************************************/
void Orbit::collisionDetection()
{
	list<Satellite*>::iterator iter1;
	list<Satellite*>::iterator iter2;

	for (iter1 = satellites.begin(); iter1 != satellites.end(); ++iter1)
	{
		iter2 = iter1;
		++iter2;
		
		while (iter2 != satellites.end())
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
			++iter2;
		}
	}
}

/*********************************************
* CHECK LIFESPAN
*********************************************/
void Orbit::checkLifeSpan()
{
	list<Satellite*>::iterator iter;
	
	for (iter = satellites.begin(); iter != satellites.end(); iter++)
	{
		// check if projectile or fragment is past its lifespan
		if ( ((*iter)->isProjectile() || (*iter)->isFragment())
			&& (*iter)->isAlive() && (*iter)->getAge() >= (*iter)->getLifeSpan())
		{
			(*iter)->kill();
		}
	}
	
}

/*********************************************
* REMOVE DEAD SATELLITES
*********************************************/
void Orbit::removeDeadSatellites()
{
	list<Satellite*>::iterator iter = satellites.begin();
	
	while (iter != satellites.end())
	{
		if (!(*iter)->isAlive())
		{
			
			(*iter)->destroy(satellites);
			
			// delete dead satellite & set
			// it to null
			delete *iter;
			*iter = nullptr;
			
			// removes dead satellite & returns an iterator
			// to next valid satellite
			iter = satellites.erase(iter);
		
		}
		else if ((*iter)->hitEarth())
		{
			iter = satellites.erase(iter);
		}
		else if (((*iter)->isProjectile() || (*iter)->isFragment())
				 && (*iter)->pastLifeSpan())
		{
			iter = satellites.erase(iter);
		}
		else
		{
			++iter;
		}
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
	
	list<Satellite*>::iterator sats_Iter;

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
