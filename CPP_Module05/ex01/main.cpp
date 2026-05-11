#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat a("Annie", 5);
		std::cout << a << std::endl;

		a.increment_grade();
		std::cout << "Incrementing: " << a << std::endl;

		a.decrement_grade();
		a.decrement_grade();
		std::cout << "Decrementing: " << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b("Bob", 0);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;;
	}

	std::cout << "\n";

	try
	{
		Bureaucrat c("Cloe", 150);
		std::cout << c << std::endl;

		c.decrement_grade();
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try
	{
		Bureaucrat d("David", 1);
		std::cout << d << std::endl;

		d.increment_grade();
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
