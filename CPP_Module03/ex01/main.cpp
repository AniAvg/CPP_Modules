#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap a("Clap");
	ScavTrap b("Scav");

	a.attack("enemy");
	b.attack("enemy");

	b.takeDamage(30);
	b.beRepaired(10);

	for (int i = 0; i < 55; i++)
		b.attack("dummy");

	b.takeDamage(200);
	b.attack("ghost");

	b.guardGate();

	ScavTrap c(b);
	c.attack("copy_target");

	ScavTrap d;
	d = b;
	d.attack("assigned_target");

	return 0;
}

