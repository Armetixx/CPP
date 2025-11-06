#include "AForm.hpp"

AForm::AForm(const std::string name, const int signGrade, const int execGrade): name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(): name("Default Form"), isSigned(false), signGrade(150), execGrade(150)
{
}

AForm::AForm(const AForm &other): name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
}

const std::string& AForm::getName() const
{
	return (this->name);
}
bool AForm::getIsSigned() const
{
	return(this->isSigned);
}

int AForm::getSignGrade() const
{
	return (this->signGrade);
}

int AForm::getExecGrade() const
{
	return (this->execGrade);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
	
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high ! Maximum grade is 1.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low to sign this form!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed!");
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->execGrade)
        throw AForm::GradeTooLowException();
    this->executeAction();
}


std::ostream &operator<<(std::ostream &out, const AForm &other)
{
    out << "Form: " << other.getName() 
        << ", signed: " << (other.getIsSigned() ? "yes" : "no")
        << ", sign grade: " << other.getSignGrade()
        << ", exec grade: " << other.getExecGrade();
    return (out);
}
