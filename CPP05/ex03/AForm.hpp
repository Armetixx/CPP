/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:51:46 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/06 00:52:12 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

public:
    AForm(const std::string name, const int signGrade, const int execGrade);
    AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();
    
    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    void beSigned(Bureaucrat &bureaucrat);
    void execute(Bureaucrat const & executor) const;
    
    virtual void executeAction() const = 0;
    
    class GradeTooHighException : public std::exception {
        public: const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public: const char *what() const throw();
    };
    class FormNotSignedException : public std::exception {
        public: const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &other);

#endif
