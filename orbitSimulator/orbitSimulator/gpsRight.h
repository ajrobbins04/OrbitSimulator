
#ifndef gpsRight_h
#define gpsRight_h

#include "satellitePiece.h"

class GPSRight : public SatellitePiece
{
public:
 
	GPSRight() : SatellitePiece() {}
	GPSRight(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 8.0)  // radius = 8 px.
	{
		setInvisible(true);
		explode();
	}
	
	virtual ~GPSRight() {}
	
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
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, random(0, 100));
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, random(200, 300));
		satellites.push_back(sFragment2);
		
		SatelliteFragment *sFragment3 = new SatelliteFragment(*this, random(300, 360));
		satellites.push_back(sFragment3);
	}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawGPSRight(getPos(), getAngularVelocity());
	}

};

#endif /* gpsRight_h */
