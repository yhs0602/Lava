//rock.hpp
#ifndef ROCK_HPP
#define ROCK_HPP
class Rock
{
	public:
		Rock(char* nam, float dens, float melting, float conduct, float capa);
		float meltingPoint;
		float density;
		float conductivity;
		float capacity;
		char * name;
		bool shouldBeSolid(float temp, float press);
		
		static Rock *air;
		static Rock* rigid;
		static Rock* granite;
};

#endif
