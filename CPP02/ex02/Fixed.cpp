/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:49:05 by armetix           #+#    #+#             */
/*   Updated: 2025/04/28 16:29:08 by armetix          ###   ########.fr       */
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

bool Fixed::operator>(const Fixed &other)
{
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other)
{
	return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other)
{
	return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other)
{
	return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other)
{
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other)
{
	return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed result;

	result._value = this->_value + other._value;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed result;

	result._value = this->_value - other._value;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed result;

	result._value = (this->_value * other._value) >> _bits;
	return (result);
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed result;

	result._value = (this->_value << _bits) / other._value;
	return (result);
}

Fixed &Fixed::operator++()
{
	this->_value += 1;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->_value -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_value += 1;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_value -= 1;
	return (temp);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}