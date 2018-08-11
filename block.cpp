//block.cpp
#include "block.hpp"
#include "geom.h"

Block *getBlock(ivec x);

extern Block *blocks[DIM][DIM][DIM]; 
void Block::update()
{
	if(this->rock==Rock::air)
	{
		return;
	}
	const float conductivity=this->rock->conductivity;
    const float capacity=this->rock->capacity;
    float q=calculateHeats();
    float dT=q/capacity;
    temperature+=dT;
    pressure=calculatePressure();
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

Block::Block(ivec pos,Rock* rck)
{
	this->rock=rck;
	this->temperature=50; //K
	this->solid=false;
	this->pos=pos;
}

float Block::calculateHeats()
{
	Block *top=getBlock(ivec(pos.x,pos.y+1,pos.z));
	Block *bottom=getBlock(ivec(pos.x,pos.y-1,pos.z));
	Block *right=getBlock(ivec(pos.x+1,pos.y,pos.z));
	Block *left=getBlock(ivec(pos.x-1,pos.y,pos.z));
	Block *front=getBlock(ivec(pos.x,pos.y,pos.z-1));
	Block *back=getBlock(ivec(pos.x,pos.y,pos.z+1));
	float dt=0;
	if(top!=NULL)
		dt+=(top->temperature-temperature);
	if(bottom!=NULL)
		dt+=(bottom->temperature-temperature);
	if(right!=NULL)
		dt+=(right->temperature-temperature);
	if(left!=NULL)
		dt+=(left->temperature-temperature);
	if(front!=NULL)
		dt+=(front->temperature-temperature);
	if(back!=NULL)
		dt+=(back->temperature-temperature);
	return dt;
}

vec Block::calculateNetForce()
{
	Block *top=getBlock(ivec(pos.x,pos.y+1,pos.z));
	Block *bottom=getBlock(ivec(pos.x,pos.y-1,pos.z));
	Block *right=getBlock(ivec(pos.x+1,pos.y,pos.z));
	Block *left=getBlock(ivec(pos.x-1,pos.y,pos.z));
	Block *front=getBlock(ivec(pos.x,pos.y,pos.z-1));
	Block *back=getBlock(ivec(pos.x,pos.y,pos.z+1));
	vec ret;
	if(top!=NULL)
		ret.y+=(top->getPressure(BOTTOM));
	if(bottom!=NULL)
		ret.y-=(bottom->getPressure(TOP));
	if(right!=NULL)
		ret.x+=(right->getPressure(LEFT));
	if(left!=NULL)
		ret.x-=(left->getPressure(RIGHT));
	if(front!=NULL)
		ret.z-=(front->getPressure(BACK));
	if(back!=NULL)
		ret.z+=(back->getPressure(FRONT));
}

float Block::calculatePressure()
{
	vec force= calculateNetForce();
	return abs(force.x)+abs(force.y+abs(force.z));
}

Block *getBlock(ivec x)
{
	if((x.x>=DIM)||(x.y>=DIM)||(x.z>=DIM))
		return NULL;
	if((x.x<0)||(x.y<0)||(x.z<0))
		return NULL;
	return  blocks[x.x][x.y][x.z];
}

float Block::getPressure(int face)
{
	switch(face)
	{
		case TOP:
			return pressure;
		case BOTTOM:
			return pressure+rock->density;
	}
	return pressure;
}
#include <gl/gl.h>

extern int texture[];
GLubyte indices[]={
0,1,2,
0,2,3,
2,1,5,
2,5,6,
2,6,7,
2,7,3,
6,5,4,
6,4,7,
7,4,0,
7,0,3
};
GLfloat texCoords[]={
	0,0,1,0,1,1,1,0
}

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
	if(solid)
	{
		glColor3f(0.5f,0.5f, 0.5f);
	}
	else
	{
		glColor3f(1,0,0);
	}
	glBindTexture(GL_TEXTURE_2D,texture[LAVA]);
	glVertexPointer(3,GL_FLOAT,0,verts);
	glTexCoordPointer(2,GL_FLOAT,0,texCoords);
	glDrawElements(GL_TRIANGLES,sizeof(indices)/sizeof(GLubyte)/3,GL_UNSIGNED_BYTE,indices);
}
