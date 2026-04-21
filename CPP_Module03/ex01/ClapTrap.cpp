#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap constructor with name called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}



ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name), hit_points(other.hit_points), energy_points(other.energy_points), attack_damage(other.attack_damage)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other)
{

	if (this != &other)
	{
		std::cout << "ClapTrap Copy assignment operator called" << std::endl;
		
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	return (*this);
}




void	ClapTrap::attack(const std::string& target)
{
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		return;
	}
	if (energy_points <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy" << std::endl;
		return;
	}
	energy_points--;
	std::cout << "ClapTrap " << name << " attacks " << target
	<< ", causing " << attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return ;
	}
	if (amount >= (unsigned int)hit_points)
		hit_points = 0;
	else
		hit_points -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount
	<< " damage! Remaining HP: " << hit_points << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		return;
	}
	if (energy_points <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy" << std::endl;
		return;
	}
	energy_points--;
	hit_points += amount;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount
	<< " HP! Total HP: " << hit_points << std::endl;
}

