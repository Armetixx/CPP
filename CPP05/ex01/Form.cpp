/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:37:00 by kederhet          #+#    #+#             */
/*   Updated: 2025/10/19 22:01:51 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int signGrade, const int execGrade): name(name), signGrade(signGrade), execGrade(execGrade), isSigned(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(): name("Default Form"), signGrade(150), execGrade(150), isSigned(false)
{
}

Form::Form(const Form &other): name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), isSigned(other.isSigned)
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
bool Form::getIsSigned()
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