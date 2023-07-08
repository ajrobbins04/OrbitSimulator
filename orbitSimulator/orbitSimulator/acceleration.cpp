#include "acceleration.h"

/*********************************************
 * SET ACCELERATION
 * Sets acceleration based on its two components: its
 * magnitude and its direction 
 *  *********************************************/
void Acceleration::setAccelerationDirection(double acc, const Direction &dir)
{
	// ddx = acc * sin(angle)
	setDDx(acc * dir.getDx());
	
	// ddy = acc * cos(angle)
	setDDy(acc * dir.getDy());
}

