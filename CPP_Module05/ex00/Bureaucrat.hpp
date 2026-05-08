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
	Bureaucrat(const std::string& name, int grade);
	std::string getName();
	int getGrade();
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

