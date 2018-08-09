//block.cpp
#include "block.hpp"
void Block::update()
{
	const float conductivity=this->rock->conductivity;
    const float capacity=this->rock->capacity;
    float q=calculateHeats();
    float dT=q/capacity;
    temperature+=dT;
    float pressure=calculatePressure();
    if(rock->shouldBeSolid(this->temperature,pressure))
    {
    	this->solid=true;
	}else
	{
		this->solid=false;
	}
	vec 
}

Block::Block(Rock* rck)
{
	this->rock=rck;
	this->temperature=1000; //K
	this->solid=false;
}

void Block:: draw(int x,int y, int z)
{
	
}
