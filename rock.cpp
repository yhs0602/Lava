#include "rock.hpp"

Rock::Rock(char* nam, float dens, float melting, float conduct, float capa)
{
	this->name=nam;
	this->conductivity=conduct;
	this->meltingPoint=melting;
	this->density=dens;
	this->capacity=capa;
}
static Rock * Rock::air=new Rock("air", 0.001f, -100, 0.001f, 0.831f);
static Rock * Rock::rigid=new Rock("rigid", 100f, 100000, 0, 10000f);

