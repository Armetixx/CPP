/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:36:10 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/06 01:36:24 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();
    
    AForm* makeForm(const std::string &formName, const std::string &target);
    
    class FormNotFoundException : public std::exception
    {
    public:
        const char *what() const throw();
    };

private:
    typedef struct s_formType
    {
        std::string name;
        AForm* (*creator)(const std::string &target);
    } t_formType;
    
    static AForm* createShrubbery(const std::string &target);
    static AForm* createRobotomy(const std::string &target);
    static AForm* createPresidential(const std::string &target);
};

#endif