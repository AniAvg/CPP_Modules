#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	pb;
	std::string	cmd;

	while (1)
	{
		std::cout << "Enter the command: " << std::endl;
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			pb.addContact();//
		}
		else if (cmd == "SEARCH")
		{
			pb.displayContacts();//
		}
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "Unknown command. Please enter ADD, SEARCH or EXIT." << std::endl;
	}
	return (0);
}
