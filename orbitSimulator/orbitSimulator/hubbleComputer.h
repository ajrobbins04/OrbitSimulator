#ifndef hubbleComputer_h
#define hubbleComputer_h
 
#include "satellitePiece.h"

class HubbleComputer : public SatellitePiece
{
public:
	 
	HubbleComputer() : SatellitePiece() {}
	HubbleComputer(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) // radius = 7 px.
	{
		explode();
	}
	
	virtual ~HubbleComputer() {}
	
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
	
	// breaks into 2 fragments
	virtual void destroy(vector<Satellite*> &satellites)
	{
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, 120);
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, 60);
		satellites.push_back(sFragment2);
 
	}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawHubbleComputer(getPos(), getAngularVelocity());
	}
	
	
};
#endif /* hubbleComputer_h */
