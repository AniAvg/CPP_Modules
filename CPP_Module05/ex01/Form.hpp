#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"


class Form
{
private:
	std::string const name;
	bool is_signed;
	const int required_to_sign;
	const int required_to_execute;
public:
	Form();
	Form(const std::string& name, int required_to_sign, int required_to_execute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();


	std::string getName() const;
	bool getIsSigned() const;
	int	getRequiredToSign() const;
	int getRequiredToExecute() const;

	void beSigned(const Bureaucrat& b);


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

std::ostream& operator<<(std::ostream& out, const Form& f);
