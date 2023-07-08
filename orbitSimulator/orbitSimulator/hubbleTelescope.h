#ifndef hubbleTelescope_h
#define hubbleTelescope_h

#include "satellitePiece.h"

class HubbleTelescope : public SatellitePiece
{
public:
	 
	HubbleTelescope() : SatellitePiece() {}
	HubbleTelescope(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 10.0) {} // radius = 10 px.
	
	virtual ~HubbleTelescope() {}
	
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
		gout.drawHubbleTelescope(getPos(), rotation);
	}
};

#endif /* hubbleTelescope_h */
