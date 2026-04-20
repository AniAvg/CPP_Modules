#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Diamond_clap_name"), FragTrap(), ScavTrap(), name("Diamond")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
}


DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name(name)
{
	std::cout << "DiamondTrap constructor with name called" << std::endl;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
}



DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}



DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}




void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}


void	DiamondTrap::whoAmI()
{
	std::cout << "I am a DiamondTrap named "<<
	name << " and I am a ClapTrap named " << ClapTrap::name << std::endl;
}
