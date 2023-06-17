/***********************************************************************
 * Header File:
 *    Point : The representation of a position
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen
 *    or the location on the field.
 ************************************************************************/

#ifndef position_h
#define position_h

#include <iostream>
#include <cmath>

class TestPosition;
class Acceleration;
class Velocity;

/*********************************************
 * Position
 * A single position on the field in Meters
 *********************************************/
class Position
{
public:
	friend TestPosition;
   
	// constructors
	Position() : x(0.0), y(0.0) {}
	Position(float x, float y);
	Position(const Position & pt) : x(pt.x), y(pt.y) {}
	Position& operator = (const Position& pt);

	// getters
	float getMetersX()       const { return x;                    }
	float getMetersY()       const { return y;                    }
	float getPixelsX()       const { return x / metersFromPixels; }
	float getPixelsY()       const { return y / metersFromPixels; }

	// setters
	void setMeters(float xMeters, float yMeters) {x = xMeters; y = yMeters; }
	void setMetersX(float xMeters)       { x = xMeters;           }
	void setMetersY(float yMeters)       { y = yMeters;           }
	void setPixelsX(float xPixels)       { x = xPixels * metersFromPixels;          }
	void setPixelsY(float yPixels)       { y = yPixels * metersFromPixels;          }
	void addMetersX(float dxMeters)      { setMetersX(getMetersX() + dxMeters);     }
	void addMetersY(float dyMeters)      { setMetersY(getMetersY() + dyMeters);     }
	void addPixelsX(float dxPixels)      { setPixelsX(getPixelsX() + dxPixels);     }
	void addPixelsY(float dyPixels)      { setPixelsY(getPixelsY() + dyPixels);     }

	// deal with the ratio of meters to pixels
	void setZoom(float metersFromPixels)
	{
	   this->metersFromPixels = metersFromPixels;
	}
	float convertToMeters(float pixels) const { return pixels * metersFromPixels; }
	float getZoom() const { return metersFromPixels; }

private:
	float x;                 // horizontal position
	float y;                 // vertical position
	static double metersFromPixels;
};

/*********************************************
 * COMPUTE DISTANCE
 * Find the distance between two positions
 *********************************************/
inline float computeDistance(const Position& pos1, const Position& pos2)
{
   return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (pos1.getMetersX() - pos2.getMetersX()) +
			   (pos1.getMetersY() - pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
}

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in,        Position& pt);


/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
	float x;
	float y;
};

#endif /* position_h */



