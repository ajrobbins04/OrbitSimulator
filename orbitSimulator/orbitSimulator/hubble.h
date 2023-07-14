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

	Hubble(): Satellite() {

		pos.setMeters(0.0, -42164000.0);
		velocity.setDxDy(3100.0, 0.0);
		setRadius(pos.convertToMeters(10));
	}
	
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
	virtual void destroy(list<Satellite*> &satellites)
	{
		HubbleTelescope *hTelescope = new HubbleTelescope(*this, random(200, 270));
		satellites.push_back(hTelescope);
		
		HubbleComputer *hComputer = new HubbleComputer(*this, random(0, 70));
		satellites.push_back(hComputer);
		
		HubbleRight *hRight = new HubbleRight(*this, random(290, 360));
		satellites.push_back(hRight);
		
		HubbleLeft *hLeft = new HubbleLeft(*this, random(100, 170));
		satellites.push_back(hLeft);
	}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawHubble(getPos(), getAngularVelocity());
	}

	
private: // inherits pos, direction, radius, angularVelociy, alive,
		 // velocity, age, and lifeSpan
	
};

#endif /* hubble_h */
