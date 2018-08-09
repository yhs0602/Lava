//block.cpp
#include "block.hpp"
#include "geom.h"
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
	vec netForce=calculateNetForce();
	this->velocity.add(netForce);
	
}

Block::Block(Rock* rck)
{
	this->rock=rck;
	this->temperature=1000; //K
	this->solid=false;
}

#include <gl/gl.h>
void Block:: draw(int x,int y, int z)
{
	GLfloat verts[]={
		x,y,z,
		x+1,y,z,
		x+1,y+1,z,
		x,y+1,z,
		x,y,z+1,
		x+1,y,z+1,
		x+1,y+1,z+1,
		x,y+1,z+1
	};
	glVertexPointer(sizeof(verts)/sizeof(GLfloat),GL_FLOAT,3,verts);
	glDrawElements(GL_TRIANGLES,sizeof(indices)/sizeof(GLuint),GL_INT,inndices);
}
