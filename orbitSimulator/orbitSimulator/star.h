/***********************************************************************
 * Header File:
 *    Star : The representation of a star in the orbit simulator
 * Author:
 *    Amber Robbins, Martin Nkala
 * Summary:
 *
 ************************************************************************/

#ifndef star_h
#define star_h

#include "position.h"
#include "uiDraw.h"


class Star
{
public:
	Star(): pos(0.0, 0.0), phaseStar(0) {}
	Star(const Position &ptUpperRight): pos(0.0, 0.0), phaseStar(0) {
		
		this->phaseStar = 0;
		pos.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
		pos.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
		
	}
	 
	void draw(ogstream & gout)
	{
		gout.drawStar(getPos(), getPhaseStar());
		advancePhaseStar();
	}
	 
	Position      getPos()       const { return pos;       }
	unsigned char getPhaseStar() const { return phaseStar; }
	
	void advancePhaseStar() { this->phaseStar += 1; }
	void setPhaseStar(unsigned char phaseStar) { this->phaseStar = phaseStar; }

	
private:
	Position pos;
	unsigned char phaseStar; // within 0 - 255 range
	
};

#endif /* star_h */
