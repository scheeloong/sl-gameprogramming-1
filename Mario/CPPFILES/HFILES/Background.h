//
#ifndef BACKGROUND_H
#define BACKGROUN_H
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
		if(MapLoad("50x50.fmp", 1))
			exit(-5); 
	}
};
#endif BACKGROUND_H

//