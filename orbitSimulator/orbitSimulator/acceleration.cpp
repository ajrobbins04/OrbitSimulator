#include "acceleration.h"

/*********************************************
 * SET ACCELERATION
 * Sets acceleration based on its two components: its
 * magnitude and its direction 
 *  *********************************************/
void Acceleration::setAcc(double aGravity, const Direction &direction)
{
	// ddx = acc * sin(angle)
	setDDx(aGravity * direction.getDx());
	
	// ddy = acc * cos(angle)
	setDDy(aGravity * direction.getDy());
}

