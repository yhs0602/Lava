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
		static Rock *air;
		static Rock* rigid;
};

#endif
