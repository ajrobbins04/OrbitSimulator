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

class SatellitePiece : public Satellite
{
public:
 /*
	SatellitePiece() : SpaceObject(0.0, 0.0), velocity(0.0, 0.0), age(0.0), angularVelocity(0.0) {}
	
	SatellitePiece(const Satellite &s, const Direction &dir) : SpaceObject(s.pos.getMetersX(), s.pos.getMetersY(), 0.0, Direction(dir.getRadians())),
	velocity(s.velocity.getDx(), s.velocity.getDy()), age(0.0), angularVelocity(0.0) {}
	
	SatellitePiece(double x, double y): SpaceObject(Position(x, y), 0.0), velocity(0.0, 0.0),
	age(0.0), angularVelocity(0.0)  {}
	
	SatellitePiece(double x, double y, double radius): SpaceObject(Position(x, y), radius), velocity(0.0, 0.0),
	age(0.0), angularVelocity(0.0) {}
	
	SatellitePiece(const Position &pos, float radius, const Velocity &velocity) :
	SpaceObject(pos, radius), velocity(velocity), age(0.0), angularVelocity(0.0)  {}
	
	SatellitePiece(const Position &pos, float radius, const Velocity &velocity, const Direction &dir) :
	SpaceObject(pos, radius, dir), velocity(velocity), age(0.0), angularVelocity(0.0)  {}
	
	virtual ~Satellite() {};

	void addKick();
	
	virtual bool isShip() const = 0;
	virtual bool isProjectile() const = 0;
	virtual void move(double time) = 0;
	virtual double getRadius() const = 0;
	virtual void draw(double rotation, ogstream & gout) = 0;
	
private:*/
 
   
};


#endif /* satellitePiece_h */
