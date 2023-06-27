#include "acceleration.h"

/*********************************************
 * SET ACCELERATION
 * Sets the speed and direction.
 *********************************************/
void Acceleration::setAcc(double aGravity, const Direction &direction)
{
	setDDx(aGravity * direction.getDx());
	setDDy(aGravity * direction.getDy());
}

