#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm* form;

	std::cout << "\n";
	form = intern.makeForm("shrubbery creation", "Garden");
	delete form;
	form = intern.makeForm("robotomy request", "Bender");
	delete form;
	form = intern.makeForm("presidential pardon", "Zaphod");
	delete form;

	std::cout << "\n";
	try
	{
		form = intern.makeForm("nothing", "Home");
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n";
	try
	{
		form = intern.makeForm("", "Nobody");
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n";
	try
	{
		Bureaucrat high("Alice", 1);
		form = intern.makeForm("robotomy request", "Bender");
		high.signForm(*form);
		high.executeForm(*form);
		delete form;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
