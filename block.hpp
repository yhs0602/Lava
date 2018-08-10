//block.h
#ifndef BLOCK_H
#define BLOCK_H
#include "rock.hpp"
#include "geom.h"
class Block
{
	public:
		Block(Rock *rck);
		float temperature;
		Rock *rock;
		bool solid;
		void update();
		void draw(int x,int y, int j);
		vec velocity;
		float calculateHeat();
		float 
};
#endif
