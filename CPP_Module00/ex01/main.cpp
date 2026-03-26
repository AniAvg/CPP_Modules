#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	pb;
	std::string	cmd;
	int			index

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
			pb.displayContacts();
			std::cout << "Enter the intex of contact (0-7): " << std::endl;
			std::cin >> index;
			if (index >= 0 && index <= 7)
			{
				//search index;
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
