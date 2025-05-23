/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:49:05 by armetix           #+#    #+#             */
/*   Updated: 2025/04/28 15:16:53 by armetix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	this->_value = other._value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	this->_value = intValue << _bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue)
{
	this->_value = roundf(floatValue * (1 << _bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	this->_value = other._value;
	std::cout << "Copy assignement operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const rawBits)
{
	this->_value = rawBits;
}

int Fixed::toInt() const
{
	return (this->_value >> _bits);
}

float Fixed::toFloat() const
{
	return ((float)this->_value / (1 << _bits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}