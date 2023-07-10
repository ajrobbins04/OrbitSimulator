 
#ifndef starlinkBody_h
#define starlinkBody_h

#include "satellitePiece.h"

class StarlinkBody : public SatellitePiece
{
public:
 
	StarlinkBody() : SatellitePiece() {}
	StarlinkBody(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) // radius = 7 px.
	{
		explode();
	}

	virtual ~StarlinkBody() {}
	
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
		gout.drawStarlinkBody(getPos(), rotation);
	}
};

#endif /* starlinkBody_h */
