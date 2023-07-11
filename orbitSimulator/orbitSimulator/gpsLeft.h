

#ifndef gpsLeft_h
#define gpsLeft_h


#include "satellitePiece.h"

class GPSLeft : public SatellitePiece
{
public:
	 
	GPSLeft() : SatellitePiece() {}
	GPSLeft(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 8.0)  // radius = 8 px.
	{
		explode();
	}
	
	virtual ~GPSLeft() {}
	
	virtual bool isShip()       const { return false; }
	virtual bool isProjectile() const { return false; }
	virtual bool isPiece()      const { return true;  }
	virtual bool isFragment()   const { return false; }
	
	virtual void move(double time)
	{
		Acceleration aGravity = getGravity();
		
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
	}
	
	// breaks into 3 fragments
	virtual void destroy(vector<Satellite*> &satellites)
	{
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, 220);
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, 90);
		satellites.push_back(sFragment2);
		
		SatelliteFragment *sFragment3 = new SatelliteFragment(*this, 350);
		satellites.push_back(sFragment3);
	}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawGPSLeft(getPos(), getAngularVelocity());
	}
};

#endif /* gpsLeft_h */
