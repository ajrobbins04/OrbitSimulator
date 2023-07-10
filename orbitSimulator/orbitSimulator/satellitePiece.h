/***********************************************************************
 * Header File:
 *    Satellite Piece
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *	  Represents a leftover piece of a whole satellite object
 *	  that experienced a collision.
 ************************************************************************/

#ifndef satellitePiece_h
#define satellitePiece_h

#include "satellite.h"

class SatellitePiece : public Satellite
{
public:
 
	SatellitePiece() : Satellite() {}
	SatellitePiece(const Satellite &rhs) : Satellite(rhs) {}
	SatellitePiece(const Satellite &rhs, double degrees, double radius) : Satellite(Position(rhs.getPos()), radius,
																Velocity(rhs.getVelocity()), Direction(degrees)) {}
	
	SatellitePiece(const Satellite &rhs, double degrees, const Velocity &v, double radius) :
	Satellite(Position(rhs.getPos()), radius, Velocity(v), Direction(degrees)) {}
	
	virtual ~SatellitePiece() {}

	virtual bool isShip()       const = 0;
	virtual bool isProjectile() const = 0;
	virtual bool isPiece()      const = 0;
	virtual bool isFragment()   const = 0;
	
	virtual void move(double time) = 0;
	virtual void destroy(vector<Satellite*> &satellites) = 0;
	virtual void draw(double rotation, ogstream & gout)  = 0;
	
};


#endif
