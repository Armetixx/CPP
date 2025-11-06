/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:02:49 by kederhet          #+#    #+#             */
/*   Updated: 2025/11/06 01:11:24 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP
# include <string>
# include <iostream>

class AForm;
class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
    void signForm(AForm &form);
    void executeForm(AForm const & form) const;
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
		
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);

#endif