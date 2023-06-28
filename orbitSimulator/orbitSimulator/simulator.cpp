
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include <iostream>
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "acceleration.h"
#include "satellite.h"
#include "velocity.h"
#include "testRunner.h"

#define TIME 48
#define FRAME_RATE 80
#define SECONDS_DAY 86400
#define PI 3.141529

using namespace std;

class Demo
{
public:
	Demo(Position ptUpperRight) :
	ptUpperRight(ptUpperRight)
	{
		ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
		ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
		
		double rate = -(2 * PI / FRAME_RATE);
		double frameRate = rate * TIME;
		angleShip = frameRate;
		angleEarth = frameRate;
		phaseStar = 0;
	}
	
	Position ptHubble;
	Position ptUpperRight;
	unsigned char phaseStar;
	double angleShip;
	double angleEarth;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
	Demo* pDemo = (Demo*)p;
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
	  "Demo",   /* name on the window */
	  ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   testRunner();
   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
