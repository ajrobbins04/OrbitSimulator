 
#ifndef gpsCenter_h
#define gpsCenter_h

#include "satellitePiece.h"

class GPSCenter : public SatellitePiece
{
public:
 
	GPSCenter() : SatellitePiece() {}
	GPSCenter(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) // radius = 7 px.
	{
		//moveForward(512000); // moves GPSCenter 160 meters from its point of creation
		//velocity.setSpeed(velocity.getSpeed() + random(5000, 9000));
		direction.setDegrees(180);
		pos.setPixelsX(700);
		pos.setPixelsY(-300);
		moveForward(512000);
		double x = pos.getPixelsX();
		double y = pos.getPixelsY();
		cout << x << endl;
		cout << y << endl;
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
