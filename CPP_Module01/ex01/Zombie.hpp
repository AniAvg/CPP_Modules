#pragma once

#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();
		void		announce(void);
		void		giveName(std::string name);
		std::string	getZombieName();

};


Zombie*	zombieHorde(int N, std::string name);

