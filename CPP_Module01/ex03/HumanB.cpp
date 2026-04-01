#include "HumanB.hpp"

HumanB::HumanB()
{}

HumanB::~HumanB()
{}

HumanB::HumanB(std::string name): name(name), weapon(NULL)
{}

void	HumanB::attack() const
{
	if (this->weapon)
		std::cout << name << " attacks with their" << weapon.getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack with" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon);
{
	this->weapon = &weapon;
}
