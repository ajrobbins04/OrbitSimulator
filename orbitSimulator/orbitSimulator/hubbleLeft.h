#ifndef hubbleLeft_h
#define hubbleLeft_h

#include "satellitePiece.h"

class HubbleLeft : public SatellitePiece
{
public:
	 
	HubbleLeft() : SatellitePiece() {}
	HubbleLeft(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 8.0) // radius = 8 px.
	{
		setInvisible(true);
		explode();
	}
	
	virtual ~HubbleLeft() {}
	
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
	virtual void destroy(list<Satellite*> &satellites)
	{
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, random(200, 350));
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, random(0, 150));
		satellites.push_back(sFragment2);
	}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawHubbleLeft(getPos(), getAngularVelocity());
	}
};

#endif /* hubbleLeft_h */
