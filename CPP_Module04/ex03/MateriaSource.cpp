#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : learned_count(0)
{
	for (int i = 0; i < 4; i++)
		this->learned[i] = NULL;
}


MateriaSource::MateriaSource(const MateriaSource& other)
{
	this->learned_count = other.learned_count;
	for (int i = 0; i < 4; i++)
		this->learned[i] = NULL;
	*this = other;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		this->learned_count = other.learned_count;
		for (int i = 0; i < 4; i++)
		{
			delete this->learned[i];
			this->learned[i] = NULL;
			if (other.learned[i] != NULL)
				this->learned[i] = other.learned[i]->clone();
		}
	}
	return (*this);
}


MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->learned_count; i++)
	{
		delete this->learned[i];
		this->learned[i] = NULL;
	}
}



void MateriaSource::learnMateria(AMateria* m)
{
	if (m != NULL)
	{
		if (this->learned_count != 4)
		{
			this->learned[learned_count] = m;
			this->learned_count++;
		}
	}
}


AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->learned_count; i++)
	{
		if (this->learned[i]->getType() == type)
			return (this->learned[i]->clone());
	}
	return (NULL);
}
