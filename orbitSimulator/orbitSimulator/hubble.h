/***********************************************************************
 * Header File:
 *    Hubble
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *	  Sputnik is a whole satellite, and thus inherits from
 *	  the Satellite class.
 ************************************************************************/
#ifndef hubble_h
#define hubble_h

#include "satellite.h"
#include "hubbleTelescope.h"
#include "hubbleComputer.h"
#include "hubbleLeft.h"
#include "hubbleRight.h"

class TestHubble;

class Hubble : public Satellite
{
public:
	friend TestHubble;
	
	Hubble(): Satellite() {}
	Hubble(const Hubble &rhs) : Satellite(rhs) {}
	Hubble(const Hubble &rhs, const Direction &d): Satellite(rhs, d) {}
	Hubble(const Position &pos): Satellite(Position(pos), 10, Velocity(0, 0)) {}  // used in test cases
	Hubble(const Position &pos, const Velocity &velocity): Satellite(pos, 10, velocity) {}      // radius = 10px
	
	virtual ~Hubble() {}
	
	virtual bool isShip()       const { return false; }
	virtual bool isProjectile() const { return false; }
	virtual bool isPiece()      const { return false; }
	virtual bool isFragment()   const { return false; }
	
	virtual void move(double time)
	{
		Acceleration aGravity = getGravity();
			
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
	}
	
	// breaks into 4 pieces
	virtual void destroy(vector<Satellite*> &satellites)
	{
		HubbleTelescope *hTelescope = new HubbleTelescope(*this, 75);
		satellites.push_back(hTelescope);
		
		HubbleComputer *hComputer = new HubbleComputer(*this, 345);
		satellites.push_back(hComputer);
		
		HubbleRight *hRight = new HubbleRight(*this, 160);
		satellites.push_back(hRight);
		
		HubbleLeft *hLeft = new HubbleLeft(*this, 275);
		satellites.push_back(hLeft);
	}
	
	virtual void draw(double rotation, ogstream & gout)
	{
		gout.drawHubble(getPos(), rotation);
	}
	
private:
	// inherits pos, radius, velocity, direction, alive,
	// angularVelocity and age
};

#endif /* hubble_h */
