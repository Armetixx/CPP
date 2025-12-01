/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:47:08 by kederhet          #+#    #+#             */
/*   Updated: 2025/12/01 01:47:08 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange btc;

	if (!btc.loadDatabase("data.csv"))
	{
		std::cerr << "Error: could not load database." << std::endl;
		return 1;
	}

	btc.processInputFile(argv[1]);
	return 0;
}