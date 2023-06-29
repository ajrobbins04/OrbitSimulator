#include "orbit.h"

void Orbit::draw(double frameRate)
{
	//frameRate = 80;
	Position pt;
	ogstream gout(pt);
	double rotation = frameRate;
	
	while (earth->isAlive())
	{
		earth->draw(rotation);
		rotation -= -0.01;
	}
	

}
