/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:02:45 by kederhet          #+#    #+#             */
/*   Updated: 2025/11/06 01:11:46 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("DefaultName"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too high ! Maximum grade is 1.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low ! Minimum grade is 150.");
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return (out);
}

Bureaucrat::~Bureaucrat()
{
}