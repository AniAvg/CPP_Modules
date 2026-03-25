#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class	Contact
{
	private:
		std::string	first_name;
		std::string	nickname;
		std::string	phone_nb;
		std::string	darkest_secret;
	public:
		Contact();
		~Contact();
};

#endif
