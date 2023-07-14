
#ifndef dragonCenter_h
#define dragonCenter_h

#include "satellitePiece.h"

class DragonCenter : public SatellitePiece
{
public:
 
	DragonCenter() : SatellitePiece() {}
	DragonCenter(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) // radius = 7 px.
	{
		setInvisible(true);
		explode();
	}

	virtual ~DragonCenter() {}
	
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
	
	// breaks into 4 fragments
	virtual void destroy(list<Satellite*> &satellites)
	{
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, 250);
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, 340);
		satellites.push_back(sFragment2);
		
		SatelliteFragment *sFragment3 = new SatelliteFragment(*this, 120);
		satellites.push_back(sFragment3);
		
		SatelliteFragment *sFragment4 = new SatelliteFragment(*this, 30);
		satellites.push_back(sFragment4);
	}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawCrewDragonCenter(getPos(), getAngularVelocity());
	}
};

#endif /* dragonCenter_h */
