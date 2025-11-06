/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:10:15 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/06 01:14:48 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));

    std::cout << "=== Creating Bureaucrats ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 40);
        Bureaucrat intern("Intern", 150);
        
        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        std::cout << intern << std::endl;
        std::cout << std::endl;

        std::cout << "TEST 1: ShrubberyCreationForm" << std::endl;
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        
        std::cout << "\nTrying to execute without signing:" << std::endl;
        manager.executeForm(shrub);
        
        std::cout << "\nIntern trying to sign (grade 150, needs 145):" << std::endl;
        intern.signForm(shrub);
        
        std::cout << "\nManager signing (grade 40, needs 145):" << std::endl;
        manager.signForm(shrub);
        
        std::cout << "\nIntern trying to execute (grade 150, needs 137):" << std::endl;
        intern.executeForm(shrub);
        
        std::cout << "\nManager executing (grade 40, needs 137):" << std::endl;
        manager.executeForm(shrub);
        
        std::cout << "\nTEST 2: RobotomyRequestForm" << std::endl;
        RobotomyRequestForm robot("Bender");
        std::cout << robot << std::endl;
        
        std::cout << "\nManager trying to sign (grade 40, needs 72):" << std::endl;
        manager.signForm(robot);
        
        std::cout << "\nManager trying to execute (grade 40, needs 45):" << std::endl;
        manager.executeForm(robot);
        
        std::cout << "\nTesting robotomy multiple times (50% success rate):" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << "Attempt " << i + 1 << ": ";
            boss.executeForm(robot);
        }
        
        std::cout << "\nTEST 3: PresidentialPardonForm" << std::endl;
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;
        
        std::cout << "\nManager trying to sign (grade 40, needs 25):" << std::endl;
        manager.signForm(pardon);
        
        std::cout << "\nBoss signing (grade 1, needs 25):" << std::endl;
        boss.signForm(pardon);
        
        std::cout << "\nManager trying to execute (grade 40, needs 5):" << std::endl;
        manager.executeForm(pardon);
        
        std::cout << "\nBoss executing (grade 1, needs 5):" << std::endl;
        boss.executeForm(pardon);
        
        std::cout << "\nTEST 4: Polymorphism with AForm*" << std::endl;
        AForm* forms[3];
        forms[0] = new ShrubberyCreationForm("garden");
        forms[1] = new RobotomyRequestForm("Marvin");
        forms[2] = new PresidentialPardonForm("Ford Prefect");
        
        std::cout << "Boss signing and executing all forms:" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << "\nForm " << i + 1 << ": " << forms[i]->getName() << std::endl;
            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]);
        }
        
        for (int i = 0; i < 3; i++) {
            delete forms[i];
        }
        
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    
    return 0;
}
