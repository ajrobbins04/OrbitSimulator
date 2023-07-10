#ifndef hubbleTelescope_h
#define hubbleTelescope_h

#include "satellitePiece.h"

class HubbleTelescope : public SatellitePiece
{
public:
	 
	HubbleTelescope() : SatellitePiece() {}
	HubbleTelescope(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 10.0) // radius = 10 px.
	{
		explode();
	}
	
	virtual ~HubbleTelescope() {}
	
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
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, 230);
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, 10);
		satellites.push_back(sFragment2);
		
		SatelliteFragment *sFragment3 = new SatelliteFragment(*this, 150);
		satellites.push_back(sFragment3);
	}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawHubbleTelescope(getPos(), rotation);
	}
};

#endif /* hubbleTelescope_h */
