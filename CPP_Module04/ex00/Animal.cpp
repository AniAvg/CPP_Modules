#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	this->type = other.type;
	std::cout << "Animal copy constructor called" << std::endl;
}


Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}



void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}


std::string	Animal::getType() const
{
	return (this->type);
}
