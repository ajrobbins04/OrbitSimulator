/***********************************************************************
 * Header File:
 *    Ship
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *	  Ship inherits from the satellite class, but it includes
 *	  additional functionalities.
 ************************************************************************/

#ifndef ship_h
#define ship_h

#include "uiInteract.h"
#include "satellite.h"
#include "projectile.h"
#include <cmath>

class TestShip;

class Ship : public Satellite
{
public:
	friend TestShip;
	
	Ship() : Satellite(Position(0.0, 0.0), 10.0, Velocity(0.0, 0.0)), thrust(false) {

		// starts in top left corner of screen
		pos.setPixelsX(-450.0);
		pos.setPixelsY(450.0);
	}

	Ship(const Position &pos, const Velocity &velocity) :
	Satellite(pos, 10.0, velocity), thrust(false) {} // radius = 10px
	
	Ship(double x, double y): Satellite(Position(x, y), 0.0, Velocity(0.0, 0.0)), thrust(false) {}
	
	virtual ~Ship() {}
	
	void setThrust(bool thrust) { this->thrust = thrust; }
	bool getThrust() const      { return thrust;         }
	void applyThrust(double time);
	
	void input(const Interface *pUI, double time, vector<Satellite*> &satellites);
	void launchProjectile(vector<Satellite*> &satellites, double time);

	virtual bool isShip()       const { return true;  }
	virtual bool isProjectile() const { return false; }
	virtual bool isPiece()      const { return false; }
	virtual bool isFragment()   const { return false; }
	
	virtual void move(double time)
	{
		Acceleration aGravity = getGravity();
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
	}
	
	virtual void destroy(vector<Satellite*> &satellites) {}
	virtual void draw(ogstream & gout)
	{
		gout.drawShip(getPos(), getDirectionAngle(), getThrust());
	}
 
	
private:                    // inherits pos, direction, radius, angularVelociy, alive,
	bool thrust;            // velocity, age, and lifeSpan

};
#endif
