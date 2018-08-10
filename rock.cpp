#include "rock.hpp"

Rock::Rock(char* nam, float dens, float melting, float conduct, float capa)
{
	this->name=nam;
	this->conductivity=conduct;
	this->meltingPoint=melting;
	this->density=dens;
	this->capacity=capa;
}

bool Rock::shouldBeSolid(float temperature, float pressure)
{
	if(pressure<=0)
		return false; 
	if(temperature>meltingPoint*pressure)
		return false;
	return true;
}

Rock * Rock::air=new Rock("air", 0.001f, -100, 0.001f, 0.831f);
Rock * Rock::rigid=new Rock("rigid", 100, 100000, 0, 10000);
Rock * Rock::granite=new Rock("granite",2.75f,1215,0.03f,790);
