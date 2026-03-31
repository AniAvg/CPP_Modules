#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	*z;

	z = new Zombie(name);
	z->announce();
	delete z;
}
