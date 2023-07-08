
#ifndef gpsRight_h
#define gpsRight_h

#include "satellitePiece.h"

class GPSRight : public SatellitePiece
{
public:
 
	GPSRight() : SatellitePiece() {}
	GPSRight(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 8.0) {} // radius = 8 px.
	
	virtual ~GPSRight();
	
	virtual bool isShip()       const { return false;  }
	virtual bool isProjectile() const { return false;  }
	/*virtual double getRadius()  const { return radius; }*/
	
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
		gout.drawGPSRight(getPos(), rotation);
	}

};

#endif /* gpsRight_h */
