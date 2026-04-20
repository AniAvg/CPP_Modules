#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor with name called" << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}


FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}


FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}


void FragTrap::highFivesGuys(void)
{
	if (hit_points == 0)
	{
		std::cout << "FragTrap " << name << " is dead and can't high five!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " is asking for high fives!" << std::endl;
}
