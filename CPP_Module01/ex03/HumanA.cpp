#include "HumanA.hpp"

HumanA::HumanA()
{}

HumanA::~HumanA()
{}

HumanA::HumanA(std::string name, Weapon &Weapon) : name(name), Weapon(weapon)
{}

void    HumanA::attack() const
{
	std::cout << name << " attacks with their" << weapon.getType() << std::endl;
}

