/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:17:42 by armetix           #+#    #+#             */
/*   Updated: 2025/04/14 12:17:16 by armetix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "phoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contactCount = 0;
	this->currentIndex = 0;
}

void	PhoneBook::addContact()
{
	Contact newContact;
	std::string input;
	
	std::cout << "Enter First Name: ";
	std::getline(std::cin, input);
	newContact.setFirstName(input);
	
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, input);
	newContact.setLastName(input);
	
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, input);
	newContact.setNickname(input);
	
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, input);
	newContact.setPhoneNumber(input);

	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, input);
	newContact.setDarkestSecret(input);
	
	contacts[currentIndex] = newContact;
	
	currentIndex = (currentIndex + 1) % 8;
	if (contactCount < 8)
		contactCount++;
}

void PhoneBook::searchContacts() const
{
	int i;
	std::string first;
	std::string last;
	std::string nick;
	std::string input;
	int	index;

	index = -1;
	i = 0;
	if (contactCount == 0)
	{
		std::cout << "No contacts yet." << std::endl;
		return;
	}
	std::cout << "|" << std::setw(10) << "Index"
			<< "|" << std::setw(10) << "First Name"
			<< "|" << std::setw(10) << "Last Name"
			<< "|" << std::setw(10) << "Nickname" << "|" << std::endl;
			
	while (i < contactCount)
	{
		first = contacts[i].getFirstName();
		last = contacts[i].getLastName();
		nick = contacts[i].getNickname();
		
		if (first.length() > 10)
			first = first.substr(0, 9) + ".";
		if (last.length() > 10)
			last = last.substr(0, 9) + ".";
		if (nick.length() > 10)
			nick = nick.substr(0, 9) + ".";
		
		std::cout << "|" << std::setw(10) << i + 1
				<< "|" << std::setw(10) << first
				<< "|" << std::setw(10) << last
				<< "|" << std::setw(10) << nick << "|" << std::endl;
		i++;
	}
	std::cout << "Enter an index: ";
	std::getline(std::cin, input);
	
	while (input.length() != 1 || !std::isdigit(input[0]) || (input[0] - '0') < 1 || (input[0] - '0') > contactCount)
	{
		std::cout << "Invalid index. Try again: ";
		std::getline(std::cin, input);
	}
	index = input[0] - '0';
	displayContact(index - 1);
}

void PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= contactCount)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	
	const Contact &c = contacts[index];
	
	std::cout << "First Name:     " << c.getFirstName() << std::endl;
	std::cout << "Last Name:      " << c.getLastName() << std::endl;
	std::cout << "Nickname:       " << c.getNickname() << std::endl;
	std::cout << "Phone Number:   " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}