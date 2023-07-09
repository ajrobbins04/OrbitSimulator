#include "projectile.h"

/*********************************************
* FIRE
*********************************************/
void Projectile::fire()
{
	pos.addMetersX(760 * direction.getDx());
	pos.addMetersY(760 * direction.getDy());

}

