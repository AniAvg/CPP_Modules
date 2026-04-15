#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a("A");
	ClapTrap	b("B");

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);

	// ClapTrap a("A");
	// for (int i = 0; i < 11; i++)
	// 	a.attack("target");

	return 0;
}
