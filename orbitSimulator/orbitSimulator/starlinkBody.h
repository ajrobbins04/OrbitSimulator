 
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
	
	// breaks into 3 fragments
	virtual void destroy(vector<Satellite*> &satellites)
	{
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, 230);
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, 10);
		satellites.push_back(sFragment2);
		
		SatelliteFragment *sFragment3 = new SatelliteFragment(*this, 150);
		satellites.push_back(sFragment3);
	}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawStarlinkBody(getPos(), getAngularVelocity());
	}
};

#endif /* starlinkBody_h */
