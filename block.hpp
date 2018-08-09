//block.h
#ifndef BLOCK_H
#define BLOCK_H
#include "rock.hpp"
class Block
{
	public:
		Block(Rock *rck);
		float temperature;
		Rock *rock;
		bool solid;
		void update();
		void draw(int x,int y, int j);
};
#endif
