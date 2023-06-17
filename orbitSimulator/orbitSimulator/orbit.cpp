#include "orbit.h"

void Orbit::handleInput(const Interface *pUi)
{
	// ship turns counter-clockwise
	if (pUi->isLeft())
	{
		// rotates in radians
		dreamChaser->rotateShip(-0.1);
	}
	 
	// ship turns clockwise
	if (pUi->isRight())
	{
		// rotates in radians
		dreamChaser->rotateShip(0.1);
	}
  
	// add thrust
	if (pUi->isDown())
	{
		dreamChaser->applyThrust(2.0);
	}
  
	// launch projectile
	if (pUi->isSpace())
	{
		dreamChaser->launchProjectile();
	 }
 }

