#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " died." << std::endl;
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

