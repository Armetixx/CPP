/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:56:38 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/05 14:00:15 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== TEST 1: Creation ===" << std::endl;
    try {
        Form f1("Tax Form", 50, 25);
        std::cout << f1 << std::endl;
        
        Form invalid("Bad", 0, 50);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Signing ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 40);
        Bureaucrat alice("Alice", 60);
        Form contract("Contract", 50, 30);
        
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << contract << std::endl << std::endl;
        
        bob.signForm(contract);
        alice.signForm(contract);
        
        std::cout << std::endl << contract << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Edge cases ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        Bureaucrat ceo("CEO", 1);
        Form hard("Top Secret", 1, 1);
        
        intern.signForm(hard);
        ceo.signForm(hard);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
