#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	//initialize
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact()
{

}

Contact	PhoneBook::searchContact()
{

}

void	PhoneBook::displayContacts()
{
	int	i = 0;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	while (i < count)
	{
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i << "|"
					<< std::right << std::setw(10) << contacts[i].getFirstName() << "|"
					<< std::right << std::setw(10) << contacts[i].getLastName() << "|"
					<< std::right << std::setw(10) << contacts[i].getNickname() << "|" << std::endl;
		i++;
	}
}
