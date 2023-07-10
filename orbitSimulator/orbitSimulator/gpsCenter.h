 
#ifndef gpsCenter_h
#define gpsCenter_h

#include "satellitePiece.h"

class GPSCenter : public SatellitePiece
{
public:
 
	GPSCenter() : SatellitePiece() {}
	GPSCenter(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) // radius = 7 px.
	{
		if (isYPositive())
			pos.addPixelsY(4.0); // moves GPSCenter 4px. from its point of creation
		else
			pos.addPixelsY(-4.0);
		
		velocity.setSpeed(velocity.getDx() + random(5000, 9000), velocity.getDy() + random(5000, 9000));

	}

	virtual ~GPSCenter() {}
	
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
	
	virtual void destroy(vector<Satellite*> &satellites)
	{
		kill();
	}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawGPSCenter(getPos(), rotation);
	}

};

#endif /* gpsCenter_h */
