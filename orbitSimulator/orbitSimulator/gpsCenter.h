
#ifndef gpsCenter_h
#define gpsCenter_h

#include "satellitePiece.h"

class GPSCenter : public SatellitePiece
{
public:
	
	GPSCenter() : SatellitePiece() {}
	GPSCenter(const Satellite &s, double degrees) : SatellitePiece(s, degrees) {}
	
	virtual ~GPSCenter() {};
	
	virtual bool isShip()       const { return false;  }
	virtual bool isProjectile() const { return false;  }
	virtual double getRadius()  const { return radius; }
	
	virtual void move(double time)
	{
		Position posPrev = getPos();
		Acceleration aGravity = getGravity();
		
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
		updateDirection(posPrev, time);
	}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawGPSCenter(getPos(), rotation);
	}

	
};

#endif /* gpsCenter_h */
