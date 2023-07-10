
#ifndef dragonLeft_h
#define dragonLeft_h

#include "satellitePiece.h"

class DragonLeft : public SatellitePiece
{
public:
 
	DragonLeft() : SatellitePiece() {}
	DragonLeft(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) // radius = 7 px.
	{
		explode();
	}

	virtual ~DragonLeft() {}
	
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
		gout.drawCrewDragonLeft(getPos(), rotation);
	}
};

#endif /* dragonLeft_h */
