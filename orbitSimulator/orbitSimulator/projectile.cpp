#include "projectile.h"

/*********************************************
* FIRE
*********************************************/
void Projectile::fire()
{
	projectilePath[0].setMetersX(pos.getMetersX());
	projectilePath[0].setMetersY(pos.getMetersY());
}

/*********************************************
* UPDATE PROJECTILE PATH
*********************************************/
void Projectile::updateProjectilePath()
{
	for (int i = 7; i >= 1; --i)
	{
	   projectilePath[i] = projectilePath[i - 1];
	}
	
	projectilePath[0].setMetersX(pos.getMetersX());
	projectilePath[0].setMetersY(pos.getMetersY());
}
