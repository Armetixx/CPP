/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:37:45 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/06 01:37:55 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm* Intern::createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    t_formType forms[3] = {
        {"shrubbery creation", &Intern::createShrubbery},
        {"robotomy request", &Intern::createRobotomy},
        {"presidential pardon", &Intern::createPresidential}
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (forms[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].creator(target);
        }
    }
    
    std::cout << "Error: Form '" << formName << "' does not exist!" << std::endl;
    throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found!";
}