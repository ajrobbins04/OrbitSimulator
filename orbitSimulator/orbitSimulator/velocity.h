/***********************************************************************
 * Header File:
 *    Velocity
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *
 ************************************************************************/
#ifndef velocity_h
#define velocity_h

#include "acceleration.h"
#include "direction.h"

class Velocity
{
public:
	
	// constructors
	Velocity(): dx(0.0), dy(0.0) {}
	Velocity(double dx, double dy) : dx(dx), dy(dy) {}
	Velocity(const Velocity &rhs) : dx(rhs.dx), dy(rhs.dy) {}
	Velocity & operator = (const Velocity &rhs)
	{
		dx = rhs.dx;
		dy = rhs.dy;
		return *this;
	}
	
	// setters
	void setDx(double dx) { this->dx = dx; }
	void setDy(double dy) { this->dy = dy; }
	void setDxDy(double dx, double dy) {
		this->dx = dx;
		this->dy = dy;
	}
	
	void setDirection(const Direction &direction)
	{
		setSpeedDirection(getSpeed(), direction);
	}
	
	void setSpeed(double speed)
	{
		setSpeedDirection(speed, getDirection());
	}
	
	Direction getDirection() const;
	void setSpeedDirection(double speed, const Direction &dir);
	void setSpeedDirection(double speed, double degrees);
	
	// getters
	double getDx() const    { return dx; }
	double getDy() const    { return dy; }
	double getSpeed() const; // speed = velocity + acceleration

	
	Velocity getVelocity()   const
	{
		Velocity velocity(dx, dy);
		return velocity;
	}
	
   
	void addDx(double dx) { setDx(getDx() + dx); }
	void addDy(double dy) { setDy(getDy() + dy); }
	void addVelocity(const Velocity &velocity)
	{
		dx += velocity.dx;
		dy += velocity.dy;
	}
	
	void applyAcceleration(const Acceleration &acc);
	void updateVelocity(const Acceleration &acc, double time);
	
	void reverse()
	{
		dx *= -1.0;
		dy *= -1.0;
	}
	
	Velocity & operator += (const Velocity &rhs)
	{
		addVelocity(rhs);
		return *this;
	}
	
private:
	double dx;
	double dy;
	
};

#endif /* velocity_h */


