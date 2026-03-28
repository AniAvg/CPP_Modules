#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <sstream>

int	main()
{
	PhoneBook	pb;
	std::string	cmd;
	int			index;

	while (1)
	{
		std::cout << "Enter the command: " << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break;
		if (cmd == "ADD")
		{
			pb.addContact();
		}
		else if (cmd == "SEARCH")
		{
			pb.displayContacts();
			std::string idx_str;
			std::cout << "Enter the index of contact (0-7): ";
			std::getline(std::cin, idx_str);
			if (idx_str.empty())
			{
				std::cout << "No index entered." << std::endl;
				continue;
			}
			{
				std::istringstream iss(idx_str);
				if (!(iss >> index))
				{
					std::cout << "Invalid index input." << std::endl;
					continue;
				}
			}
			if (index >= 0 && index <= 7)
			{
				pb.searchContact(index);
			}
			else
				std::cout << "Index is out of range." << std::endl;
		}
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "Unknown command. Please enter ADD, SEARCH or EXIT." << std::endl;
	}
	return (0);
}
