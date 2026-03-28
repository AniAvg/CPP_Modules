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
		if (!std::isdigit(pn[i]))
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
	while (!is_valid_number(pn) || pn.empty() || is_with_space(pn))
	{
		std::cout << "Invalid phone number. Phone number: ";
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

void	PhoneBook::searchContact(int idx)
{
	if (idx < 0 || idx >= count)
	{
		std::cout << "Index is out of range." << std::endl;
		return;
	}
	std::cout << "First name: " << contacts[idx].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[idx].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[idx].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[idx].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[idx].getDarkestSecret() << std::endl;
}

void	PhoneBook::displayContacts()
{
	int	i = 0;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (i < count)
	{
		std::string	fn = contacts[i].getFirstName();
		std::string	ln = contacts[i].getLastName();
		std::string	nn = contacts[i].getNickname();

		if (fn.length() > 10)
			fn = fn.substr(0, 9) + '.';
		if (ln.length() > 10)
			ln = ln.substr(0, 9) + '.';
		if (nn.length() > 10)
			nn = nn.substr(0, 9) + '.';

		std::cout << "|";
		std::cout << std::right << std::setw(10) << i << "|"
					<< std::right << std::setw(10) << fn << "|"
					<< std::right << std::setw(10) << ln << "|"
					<< std::right << std::setw(10) << nn << "|" << std::endl;
		i++;
	}
}
