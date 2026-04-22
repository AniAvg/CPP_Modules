#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;

	std::cout << "\n---WrongAnimal---\n";
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << wrong_meta->getType() << std::endl;
	std::cout << wrong_cat->getType() << std::endl;
	wrong_meta->makeSound();
	wrong_cat->makeSound();

	delete wrong_meta;
	delete wrong_cat;

	return 0;
}