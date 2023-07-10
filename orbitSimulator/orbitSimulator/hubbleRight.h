#ifndef hubbleRight_h
#define hubbleRight_h

#include "satellitePiece.h"

class HubbleRight : public SatellitePiece
{
public:
 
	HubbleRight() : SatellitePiece() {}
	HubbleRight(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 8.0) {} // radius = 8 px.
	
	virtual ~HubbleRight() {}
	
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
		gout.drawHubbleRight(getPos(), rotation);
	}
};

#endif /* hubbleRight_h */
