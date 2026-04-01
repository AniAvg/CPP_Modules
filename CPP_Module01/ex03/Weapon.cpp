#include "Weapon.hpp"

Weapon::Weapon()
{}

Weapon::~Weapon()
{}

const std::string& Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}