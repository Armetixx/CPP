/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:31:05 by armetix           #+#    #+#             */
/*   Updated: 2025/04/21 13:37:02 by armetix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string zombie;
	zombie = "HI THIS IS BRAIN";
	std::string *stringPTR = &zombie;
	std::string &stringREF = zombie;
	
	std::cout << "address of string: " << &zombie << std::endl;
	std::cout << "address with pointer: " << stringPTR << std::endl;
	std::cout << "address with reference: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "value of the string: " << zombie << std::endl;
	std::cout << "value with pointer: " << *stringPTR << std::endl;
	std::cout << "value with reference: " << stringREF << std::endl;

	return (0);
}
