#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int	main()
{
	FragTrap	f1;
	FragTrap	f2("Frag");
	FragTrap	f3(f2);
	FragTrap	f4("Temp");
	f4 = f2;

	f2.attack("enemy");
	f2.takeDamage(40);
	f2.beRepaired(10);
	f2.highFivesGuys();

	FragTrap f5("LowEnergy");
	for (int i = 0; i <= 100; i++)
		f5.attack("target");

	FragTrap f6("Dead");
	f6.takeDamage(999);
	f6.attack("someone");
	f6.beRepaired(10);
	f6.highFivesGuys();

	return (0);
}
