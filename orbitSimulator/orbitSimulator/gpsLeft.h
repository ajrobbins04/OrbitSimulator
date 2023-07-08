

#ifndef gpsLeft_h
#define gpsLeft_h

#include "gps.h"
#include "satellitePiece.h"

class GPSLeft : public SatellitePiece
{
public:
	 
	GPSLeft() : SatellitePiece() {}
	GPSLeft(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 8.0) {} // radius = 8 px.
	
	virtual ~GPSLeft() {};
	
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
		
	}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawGPSLeft(getPos(), rotation);
	}
	
	
};
#endif /* gpsLeft_h */
