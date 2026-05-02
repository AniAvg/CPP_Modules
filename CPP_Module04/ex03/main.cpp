#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	/*********************************************/
	// IMateriaSource *src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter *me = new Character("me");
	// me->equip(src->createMateria("ice"));
	// me->equip(src->createMateria("cure"));

	// ICharacter *bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);

	// me->use(42, *bob);
	// me->unequip(0);
	// me->use(0, *bob);

	// AMateria *lost = src->createMateria("fire");
	// std::cout << "fire materia: " << (lost ? "not null (bad!)" : "NULL (ok)") << std::endl;

	// Character copy(*static_cast<Character *>(me));
	// copy.use(1, *bob);

	// delete bob;
	// delete me;
	// delete src;

	return 0;
}
