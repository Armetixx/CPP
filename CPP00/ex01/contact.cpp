/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:06:02 by armetix           #+#    #+#             */
/*   Updated: 2025/04/14 12:17:41 by armetix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::setFirstName(const std::string &value) 
{
	this->firstName = value;
}
void Contact::setLastName(const std::string &value) 
{
	this->lastName = value;
}
void Contact::setNickname(const std::string &value) 
{
	this->nickname = value;
}
void Contact::setPhoneNumber(const std::string &value) 
{
	this->phoneNumber = value;
}
void Contact::setDarkestSecret(const std::string &value) 
{
	this->darkestSecret = value;
}

std::string Contact::getFirstName() const 
{
	return this->firstName;
}
std::string Contact::getLastName() const 
{
	return this->lastName;
}
std::string Contact::getNickname() const 
{
	return this->nickname;
}
std::string Contact::getPhoneNumber() const 
{
	return this->phoneNumber;
}
std::string Contact::getDarkestSecret() const 
{
	return this->darkestSecret;
}