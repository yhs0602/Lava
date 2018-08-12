//block.h
#ifndef BLOCK_H
#define BLOCK_H
#include "rock.hpp"
#include "geom.h"

#define DIM 25
enum TEXTURES
{
	LAVA,
	ROCK,
	NUM_TEXTURES
};

#include <GL/gl.h>
extern GLuint texture[NUM_TEXTURES];
class Block
{
	public:
		Block(ivec pos, Rock *rck);
		float temperature;
		Rock *rock;
		bool solid;
		float pressure;
		void update();
		void draw(int x,int y, int j);
		vec velocity;
		float calculateHeats();
		float calculatePressure();
		vec calculateNetForce();
		ivec pos;
		float getPressure(int face);
};

enum FACES
{
	TOP,
	BOTTOM,
	RIGHT,
	LEFT,
	FRONT,
	BACK
};
#endif
