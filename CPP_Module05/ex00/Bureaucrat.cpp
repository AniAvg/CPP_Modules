#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
	if (this->grade < 1)
		throw GradeTooHighException();
	if (this->grade > 150)
		throw GradeTooLowException();
}


std::string Bureaucrat::getName()
{
	return this->name;
}

int Bureaucrat::getGrade()
{
	return this->grade;
}

void Bureaucrat::increment_grade()
{
	if (this->grade == 1)
		this->grade = 150;
	else
		this->grade--;
}

void Bureaucrat::decrement_grade()
{
	if (this->grade == 150)
		this->grade = 150;
	else
		this->grade++;
}

