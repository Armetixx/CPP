/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:23:33 by kederhet          #+#    #+#             */
/*   Updated: 2025/10/19 21:36:08 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

# define FORM_HPP
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int execGrade;
public:
	Form(const std::string name, const int signGrade, const int execGrade);
	Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	
	const std::string& getName() const;
	bool getIsSigned();
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(Bureaucrat &bureaucrat);
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

std::ostream &operator<<(std::ostream &out, const Form &other);

#endif