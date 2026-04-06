#include "Zombie.hpp"

int	main()
{
	Zombie	*zombie;

	zombie = newZombie("Foo");
	std::cout << zombie->getZombieName() << std::endl;
	randomChump("Tupoy");
	delete zombie;
}
