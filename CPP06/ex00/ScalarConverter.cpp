/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 02:16:44 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/06 02:16:44 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string &literal)
{
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

static bool isInt(const std::string &literal)
{
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (i >= literal.length())
        return false;
    for (; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

static bool isFloat(const std::string &literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
    
    if (literal[literal.length() - 1] != 'f')
        return false;
    
    bool hasPoint = false;
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    
    for (; i < literal.length() - 1; i++)
    {
        if (literal[i] == '.')
        {
            if (hasPoint)
                return false;
            hasPoint = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    return hasPoint;
}

static bool isDouble(const std::string &literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    
    bool hasPoint = false;
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    
    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (hasPoint)
                return false;
            hasPoint = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    return hasPoint;
}

static void printChar(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else if (value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value)
{
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value);
        std::cout << "f" << std::endl;
    }
}

static void printDouble(double value)
{
    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "+inf" << std::endl;
        else
            std::cout << "-inf" << std::endl;
    }
    else
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    double value = 0.0;
    
    if (isChar(literal))
    {
        value = static_cast<double>(literal[1]);
    }
    else if (isInt(literal))
    {
        long tmp = std::strtol(literal.c_str(), NULL, 10);
        if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        value = static_cast<double>(tmp);
    }
    else if (isFloat(literal))
    {
        if (literal == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inff")
            value = -std::numeric_limits<double>::infinity();
        else
            value = static_cast<double>(std::strtof(literal.c_str(), NULL));
    }
    else if (isDouble(literal))
    {
        if (literal == "nan")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            value = -std::numeric_limits<double>::infinity();
        else
            value = std::strtod(literal.c_str(), NULL);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
