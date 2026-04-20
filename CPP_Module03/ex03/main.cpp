#include "DiamondTrap.hpp"


int	main()
{
	std::cout << "=== Default Constructor Test ===" << std::endl;
	DiamondTrap a;
	a.whoAmI();

	std::cout << "\n=== Parameterized Constructor Test ===" << std::endl;
	DiamondTrap b("Bobby");
	b.whoAmI();

	std::cout << "\n=== Attack Test ===" << std::endl;
	b.attack("Enemy");

	std::cout << "\n=== Special Abilities Test ===" << std::endl;
	b.guardGate();
	b.highFivesGuys();

	std::cout << "\n=== Damage and Repair Test ===" << std::endl;
	b.takeDamage(20);
	b.beRepaired(10);

	std::cout << "\n=== Energy Depletion Test ===" << std::endl;
	for (int i = 0; i < 55; i++)
		b.attack("Dummy");

	std::cout << "\n=== Copy Constructor Test ===" << std::endl;
	DiamondTrap c(b);
	c.whoAmI();

	std::cout << "\n=== Assignment Operator Test ===" << std::endl;
	DiamondTrap d;
	d = b;
	d.whoAmI();

	std::cout << "\n=== End of Tests ===" << std::endl;

	return 0;
}
