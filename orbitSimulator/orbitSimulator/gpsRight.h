
#ifndef gpsRight_h
#define gpsRight_h

#include "satellitePiece.h"

class GPSRight : public SatellitePiece
{
public:
 
	GPSRight() : SatellitePiece() {}
	GPSRight(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 8.0)  // radius = 8 px.
	{
		explode();
	}
	
	virtual ~GPSRight() {}
	
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
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, 180);
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, 300);
		satellites.push_back(sFragment2);
		
		SatelliteFragment *sFragment3 = new SatelliteFragment(*this, 0);
		satellites.push_back(sFragment3);
	}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawGPSRight(getPos(), rotation);
	}

};

#endif /* gpsRight_h */
