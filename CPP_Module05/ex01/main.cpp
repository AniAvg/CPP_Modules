#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Form f("Tax Form", 50, 24);
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: "<< e.what() << std::endl;
	}

	std::cout << "\n";

	try
	{
		Form f("Tax Form", 0, 25);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try
	{
		Form f("Tax Form", 151, 25);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b("Alice", 10);
		Form f("Tax Form", 50, 25);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b("Bob", 100);
		Form f("Tax Form", 50, 25);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n";

	try
	{
		Bureaucrat b("Charlie", 1);
		Form f("Tax Form", 50, 25);
		b.signForm(f);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}


	return 0;
}
