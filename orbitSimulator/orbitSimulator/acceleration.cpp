#include "acceleration.h"

/*********************************************
 * SET ACCELERATION
 * Sets the speed and direction.
 *********************************************/
void Acceleration::setAcc(float gravity, const Direction &direction)
{
	setDDx(gravity * direction.getDx());
	setDDy(gravity * direction.getDy());
}

