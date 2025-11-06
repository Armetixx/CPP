/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:37:00 by kederhet          #+#    #+#             */
/*   Updated: 2025/11/05 23:29:45 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int signGrade, const int execGrade): name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(): name("Default Form"), isSigned(false), signGrade(150), execGrade(150)
{
}

Form::Form(const Form &other): name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
	return (this->name);
}
bool Form::getIsSigned() const
{
	return(this->isSigned);
}

int Form::getSignGrade() const
{
	return (this->signGrade);
}

int Form::getExecGrade() const
{
	return (this->execGrade);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
	
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high ! Maximum grade is 1.");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low to sign this form!");
}

std::ostream &operator<<(std::ostream &out, const Form &other)
{
    out << "Form: " << other.getName() 
        << ", signed: " << (other.getIsSigned() ? "yes" : "no")
        << ", sign grade: " << other.getSignGrade()
        << ", exec grade: " << other.getExecGrade();
    return (out);
}
