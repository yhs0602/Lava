//block.h
#ifndef BLOCK_H
#define BLOCK_H
#include "rock.hpp"
class Block
{
	public:
		Block();
		float temperature;
		Rock rock;
		bool solid;
		void update();
}
#endif
