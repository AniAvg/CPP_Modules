#pragma once

#include <iostream>
#include <string>


class ClapTrap
{
	private:
		std::string	name;
		int	hit_points;
		int	energy_points;
		int	attack_damage;
	public:
		ClapTrap();
		ClapTrap(const ClapTrap& other);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &other);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

