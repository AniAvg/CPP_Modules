#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}



ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
}


ClapTrap&	ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	return (*this);
}





void	ClapTrap::attack(const std::string& target)
{
	attack_damage--;
	std::cout << "ClapTrap" << name << "attacks" << hit_points
	<< "causing" << attack_damage << "points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{}

void	ClapTrap::beRepaired(unsigned int amount)
{}

