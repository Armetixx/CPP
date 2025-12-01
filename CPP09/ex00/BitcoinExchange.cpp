/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:46:59 by kederhet          #+#    #+#             */
/*   Updated: 2025/12/01 01:46:59 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

static std::string trim(const std::string &str)
{
	size_t start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	size_t end = str.find_last_not_of(" \t\r\n");
	return str.substr(start, end - start + 1);
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		_database = src._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	for (size_t i = 0; i < yearStr.length(); i++)
		if (!isdigit(yearStr[i])) return false;
	for (size_t i = 0; i < monthStr.length(); i++)
		if (!isdigit(monthStr[i])) return false;
	for (size_t i = 0; i < dayStr.length(); i++)
		if (!isdigit(dayStr[i])) return false;

	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());

	if (year < 2009 || year > 2050)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

bool BitcoinExchange::isValidValue(const std::string &value, float &result)
{
	if (value.empty())
		return false;

	bool hasDecimal = false;
	size_t start = 0;
	
	if (value[0] == '-' || value[0] == '+')
		start = 1;

	if (start >= value.length())
		return false;

	for (size_t i = start; i < value.length(); i++)
	{
		if (value[i] == '.')
		{
			if (hasDecimal)
				return false;
			hasDecimal = true;
		}
		else if (!isdigit(value[i]))
			return false;
	}

	result = std::atof(value.c_str());

	if (result < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (result > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return false;
	}

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		line = trim(line);
		if (line.empty())
			continue;
		if (firstLine)
		{
			firstLine = false;
			continue;
		}

		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;

		std::string date = trim(line.substr(0, commaPos));
		std::string priceStr = trim(line.substr(commaPos + 1));
		if (date.empty() || priceStr.empty())
			continue;

		float price = std::atof(priceStr.c_str());
		_database[date] = price;
	}

	file.close();
	return !_database.empty();
}

float BitcoinExchange::getExchangeRate(const std::string &date)
{
	std::map<std::string, float>::iterator it = _database.upper_bound(date);
	
	if (it == _database.begin())
	{
		return -1;
	}
	
	--it;
	return it->second;
}

void BitcoinExchange::processInputFile(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		line = trim(line);
		if (line.empty())
			continue;
		if (firstLine)
		{
			firstLine = false;
			continue;
		}

		size_t sepPos = line.find(" | ");
		if (sepPos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, sepPos));
		std::string valueStr = trim(line.substr(sepPos + 3));

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		float value;
		if (!isValidValue(valueStr, value))
			continue;

		float rate = getExchangeRate(date);
		if (rate < 0)
		{
			std::cerr << "Error: date too early => " << date << std::endl;
			continue;
		}

		float result = value * rate;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}

	file.close();
}
