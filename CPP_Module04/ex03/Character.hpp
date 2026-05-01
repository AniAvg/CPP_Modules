#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria*	inventory[4];
	AMateria*	floor[256];
	int			floor_count;
public:
	Character();
	Character(const Character& other);
	Character(std::string const & name);
	Character& operator=(const Character& other);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

