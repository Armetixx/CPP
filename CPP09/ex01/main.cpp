/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 02:32:03 by kederhet          #+#    #+#             */
/*   Updated: 2025/12/01 02:32:03 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	RPN calculator;
	try
	{
		long result = calculator.compute(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}
