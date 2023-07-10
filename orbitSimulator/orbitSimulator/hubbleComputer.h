#ifndef hubbleComputer_h
#define hubbleComputer_h
 
#include "satellitePiece.h"

class HubbleComputer : public SatellitePiece
{
public:
	 
	HubbleComputer() : SatellitePiece() {}
	HubbleComputer(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) {} // radius = 7 px.
	
	virtual ~HubbleComputer() {}
	
	virtual bool isShip()       const { return false; }
	virtual bool isProjectile() const { return false; }
	virtual bool isPiece()      const { return true;  }
	virtual bool isFragment()   const { return false; }
	
	virtual void move(double time)
	{
		Position posPrev = getPos();
		Acceleration aGravity = getGravity();
		
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
		updateDirection(posPrev, time);
	}
	
	virtual void destroy(vector<Satellite*> &satellites)
	{
		kill();
	}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawHubbleComputer(getPos(), rotation);
	}
	
	
};
#endif /* hubbleComputer_h */
