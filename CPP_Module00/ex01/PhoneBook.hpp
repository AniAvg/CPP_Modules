#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		count;
		int		index;
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact(int idx);
		void	displayContacts();
};

#endif
