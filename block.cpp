//block.cpp
void Block::update()
{
	const float conductivity=this->rock->conductivity;
    const float capacity=this->rock->capacity;
    float q=calculateHeats();
    float dT=q/capacity;
    temperature+=dT;
}

Block::Block(Rock* rck)
{
	this->rock=rck;
	this->temperature=1000; //K
	this->solid=false;
}
