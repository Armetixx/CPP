/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:59:20 by armetix           #+#    #+#             */
/*   Updated: 2025/04/14 12:15:22 by armetix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "phoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;
	
	std::cout << "Welcome to the PhoneBook." << std::endl;
	std::cout << "Commands are: ADD, SEARCH and EXIT" << std::endl;
	
	while(true)
	{
		std::cout << "> ";
		std::getline(std::cin, command);
		
		if (std::cin.eof())
		{
			std::cout << "\nExiting the PhoneBook..." << std::endl;
			break ;
		}
		
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (command == "EXIT")
		{
			std::cout << "Exiting the PhoneBook..." << std::endl;
			break ;
		}
		else
		{
			std::cout << "Unknown command. Try 'ADD', 'SEARCH' or 'EXIT'." << std::endl;
		}
	}
}