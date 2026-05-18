#pragma once

#include <string>
#include <iostream>

class Bureaucrat;


class AForm
{
private:
	std::string const name;
	bool is_signed;
	const int required_to_sign;
	const int required_to_execute;
public:
	AForm();
	AForm(const std::string& name, int required_to_sign, int required_to_execute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();


	std::string getName() const;
	bool getIsSigned() const;
	int	getRequiredToSign() const;
	int getRequiredToExecute() const;

	void beSigned(const Bureaucrat& b);


	virtual void execute(Bureaucrat const & executor) const;
	virtual void performAction() const = 0;

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

	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return "Form is not signed";
		}
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& f);
