#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	a("A");
	ClapTrap	b("B");

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);

	return 0;
}
