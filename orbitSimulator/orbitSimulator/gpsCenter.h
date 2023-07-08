 
#ifndef gpsCenter_h
#define gpsCenter_h

#include "satellitePiece.h"

class GPSCenter : public SatellitePiece
{
public:
 
	GPSCenter() : SatellitePiece() {}
	GPSCenter(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) {} // radius = 7 px.
	
	virtual ~GPSCenter() {}
	
	virtual bool isShip()       const { return false;  }
	virtual bool isProjectile() const { return false;  }
	
	virtual void move(double time)
	{
		Position posPrev = getPos();
		Acceleration aGravity = getGravity();
		
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
		updateDirection(posPrev, time);
	}
	
	virtual void destroy(vector<Satellite*> satellites)
	{
		kill();
	}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawGPSCenter(getPos(), rotation);
	}

};

#endif /* gpsCenter_h */
