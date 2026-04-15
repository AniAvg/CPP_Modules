#include "ScavTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private:

	public:
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &other);

		void	guardGate();
};
