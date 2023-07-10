

#ifndef dragonCenter_h
#define dragonCenter_h

#include "satellitePiece.h"

class DragonCenter : public SatellitePiece
{
public:
 
	DragonCenter() : SatellitePiece() {}
	DragonCenter(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) // radius = 7 px.
	{
		explode();
	}

	virtual ~DragonCenter() {}
	
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
		gout.drawCrewDragonCenter(getPos(), rotation);
	}
};

#endif /* dragonCenter_h */
