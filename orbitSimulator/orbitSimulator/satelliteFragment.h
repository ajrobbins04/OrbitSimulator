/***********************************************************************
 * Header File:
 *    Satellite Fragment
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *	  Represents a leftover fragment of a satellite object
 *	  piece that experienced a collision.
 ************************************************************************/

#ifndef satelliteFragment_h
#define satelliteFragment_h

#include "satellite.h"
#include "satellitePiece.h"

class SatelliteFragment : public Satellite
{
public:
	
	SatelliteFragment() : Satellite() {}
	
	SatelliteFragment(const Satellite &rhs, double degrees) : Satellite(Position(rhs.getPos()), 2.0,  // radius = 2 px.
															  Velocity(rhs.getVelocity()), Direction(degrees)) {}
	
	SatelliteFragment(const SatellitePiece &rhs, double degrees) : Satellite(Position(rhs.getPos()), 2.0,
																   Velocity(rhs.getVelocity()), Direction(degrees)) {}

	virtual ~SatelliteFragment() {}
	
	virtual bool isShip()       const { return false; }
	virtual bool isProjectile() const { return false; }
	virtual bool isPiece()      const { return false; }
	virtual bool isFragment()   const { return true;  }

	
	virtual void move(double time)
	{
		Position posPrev = getPos();
		Acceleration aGravity = getGravity();
		
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
		updateDirection(posPrev, time);
	}
	virtual void destroy(vector<Satellite*> satellites)
	{
		kill();
	}
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawFragment(getPos(), rotation);
	}
	
};
  
#endif /* satelliteFragment_h */
