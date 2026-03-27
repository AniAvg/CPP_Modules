#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	count = 0;
	index = 0;
}

PhoneBook::~PhoneBook()
{
}

static bool	is_valid_number(std::string pn)
{
	int	i = 0;

	while (pn[i])
	{
		if (pn[i] == ' ')
		{
			i++;
			continue;
		}
		if (std::isdigit(pn[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	is_with_space(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if (!std::isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	PhoneBook::addContact()
{
	std::string	fn;
	std::string	ln;
	std::string	nn;
	std::string	pn;
	std::string	ds;

	std::cout << "First name: ";
	std::getline(std::cin, fn);
	while (fn.empty() || is_with_space(fn))
	{
		std::cout << "Field cannot be empty. First name: ";
		std::getline(std::cin, fn);
	}

	std::cout << "Last name: ";
	std::getline(std::cin, ln);
	while (ln.empty() || is_with_space(ln))
	{
		std::cout << "Field cannot be empty. Last name: ";
		std::getline(std::cin, ln);
	}

	std::cout << "Nickname: ";
	std::getline(std::cin, nn);
	while (nn.empty() || is_with_space(nn))
	{
		std::cout << "Field cannot be empty. Nickname: ";
		std::getline(std::cin, nn);
	}

	std::cout << "Phone number: ";
	std::getline(std::cin, pn);
	while (!is_valid_number(pn))
	{
		std::cout << "Invalid phone number." << std::endl;
		std::getline(std::cin, pn);
	}

	std::cout << "Darkest secret: ";
	std::getline(std::cin, ds);
	while (ds.empty() || is_with_space(ds))
	{
		std::cout << "Field cannot be empty. Darkest secret: ";
		std::getline(std::cin, ds);
	}

	contacts[index % 8].setContact(fn, ln, nn, pn, ds);
	index++;
	if (count < 8)
		count++;

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
