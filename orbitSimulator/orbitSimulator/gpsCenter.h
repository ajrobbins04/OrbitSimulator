 
#ifndef gpsCenter_h
#define gpsCenter_h

#include "satellitePiece.h"

class GPSCenter : public SatellitePiece
{
public:
 
	GPSCenter() : SatellitePiece() {}
	GPSCenter(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) // radius = 7 px.
	{
		setInvisible(true);
		explode();
	}

	virtual ~GPSCenter() {}
	
	virtual bool isShip()       const { return false; }
	virtual bool isProjectile() const { return false; }
	virtual bool isPiece()      const { return true;  }
	virtual bool isFragment()   const { return false; }
	
	virtual void move(double time)
	{
		if (age >= 3)
			setInvisible(false);
		
		Acceleration aGravity = getGravity();
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
		
		increaseAge();
	}
	
	// breaks into 3 fragments
	virtual void destroy(list<Satellite*> &satellites)
	{
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, 20);
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, 190);
		satellites.push_back(sFragment2);
		
		SatelliteFragment *sFragment3 = new SatelliteFragment(*this, 250);
		satellites.push_back(sFragment3);
		 
	}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawGPSCenter(getPos(), getAngularVelocity());
	}

};

#endif /* gpsCenter_h */
