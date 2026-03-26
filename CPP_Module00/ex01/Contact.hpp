#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		Contact();
		~Contact();
		void	setContact(std::string fn, std::string ln, std::string nn,
							std::string pn, std::string ds);
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNicname();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
};

#endif
