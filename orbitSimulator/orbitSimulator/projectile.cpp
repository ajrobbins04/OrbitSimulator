#include "projectile.h"

void Projectile::fire()
{
	projectilePath[0].setMetersX(pos.getMetersX());
	projectilePath[0].setMetersY(pos.getMetersY());
}

void Projectile::updateProjectilePath()
{
	for (int i = 7; i >= 1; --i)
	{
	   projectilePath[i] = projectilePath[i - 1];
	}
	
	projectilePath[0].setMetersX(pos.getMetersX());
	projectilePath[0].setMetersY(pos.getMetersY());
}
