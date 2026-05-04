#include "Character.hpp"

Character::Character() : name("Default"), floor_count(0)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 256; i++)
		this->floor[i] = NULL;
}

Character::Character(std::string const & name) : name(name), floor_count(0)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 256; i++)
		this->floor[i] = NULL;
}

Character::Character(const Character& other)
{
	this->floor_count = other.floor_count;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 256; i++)
		this->floor[i] = NULL;
	*this = other;
}



Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->floor_count = other.floor_count;
		for (int i = 0; i < 4; i++)
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
			if (other.inventory[i] != NULL)
				this->inventory[i] = (*other.inventory[i]).clone();
		}
		for (int i = 0; i < floor_count; i++)
		{
			delete this->floor[i];
			this->floor[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	for (int i = 0; i < floor_count; i++)
	{
		if (this->floor[i])
		{
			delete this->floor[i];
			this->floor[i] = NULL;
		}
	}
}



std::string const& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		if (this->inventory[idx] != NULL && floor_count < 256)
		{
			this->floor[floor_count] = this->inventory[idx];
			floor_count++;
			this->inventory[idx] = NULL;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
	{
		if (this->inventory[idx] != NULL)
		{
			inventory[idx]->use(target);
		}
	}
}

