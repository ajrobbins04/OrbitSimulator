 
#ifndef starlinkRight_h
#define starlinkRight_h

#include "satellitePiece.h"

class StarlinkArray : public SatellitePiece
{
public:
 
	StarlinkArray() : SatellitePiece() {}
	StarlinkArray(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) // radius = 7 px.
	{
		explode();
	}

	virtual ~StarlinkArray() {}
	
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
		gout.drawStarlinkArray(getPos(), rotation);
	}
};

#endif /* starlinkArray_h */
