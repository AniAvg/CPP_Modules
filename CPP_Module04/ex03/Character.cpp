#include "Character.hpp"

Character::Character() : name("Default"), floor_count(0)
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 256; i++)
		this->floor[i] = NULL;
}

Character::Character(std::string const & name) : name(name), floor_count(0)
{
	std::cout << "Character constructor with name called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
	for (int i = 0; i < 256; i++)
		this->floor[i] = nullptr;
}

Character::Character(const Character& other)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 256; i++)
		this->floor[i] = NULL;
	*this = other;
}



Character& Character::operator=(const Character& other)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->floor_count = other.floor_count;
		for (int i = 0; i < 4; i++)
		{
			delete this->inventory[i];
			this->inventory[i] = nullptr;
			if (other.inventory[i] != nullptr)
				this->inventory[i] = (*other.inventory[i]).clone();
		}
		for (int i = 0; i < floor_count; i++)
	{
		delete this->floor[i];
		this->floor[i] = nullptr;
	}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = nullptr;
	}
	for (int i = 0; i < floor_count; i++)
	{
		delete this->floor[i];
		this->floor[i] = nullptr;
	}
}



std::string const& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == nullptr)
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
		if (this->inventory[idx] != nullptr)
		{
			this->floor[floor_count] = this->inventory[idx];
			floor_count++;
			this->inventory[idx] = nullptr;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
	{
		if (this->inventory[idx] != nullptr)
		{
			inventory[idx]->use(target);
		}
	}
}

