#include "projectile.h"

/*********************************************
 *  FIRE
 *  Fires the projectile
 *********************************************/
void Projectile::fire(double time)
{
	velocity.setSpeedDirection((velocity.getSpeed() + 9000), getDirection());
	pos.setMetersY(pos.getMetersY() + 19.0);
}
