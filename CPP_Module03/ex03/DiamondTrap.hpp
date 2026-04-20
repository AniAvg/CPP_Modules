#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap& other);

		void	attack(const std::string& target);
		void	whoAmI();
};
