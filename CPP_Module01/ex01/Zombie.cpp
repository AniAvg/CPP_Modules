#include "Zombie.hpp"

Zombie::Zombie()
{
}


Zombie::~Zombie()
{
}

std::string	Zombie::getZombieName()
{
	return (name);
}

void	Zombie::giveName(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

