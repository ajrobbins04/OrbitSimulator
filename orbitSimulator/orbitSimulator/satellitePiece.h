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
	
	SatellitePiece(const Satellite &s, double degrees) : Satellite(Position(s.getPosX(), s.getPosY()), 0,
																Velocity(s.getVelocity()), Direction(degrees)) {}
	
	virtual ~SatellitePiece() {}

	// addKick();
	
	virtual bool isShip() const = 0;
	virtual bool isProjectile() const = 0;
	virtual void move(double time) = 0;
	virtual double getRadius() const = 0;
	virtual void draw(double rotation, ogstream & gout) = 0;
	
private:
 
   
};


#endif /* satellitePiece_h */
