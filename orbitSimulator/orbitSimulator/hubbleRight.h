#ifndef hubbleRight_h
#define hubbleRight_h

#include "satellitePiece.h"

class HubbleRight : public SatellitePiece
{
public:
 
	HubbleRight() : SatellitePiece() {}
	HubbleRight(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 8.0) // radius = 8 px.
	{
		setInvisible(true);
		explode();
	}
	
	virtual ~HubbleRight() {}
	
	virtual bool isShip()       const { return false; }
	virtual bool isProjectile() const { return false; }
	virtual bool isPiece()      const { return true;  }
	virtual bool isFragment()   const { return false; }
	
	virtual void move(double time)
	{
		if (age >= 3)
			setInvisible(false);
		
		Acceleration aGravity = getGravity();
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
		
		increaseAge();
	}
	
	// breaks into 2 fragments
	virtual void destroy(vector<Satellite*> &satellites)
	{
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, 300);
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, 100);
		satellites.push_back(sFragment2);
	}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawHubbleRight(getPos(), getAngularVelocity());
	}
};

#endif /* hubbleRight_h */
