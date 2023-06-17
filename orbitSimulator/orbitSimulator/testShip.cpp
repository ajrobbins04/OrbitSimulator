#include "testShip.h"

void TestShip::run()
{
	test_rotate_right();
    test_rotate_left();
	test_rotate_alternating();
	
	test_applyThrust_stationary();
	test_applyThrust_moving();
	test_applyThrust_double();
}


void TestShip::test_rotate_right()
{
	Ship ship(Position(0.0, 26560000), 10, Velocity(-3.880, 0));
	float originalRadians = ship.direction.getRadians();

	// equivalent of clicking right keyboard arrow 3 times
	ship.rotateShip(0.1);
	ship.rotateShip(0.1);
	ship.rotateShip(0.1);
	
	float currentRadians = ship.direction.getRadians();
	float differenceRadians = abs(currentRadians - originalRadians);

	assert(differenceRadians > 0.3 && differenceRadians < 0.3000001);

}

void TestShip::test_rotate_left()
{
	Ship ship(Position(0.0, 26560000), 10, Velocity(-3.880, 0));
	float originalRadians = ship.direction.getRadians();
	
	// equivalent of clicking right keyboard arrow 3 times
	ship.rotateShip(-0.1);
	ship.rotateShip(-0.1);
	ship.rotateShip(-0.1);
	
	float currentRadians = ship.direction.getRadians();
	float differenceRadians = abs(currentRadians - originalRadians);

	assert(differenceRadians > 0.3 && differenceRadians < 0.3000001);
}


void TestShip::test_rotate_alternating()
{
	Ship ship(Position(0, -26560000), 10, Velocity(3880, 0));
	float originalRadians = ship.direction.getRadians();

	ship.rotateShip(-0.1); // click left
	ship.rotateShip(0.1);  // click right
	ship.rotateShip(0.1);  // click right
	ship.rotateShip(-0.1); // click left
	ship.rotateShip(0.1);  // click right
	ship.rotateShip(0.1);  // click right
	
	float currentRadians = ship.direction.getRadians();
	float differenceRadians = abs(currentRadians - originalRadians);

	assert(differenceRadians > 0.2 && differenceRadians < 0.2000001);
}

void TestShip::test_applyThrust_stationary()
{
	Ship ship(Position(-23001634.72, 13280000), 10, Velocity(0, 0));
	
	// thrust amount = 2.0 and time = 48
	ship.applyThrust(2.0, 48);
	
	float dx = ship.velocity.getDx();
	float dy = ship.velocity.getDy();
	  
	assert( dx == 96);
//	assert( dy == 96);
	
}

void TestShip::test_applyThrust_moving()
{
	Ship ship(Position(-23001634.72, 13280000), 10, Velocity(-1940, -3360.18));
	
	float originalDx = ship.velocity.getDx();
	float originalDy = ship.velocity.getDy();
	
	// thrust amount = 2.0 and time = 48
	ship.applyThrust(2.0, 48);
	
	float currentDx = ship.velocity.getDx();
	float currentDy = ship.velocity.getDy();
	
	float differenceDx = abs(originalDx - currentDx);
	float differenceDy = abs(originalDy - currentDy);
	
	
	assert( differenceDx > 96 && differenceDx < 97  && differenceDy > 96 && differenceDy < 97 );
	
}

void TestShip::test_applyThrust_double()
{
	Ship ship(Position(0.0, -13020000), 10, Velocity(5800, 0.0));
	
	float originalDx = ship.velocity.getDx();
	float originalDy = ship.velocity.getDy();
	
	// thrust amount = 2.0 and time = 48
	ship.applyThrust(2.0, 48);
	ship.applyThrust(2.0, 48);
	
	float currentDx = ship.velocity.getDx();
	float currentDy = ship.velocity.getDy();
	
	float differenceDx = abs(originalDx - currentDx);
	float differenceDy = abs(originalDy - currentDy);
	
	
	assert( differenceDx == 192);
	assert(differenceDy == 192);
	
}
