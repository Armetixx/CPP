/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:10:15 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/06 01:39:07 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));

    Bureaucrat boss("Boss", 1);
    Intern someRandomIntern;
    AForm* form;
    
    std::cout << "TEST 1: Valid Forms" << std::endl;
    
    std::cout << "\nCreating Shrubbery Form" << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "garden");
    if (form)
    {
        std::cout << *form << std::endl;
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
    
    std::cout << "\nCreating Robotomy Form" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        std::cout << *form << std::endl;
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
    
    std::cout << "\nCreating Presidential Form" << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Arthur");
    if (form)
    {
        std::cout << *form << std::endl;
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
    
    std::cout << "\nTEST 2: Invalid Forms" << std::endl;
    
    try {
        std::cout << "\nTrying to create invalid form" << std::endl;
        form = someRandomIntern.makeForm("invalid form", "target");
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTrying to create form with typo" << std::endl;
        form = someRandomIntern.makeForm("robotoomy request", "R2D2");
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\nTEST 3: Multiple Interns" << std::endl;
    Intern intern1;
    Intern intern2;
    Intern intern3;
    
    AForm* forms[3];
    forms[0] = intern1.makeForm("shrubbery creation", "park");
    forms[1] = intern2.makeForm("robotomy request", "C3PO");
    forms[2] = intern3.makeForm("presidential pardon", "Zaphod");
    
    std::cout << "\nAll forms created by different interns:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        if (forms[i])
        {
            std::cout << *forms[i] << std::endl;
            delete forms[i];
        }
    }
    
    std::cout << "\nTEST 4: Example from subject" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            std::cout << "Form created: " << *rrf << std::endl;
            delete rrf;
        }
    }
    
    return 0;
}