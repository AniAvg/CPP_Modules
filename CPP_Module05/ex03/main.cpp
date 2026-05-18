#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat worker("Worker", 140);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << "\n";
		boss.signForm(shrub);
		boss.executeForm(shrub);

		std::cout << "\n";
		boss.signForm(robot);
		boss.executeForm(robot);

		std::cout << "\n";
		boss.signForm(pardon);
		boss.executeForm(pardon);

		std::cout << "\n";
		worker.executeForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
