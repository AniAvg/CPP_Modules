#pragma once

#include <iostream>
#include <exception>
#include <string>


class Bureaucrat
{
private:
	std::string const	name;
	int		grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	std::string getName() const;
	int getGrade() const;
	void increment_grade();
	void decrement_grade();


	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "Grade is too high";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "Grade is too low";
		}
	};

};


std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);


