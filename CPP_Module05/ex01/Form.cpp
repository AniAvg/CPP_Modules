#include "Form.hpp"

Form::Form() : name("default"), is_signed(false),
				required_to_sign(150), required_to_execute(150)
{}

Form::Form(const std::string& name, int required_to_sign, int required_to_execute)
	: name(name), is_signed(false), required_to_sign(required_to_sign),
	  required_to_execute(required_to_execute)
{
	if (this->required_to_sign < 1 || this->required_to_execute < 1)
		throw GradeTooHighException();
	if (this->required_to_sign > 150 || this->required_to_execute > 150)
		throw GradeTooLowException();
}


Form::Form(const Form& other) : name(other.name), is_signed(other.is_signed),
								required_to_sign(other.required_to_sign),
								required_to_execute(other.required_to_execute)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->is_signed = other.is_signed;
	}
	return *this;
}

Form::~Form()
{}


std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return is_signed;
}

int	Form::getRequiredToSign() const
{
	return required_to_sign;
}

int Form::getRequiredToExecute() const
{
	return required_to_execute;
}


void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->required_to_sign)
		throw GradeTooLowException();
	this->is_signed = true;
}


std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << "Form: "<< f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no")
	<< ", required to sign: " << f.getRequiredToSign()
	<< ", required to execute: " << f.getRequiredToExecute();
	return out;
}
