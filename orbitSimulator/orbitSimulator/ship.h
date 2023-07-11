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
 
	Ship() : Satellite(Position(0.0, 0.0), 0.0, Velocity(0.0, 0.0)), thrust(false),
	shipFrontPos(Position(0.0, 760.0)), prevDir(0.0) {}
	
	Ship(const Position &pos, const Velocity &velocity, const Position &frontPos) :
	Satellite(pos, 10, velocity), thrust(false), shipFrontPos(frontPos), prevDir(0.0) {} // radius = 10px
	
	Ship(double x, double y): Satellite(Position(x, y), 0.0, Velocity(0.0, 0.0)), thrust(false) {}
	
	virtual ~Ship() {}
	
	void setThrust(bool thrust)     { this->thrust = thrust;   }
	void setPrevDir(double radians) { this->prevDir = radians; }
	
	bool getThrust() const         { return thrust;               }
	double getPrevDirAngle() const { return prevDir.getRadians(); }
	
	void input(const Interface *pUI, double time, vector<Satellite*> &satellites);
	void applyThrust(double time);
	
	double getShipFrontPosX() { return shipFrontPos.getMetersX(); }
	double getShipFrontPosY() { return shipFrontPos.getMetersY(); }
	
	void updateShipFrontPos(const Acceleration &aGravity, double time);
	void launchProjectile(vector<Satellite*> &satellites, double time);

	virtual bool isShip()       const { return true;  }
	virtual bool isProjectile() const { return false; }
	virtual bool isPiece()      const { return false; }
	virtual bool isFragment()   const { return false; }
	
	virtual void move(double time)
	{
		Acceleration aGravity = getGravity();
		updateShipFrontPos(aGravity, time);
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
	
	}
	
	virtual void destroy(vector<Satellite*> &satellites)
	{
		kill();
	}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawShip(getPos(), getAngularVelocity(), getThrust());
	}
 
	
private:                    // inherits pos, direction, radius, angularVelociy, alive,
	bool thrust;            // velocity, age, and lifeSpan
	Position shipFrontPos;
	Direction prevDir;
	
};
#endif
