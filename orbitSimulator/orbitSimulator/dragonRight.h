
#ifndef dragonRight_h
#define dragonRight_h

#include "satellitePiece.h"

class DragonRight : public SatellitePiece
{
public:
 
	DragonRight() : SatellitePiece() {}
	DragonRight(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) // radius = 7 px.
	{
		explode();
	}

	virtual ~DragonRight() {}
	
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
		gout.drawCrewDragonRight(getPos(), rotation);
	}
};

#endif /* dragonRight_h */
