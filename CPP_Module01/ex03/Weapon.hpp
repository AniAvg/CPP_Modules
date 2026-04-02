#pragma once

#include <iostream>

class	Weapon
{
	private:
		std::string	type;
	public:
		Weapon();
		Weapon(const std::string &type);
		~Weapon();
		const std::string& getType() const;
		void	setType(std::string type);
};
