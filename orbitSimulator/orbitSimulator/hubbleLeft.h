#ifndef hubbleLeft_h
#define hubbleLeft_h

#include "satellitePiece.h"

class HubbleLeft : public SatellitePiece
{
public:
	 
	HubbleLeft() : SatellitePiece() {}
	HubbleLeft(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 8.0) {} // radius = 8 px.
	
	virtual ~HubbleLeft() {}
	
	virtual bool isShip()       const { return false; }
	virtual bool isProjectile() const { return false; }
	virtual bool isPiece()      const { return true;  }
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
		gout.drawHubbleLeft(getPos(), rotation);
	}
};

#endif /* hubbleLeft_h */
