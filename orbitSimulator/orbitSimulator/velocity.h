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
#define TIME 48

#include "acceleration.h"
#include "direction.h"

class Velocity
{
public:
	
	// constructors
	Velocity(): dx(0.0), dy(0.0) {}
	Velocity(float dx, float dy) : dx(dx), dy(dy) {}
	Velocity(const Velocity &rhs) : dx(rhs.dx), dy(rhs.dy) {}
	Velocity & operator = (const Velocity &rhs)
	{
		dx = rhs.dx;
		dy = rhs.dy;
		return *this;
	}
	
	// setters
	void setDx(float dx) { this->dx = dx; }
	void setDy(float dy) { this->dy = dy; }
	void setDxDy(float dx, float dy) {
		this->dx = dx;
		this->dy = dy;
	}
	
	void setDirection(const Direction &direction)
	{
		setSpeedDirection(getSpeed(), direction);
	}
	
	void setSpeed(float speed)
	{
		setSpeedDirection(speed, getDirection());
	}
	
	void setSpeedDirection(float speed, const Direction &direction);
	
	// getters
	float getDx() const    { return dx; }
	float getDy() const    { return dy; }
	float getSpeed() const;
	
	Direction getDirection() const;
	Velocity getVelocity()   const
	{
		Velocity velocity(dx, dy);
		return velocity;
	}
	
   
	void addDx(float dx) { setDx(getDx() + dx); }
	void addDy(float dy) { setDy(getDy() + dy); }
	void addVelocity(const Velocity &velocity)
	{
		dx += velocity.dx;
		dy += velocity.dy;
	}
	
	void updateVelocity(const Acceleration &acc);
	void updateVelocity(const Acceleration &acc, float time);
	void updateVelocity(const Acceleration &acc, float time, float thrustAmount);
	
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
	float dx;
	float dy;
	
};

#endif /* velocity_h */


