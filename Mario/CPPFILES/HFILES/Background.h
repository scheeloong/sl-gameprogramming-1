#ifndef BACKGROUND_H
#define BACKGROUND_H

// CL: What happen to Background.cpp?
// VL: With the introduction of the map, background is no longer used.
//	   Turns out, the map from Mappy must be loaded inside the Mario.cpp file, 
//	   inside the Mario class. Errors arise otherwise. This is still here 
//	   in case parallax scrolling requires this stuff, etc.
#include "Classes.h"
#include "Player.h"
//#include "mappy_A5.h"
class Background 
{
private:
	//ALLEGRO_BITMAP *bgImage;
	//ALLEGRO_BITMAP *mgImage;
	//ALLEGRO_BITMAP *fgImage;
public:
	Background()
	{
		/*if(MapLoad("50x50.fmp", 1))
			exit(-5); */
	}
};
#endif BACKGROUND_H

//